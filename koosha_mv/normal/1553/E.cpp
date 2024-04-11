#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+99;
 
int n,t,m,a[N],p[N],mark[N],vis[N];
 
int solve(int x){
	fill(vis,vis+n,0);
	int res=0;
	f(i,0,n)
		p[i]=(a[i]+x)%n;
	f(i,0,n){
		if(!vis[i]){
			res++;
			vis[i]=1;
			for(int u=p[i];u!=i;u=p[u])
				vis[u]=1;
		}
	}
	return res;
}
 
int main(){
	cin>>t;
	while(t--){
		vector<int> ans;
		fill(mark,mark+n,0);
		cin>>n>>m;
		f(i,0,n){
			cin>>a[i];
			a[i]--;
			mark[(i+n-a[i])%n]++;
		}
		f(i,0,n){
			if(mark[i]+m*2>=n){
				if(n-solve(i)<=m)
					ans.pb(i);
			}
		}
		cout<<ans.size()<<" ";
		f(i,0,ans.size()) cout<<ans[i]<<" "; cout<<endl;
	}
}