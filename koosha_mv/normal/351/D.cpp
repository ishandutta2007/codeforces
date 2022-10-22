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

const int N=2e5+99;

int n,q,mv,a[N],L[N],R[N],prv[N],last[N],ans[N],fenwik[N];
vector<int> v[N];
vector<pair<int,int>> vec[N],ad[N];

void add(int x, int val){ for(x++;x<N;x+=x&-x) fenwik[x]+=val; }
int get(int x) { int res=0; for (x++;x>0;x-=x&-x) res+=fenwik[x]; return res; }

void pre(){
	f(i,1,n+1) prv[i]=last[a[i]],last[a[i]]=i;
	f(i,1,N) v[i].pb(0);
	f(i,1,N) v[a[i]].pb(i);
	f(x,1,N){
		v[x].pb(n+1);
		v[x].pb(n+1);
		int last=v[x].size()-2;
		f_(i,v[x].size()-3,1){
			if(v[x][i+1]-v[x][i]!=v[x][i+2]-v[x][i+1]){
				last=i+1;
			}
			ad[v[x][i-1]+1].pb({v[x][last+1]-1,+1});
			ad[v[x][i]+1].pb({v[x][last+1]-1,-1});
			ad[v[x][i-1]+1].pb({v[x][i]-1,-1});
			ad[v[x][i]+1].pb({v[x][i]-1,+1});
		}	
	}
}
void solve1(){
	f(i,1,n+1){
		add(prv[i],1);
		for(auto p : vec[i]){
			ans[p.S]+=get(p.F-1)-p.F+1;
		}
	}
	fill(fenwik,fenwik+N,0);
	f(i,0,N) vec[i].clear();
}
void solve2(){
	f(i,1,q+1) vec[L[i]].pb({R[i],i});
	f(i,1,n+1){
		for(auto p : ad[i]){
			add(p.F,p.S);
		}
		for(auto p : vec[i]){
			ans[p.S]+=(get(p.F-1)==get(N-1));
		}
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	pre();
	cin>>q;
	f(i,1,q+1){
		cin>>L[i]>>R[i];
		vec[R[i]].pb({L[i],i});
	}
	solve1();
	solve2();
	f(i,1,q+1){
		cout<<ans[i]<<" ";
	}
}