#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99,mod=1e9+7;

int n,t,sq,ans=1,a[N],s[N],d[N],cnt[N],fac[N],deg[N],Ft[N],Tf[N];

int G(int x){
	if(x==1 || (s[x]==x && x*2>n)) return 1;
	return 0;
}
void Add_edge(int u,int v){
	if((Ft[u] && Ft[u]!=v) || (Tf[v] && Tf[v]!=u)){
		cout<<0;
		exit(0);
	}
	Ft[u]=v;
	Tf[v]=u;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	d[1]=s[1]=1;
	fac[0]=1;
	f(i,1,N){
		fac[i]=1ll*fac[i-1]*i%mod;
	}
	f(i,2,N){
		if(!s[i]){
			for(int j=i;j<N;j+=i){
				s[j]=i;
			}
		}
	}
	f(i,2,N){
		d[i]=d[i/s[i]];
		if(d[i]%s[i]!=0){
			d[i]*=s[i];
		}
	}
	cin>>n;
	f(i,1,n+1){
		cnt[d[i]]++;
	}
	f(i,1,n+1){
		int x;
		cin>>x;
		cnt[d[x]]--;
		if(x){
			if(G(i)!=G(x)) return cout<<0,0;
			if(G(i)){
				Add_edge(i,x);
			}
			else{
				int u=d[i],v=d[x];
				if(u/s[u]!=v/s[v] || n/s[u]!=n/s[v]) return cout<<0,0;
				Add_edge(s[u],s[v]);
			}
		}
	}
	f(i,1,n+1){
		ans=1ll*ans*fac[cnt[i]]%mod;
	}
	f(i,2,n+1){
		int cnt=0,p;
		for(p=i;n/i==n/p;p++){
			cnt+=(p==s[p] && !Ft[p]);
		}
		if(p==n+1) cnt+=!Ft[1];
		ans=1ll*ans*fac[cnt]%mod;
		i=p-1;
	}
	cout<<ans<<endl;
}