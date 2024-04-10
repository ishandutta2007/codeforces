#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 35003;
int N , arr[_] , l[_] , r[_];

int work(int x){
	priority_queue < int > L; priority_queue < int , vector < int > , greater < int > > R;
	int val = abs(x) , movel = 0 , mover = 0;
	for(int i = 1 ; i <= N + 3 ; ++i){L.push(x); R.push(x);}//describe f_{1,others}=inf
	for(int i = 2 ; i <= N ; ++i){
		movel -= arr[i] - r[i]; mover -= arr[i] - r[i]; //operation 1
		movel -= r[i] - l[i];//operation 2
		//operation 3
		if(L.top() + movel >= 0){//lying in segments with negative slopes
			int t = L.top(); L.pop(); val += movel + t; R.push(t + movel - mover);
			L.push(-movel); L.push(-movel);
		}
		else if(R.top() + mover <= 0){//lying in segments with positive slopes
			int t = R.top(); R.pop(); L.push(t + mover - movel); val += -t - mover;
			R.push(-mover); R.push(-mover);
		}
		else{L.push(-movel); R.push(-mover);}//lying in the segment with slope 0
		assert(L.top() + movel <= R.top() + mover);
	}
	//calculate the answer
	int rgel = arr[1] + x - r[1] , rger = arr[1] + x - l[1];
	if(!(L.top() + movel > rger || R.top() + mover < rgel)) return val;
	else if(L.top() + movel > rger){
		int k = 1 , pre = L.top(); L.pop();
		while(!L.empty()){
			int t = L.top();
			if(t + movel <= rger) return ((pre + movel) - rger) * k + val;
			L.pop(); val += (pre - t) * (k++); pre = t;
		}
	}
	else{
		int k = 1 , pre = R.top(); R.pop();
		while(!R.empty()){
			int t = R.top();
			if(t + mover >= rgel) return (rgel - (pre + mover)) * k + val;
			R.pop(); val += (t - pre) * (k++); pre = t;
		}
	}
	assert(0); return -1;
}

signed main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> arr[i] >> l[i] >> r[i];
	int L = -35000*35000 , R = 35000*35000;
	while(L < R){int mid = (L + R) >> 1; work(mid) < work(mid + 1) ? R = mid : L = mid + 1;}
	cout << work(L) << endl; return 0;
}