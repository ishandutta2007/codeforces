#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2e5+9;
ll n,m,q[N][2],mark[N],t,deg[N],k,ans[N],e=1e6;
vector<ll> g[N];
map <ll,ll> mp;
void del(ll x){
	deg[x]--;
	if(deg[x]<k){
		mark[x]=0;
		t--;
		f(i,0,g[x].size()){
			if(mark[g[x][i]]==1 && mp[x*e+g[x][i]]==1)
				del(g[x][i]);
		}
	}
}
int main(){
	cin>>n>>m>>k;t=n;
	f(i,1,N) mark[i]=1;
	f(i,0,m){
		cin>>q[i][0]>>q[i][1];
		mp[q[i][0]+q[i][1]*e]=1,mp[q[i][0]*e+q[i][1]]=1;
		deg[q[i][0]]++;deg[q[i][1]]++;
		g[q[i][0]].pb(q[i][1]),g[q[i][1]].pb(q[i][0]);
	}
	f(i,1,n+1){
		if(deg[i]<k && mark[i]==1){
			del(i);
		}
	}
	f_(i,m-1,0){
		ans[i]=t;
		if(mark[q[i][0]]==1 && mark[q[i][1]]==1){
			mp[q[i][0]+q[i][1]*e]=0,mp[q[i][0]*e+q[i][1]]=0;
			del(q[i][0]);
			if(mark[q[i][1]]==1)
				del(q[i][1]);
		}
	}
	f(i,0,m) cout<<ans[i]<<endl;
}