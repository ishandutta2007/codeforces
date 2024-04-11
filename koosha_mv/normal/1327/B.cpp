#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=3e5+99;
vector<int> g[N];
int n,t,x,k,mark[N],mark2[N];
void solve(){
	f(i,1,n+1){
		sort(g[i].begin(),g[i].end());
		f(j,0,g[i].size()){
			if(mark[g[i][j]]==0){
				mark[g[i][j]]=1,mark2[i]=1;break;}
		}
	}
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		f(i,0,n+2) g[i].clear(),mark[i]=mark2[i]=0;
		f(i,1,n+1){
			cin>>k;
			f(j,0,k){
				gett(x);
				g[i].pb(x);
			}
		}
		solve();
		int p1=0,p2=0;
		f(i,1,n+1){
			if(mark2[i]==0) p1=i;
			if(mark[i]==0) p2=i;
		}
		if(p1==0) cout<<"OPTIMAL"<<endl;
		else cout<< "IMPROVE"<<endl<<p1<<" "<<p2<<endl;
	}
}