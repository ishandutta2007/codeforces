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
 
const int N=1e6+99,S=62;

int n,ans,a[N];
map<pair<ll,ll> ,int> g;

ll solve(ll x,ll mask){
	if(g.count(mp(x,mask)))
		return g[mp(x,mask)];
	bool mark[70];
	fill(mark,mark+S,0);
	f(i,0,S){
		if(x-i-1>=0 && !(mask&(1ll<<i)))
			mark[solve(x-i-1,mask^(1<<i))]=1;
	}
	f(i,0,S){
		if(!mark[i]){
			g[mp(x,mask)]=i;
			return i;
		}
	}
}

int main(){
   cin>>n;
   f(i,0,n){
      cin>>a[i];
      ans^=solve(a[i],0ll);
   }
   if(ans==0) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
}