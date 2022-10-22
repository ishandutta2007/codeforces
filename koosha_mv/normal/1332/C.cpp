#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=3e5+9;
int n,t,k,ans,a[N],b[150],cnt;
string s;
vector<int> g[N];
void solve(){
	int an=0;
	f(i,0,k/2+1){
		an=0;
		f(j,0,150) b[j]=0;
		f(j,0,g[i].size()){
			b[g[i][j]]++;
			maxm(an,b[g[i][j]]);
		}
		ans+=(g[i].size()-an);
	}
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k>>s;
		ans=0;
		f(i,0,n){
			if(i%k<k/2)
				g[i%k].pb(s[i]);
			else{
				if(i%k==k/2 && k%2)
					g[k/2].pb(s[i]);
				else
					g[k-1-(i%k)].pb(s[i]);
			}
		}
		solve();
		cout<<ans<<endl;
		f(i,0,k/2+2) g[i].clear();
	}
}
// owerflow int long long