#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x, int y){
	int v = x/y;
	int v2 = x/y+1;
	int c = y-(x%y);
	int c2 = x%y;
	return c*v*v+c2*v2*v2;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	k-=n;
	priority_queue<pair<int,pair<int,int>>>pq;
	int ans = 0;
	for(int i = 1; i<=n; i++){
		int x;
		cin >> x;
		ans+=x*x;
		int v = f(x,1)-f(x,2);
		pq.push({v,{x,1}});
	}
	for(int i = 0; i<k; i++){
		auto p = pq.top(); pq.pop();
		ans-=p.first;
		pair<int,int>val = p.second;
		val.second++;
		pq.push({f(val.first,val.second)-f(val.first,val.second+1),val});
	}
	cout << ans << "\n";
	return 0;
}