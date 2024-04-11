#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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

const int N=1e6+99,mod=998244353;

int n,m,q,k,t,a[N],b[N],mark[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

void Main(){
	map<int,int> col,row;
	cin>>n>>m>>k>>q;
	f(i,1,q+1){
		int x,y;
		cin>>x>>y;
		a[i]=x,b[i]=y;
	}
	int res=1;
	f_(i,q,1){
		if(!((row[a[i]] || col.size()==m) && (col[b[i]] || row.size()==n))){
			res=1ll*res*k%mod;
		}
		row[a[i]]=1;
		col[b[i]]=1;
	}
	cout<<res<<'\n';
}

main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>t;
	while(t--){
		Main();
	}
}