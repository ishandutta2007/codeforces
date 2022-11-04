#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100,M=1000100;
int a[N];
ll pref[M];
int n,q;
set<ll>st;

void dfs(ll l,ll r){
	if(l>r)return;
	if(pref[r]==pref[l-1])return;
	st.insert(pref[r]-pref[l-1]);
	while(l<M&&pref[l-1]==pref[l])++l;
	while(r>1&&pref[r]==pref[r-1])--r;
	if(l==r)return;
	ll m=(l+r)/2;
	dfs(l,m);dfs(m+1,r);
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		st.clear();
		for(int i=0;i<M;++i)pref[i]=0;
		cin>>n>>q;
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<n;++i)pref[a[i]]+=a[i];
		for(int i=1;i<M;++i)pref[i]+=pref[i-1];
		dfs(1,M-1);
		while(q--){
			int qq;cin>>qq;
			if(st.count(qq))cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
}