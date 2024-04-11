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

const int N=1e6+99;

int n,cnt,a[N],vis[N];
pair<int,int> s[N],t[N];
map<int,pair<int,int> > mark;
vector<int> g[N];
map<pair<int,int>,int> ans;

void dfs(int u){
	while(g[u].size() && vis[g[u].back()]){
		g[u].pop_back();
	}	
	if(g[u].size()==0) return ;
	pair<int,int> x=s[g[u].back()],y=t[g[u].back()];
	vis[g[u].back()]=1;
	g[u].pop_back();
	if(x.F!=u) swap(x,y);
	ans[{x.F,x.S}]=1;
	dfs(y.F);	
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	f(i,0,n){
		int k;
		cin>>k;
		a[i]=k;
		f(j,0,k){
			int x;
			cin>>x;
			if(mark.count(x)==1){
				g[i].pb(cnt);
				g[mark[x].F].pb(cnt);
				s[cnt]=mp(i,j);
				t[cnt]=mark[x];
				mark.erase(x);
				//erorp(s[cnt]);
				//erorp(t[cnt]);
				cnt++;
			}
			else{
				mark[x]=mp(i,j);
			}
		}
	}
	if(mark.size()){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	f(i,0,n){
		dfs(i);
	}
	f(i,0,n){
		f(j,0,a[i]){
			if(ans.count({i,j})){
				cout<<'L';
			}
			else{
				cout<<'R';
			}
		}
		cout<<endl;
	}
}