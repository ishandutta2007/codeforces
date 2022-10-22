#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=5e5+5;
ll n,a[N],m,t,ans,x,y,p;
vector<ll> g[N],g2[N];
map<vector<ll>,ll> eshterak[N];
int main(){
	cin>>t;
	f(q,0,t){
		ans=0;
		f(i,1,n+1) g[i].clear();
		Get(n,m);
		f(i,1,n+1) get(a[i]);
		f(i,0,m){
			Get(x,y);
			g[y].pb(x);
		}
		f(i,1,n+1){
			sort(g[i].begin(),g[i].end());
			eshterak[q][g[i]]+=a[i];
		}
		f(i,1,n+1){
			if(g[i].size()) ans=__gcd(ans,eshterak[q][g[i]]);
		}
		cout<<ans<<endl;
	}
}