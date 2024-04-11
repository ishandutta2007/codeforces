#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99;

int n,t,x,a[N],vis[N],p[N],deg[N];

void Main(){
	int cnt=0,rt=0;
	cin>>n>>x;
	fill(vis,vis+n+10,0);
	f(i,1,n+1) deg[i]=0;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
	}
	f(i,1,n+1){
		int x;
		cin>>x;
		p[x]=i;
		cnt+=(x!=i);
	}
	if(cnt==0){
		cout<<"Alice"<<'\n';
		return ;
	}
	if(cnt==2){
		cnt=0;
		f(i,1,n+1) if(p[i]!=i && i!=x){
			cnt++;
		}
		if(cnt==2){
			cout<<"Alice"<<'\n';
			return ;
		}
	}
	f(i,1,n+1){
		if(deg[i]==n-1){
			rt=i;
		}
	}
	if(rt==0){
		cout<<"Alice"<<'\n';
		return ;
	}
	int b=n&1;
	f(i,1,n+1){
		if(!vis[i]){
			b^=1;
			for(int u=i;;u=p[u]){
				vis[u]=1;
				if(p[u]==i) break;
			}
		}
	}
	if((b==1)==(x!=rt)){
		cout<<"Bob"<<'\n';
		return ;
	}
	if(p[rt]!=rt && (x==rt || p[x]==rt)){
		cout<<"Bob"<<'\n';
		return ;
	}
	cout<<"Alice"<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}