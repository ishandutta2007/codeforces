#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

struct elem{ int x, y, idx; }a[300005];

int n, w, res[300005], rev[300005];

lint trial(int x){
	memset(res, 0, sizeof(res));
	priority_queue<pi, vector<pi>, greater<pi> > pq1, pq2, pq3;
	lint ret = 0;
	for(int i=0; i<w-2*x; i++){
		ret += a[i].x;
		res[i] = 1;
		pq2.push(pi(a[i].y - a[i].x, i));
	}
	for(int i=w-2*x; i<n; i++){
		pq1.push(pi(a[i].x, i));
		pq3.push(pi(a[i].y, i));
	}
	for(int i=0; i<x; i++){
		while(!pq3.empty() && res[pq3.top().second] != 0){
			pq3.pop();
		}
		while(!pq2.empty() && res[pq2.top().second] != 1){
			pq2.pop();
		}
		while(!pq1.empty() && res[pq1.top().second] != 0){
			pq1.pop();
		}
		if(pq3.empty()){
			res[pq1.top().second] = 1;
			res[pq2.top().second] = 2;
			ret += pq1.top().first + pq2.top().first;
			auto ins = pi(a[pq1.top().second].y - a[pq1.top().second].x, pq1.top().second);
			pq1.pop();
			pq2.pop();
			pq2.push(ins);
		}
		else if(pq1.empty() || pq2.empty()){
			res[pq3.top().second] = 2;
			ret += pq3.top().first;
			pq3.pop();
		}
		else{
			lint ch1 = pq1.top().first + pq2.top().first;
			lint ch2 = pq3.top().first;
			if(ch1 < ch2){
				res[pq1.top().second] = 1;
				res[pq2.top().second] = 2;
				ret += pq1.top().first + pq2.top().first;
				auto ins = pi(a[pq1.top().second].y - a[pq1.top().second].x, pq1.top().second);
				pq1.pop();
				pq2.pop();
				pq2.push(ins);
			}
			else{
				res[pq3.top().second] = 2;
				ret += pq3.top().first;
				pq3.pop();
			}
		}
	}
	return ret;
}

int main(){
	cin >> n >> w;
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].x, &a[i].y);
		a[i].idx = i;
	}
	sort(a, a+n, [&](const elem &a, const elem &b){
		return a.x < b.x;
	});
	int s = max(0, w-n), e = w/2;
	while(s != e){
		int m = (s+e)/2;
		if(trial(m) < trial(m+1)) e = m;
		else s = m+1;
	}
	cout << trial(s) << endl;
	for(int i=0; i<n; i++) rev[a[i].idx] = i;
	for(int i=0; i<n; i++){
		printf("%d", res[rev[i]]);
	}
}