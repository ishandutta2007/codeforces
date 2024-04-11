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

const int N=2e5+99,S=11,T=25,mod=998244353;
 
int n,m,Pow=1,a[N],dp[T][(1<<S)],pd[(1<<S)];
ll ans[N];
vector<int> base,vec1,vec2;
 
void dfs(int x,int mask,int t){
	if(x==base.size()){
		if(t==0){
			dp[nb(mask>>S)][mask&((1<<S)-1)]++;
		}
		else{
			pd[mask]++;
		}
		return ;
	}
	dfs(x+1,mask,t);
	dfs(x+1,mask^base[x],t);
}
void make(vector<int> vec,int t){
	base=vec;
	dfs(0,0,t);
}
void read(){
	cin>>n>>m;
	f(i,0,n){
		int x;
		cin>>x;
		f(j,0,base.size()){
			minm(x,x^base[j]);
		}
		if(x==0) Pow=2ll*Pow%mod;
		else{
			base.pb(x);
			sort(all(base),greater<int>());	
		}
	}
	f(i,0,base.size()){
		if(base[i]>=(1<<S)){
			vec1.pb(base[i]);
		}
		else{
			vec2.pb(base[i]);
		}
	}
	make(vec1,0);
	make(vec2,1);
}
void solve(){
	f(i,0,T){
		f(mask,0,(1<<S)){
			f(task,0,(1<<S)){
				ans[i+nb(mask^task)]+=1ll*dp[i][mask]*pd[task];
			}
		}
	}
}
void Print(){
	f(i,0,m+1){
		cout<<1ll*ans[i]*Pow%mod<<" ";
	}
}
main(){
	read();
	solve();
	Print();
}