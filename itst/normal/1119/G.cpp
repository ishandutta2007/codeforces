#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

const int MAXN = 1e6 + 7;
int val[MAXN] , sum[MAXN] , peo[MAXN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	int N , M , all = 0; cin >> N >> M;
	vector < int > num;
	num.push_back(0);
	for(int i = 1 ; i <= M ; ++i){
		cin >> val[i];
		sum[i] = (sum[i - 1] + val[i]) % N;
		all += val[i];
		if(i != M)
			num.push_back(sum[i]);
	}
	cout << (all / N + (all % N ? 1 : 0)) << endl;
	num.push_back(N);
	sort(num.begin() , num.end());
	int pre = 0;
	for(int i = 1 ; i <= M ; ++i){
		peo[i] = num[i] - num[i - 1];
		cout << peo[i] << ' ';
	}
	cout << endl;
	int hit = 1 , pos = 1;
	while(hit <= M){
		cout << hit << ' ';
		val[hit] -= peo[pos];
		if(val[hit] <= 0) ++hit;
		if(pos == M){
			cout << endl;
			pos = 1;
		}
		else ++pos;
	}
	while(pos != 1){
		cout << M << ' ';
		if(pos == M){
			cout << endl;
			pos = 1;
		}
		else ++pos;
	}
	return 0;
}