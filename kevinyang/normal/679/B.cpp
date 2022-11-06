#include <bits/stdc++.h>
using namespace std;
#define int long long
set<int>s;
map<int,pair<int,int>>hm;
pair<int,int> f(int x){
	if(x<=1)return {x,x};
	if(hm.find(x)!=hm.end())return  hm[x];
	int v = *--s.upper_bound(x);
	pair<int,int>r1 = f(x-v); r1.first++; r1.second+=v;
	pair<int,int>r2 = f(v-1);
	return hm[x] = max(r1,r2);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int i = 1; i<=100000; i++){
		s.insert(i*i*i);
	}
	int m;
	cin >> m;
	pair<int,int>ans = f(m);
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}