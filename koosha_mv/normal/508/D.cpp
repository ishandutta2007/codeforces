#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
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

const int N=1e6+99,base=256;

int n,t,cnt,a[N],deg[N];
vector<int> v,g[N];

void dfs(int x){
   while(g[x].size()){
      int u=g[x].back();
      g[x].pop_back();
      dfs(u);
   }
   v.pb(x);
}
int main(){
	cin>>n;	
	f(i,0,n){
		string s;
		cin>>s;
		int u=s[0]*base+s[1],v=s[1]*base+s[2];
		deg[u]++,deg[v]--;
		g[u].pb(v);
	}
	f(i,0,N){
		if(abs(deg[i])>1){
			return cout<<"NO",0;
		}
		if(deg[i]==1){
			cnt++;
			if(cnt>1){
				return cout<<"NO",0;
			}
		}
	}
	f(i,0,N){
		if(deg[i]==1 || (g[i].size()>0 && cnt==0)){
			dfs(i);
			if(v.size()<n+1) return cout<<"NO",0;
			cout<<"YES"<<endl;
			reverse(v.begin(),v.end());
			cout<<char(v[0]/base);
			f(i,0,v.size()){
				cout<<char(v[i]%base);
			}
			return 0;
		}
	}
}