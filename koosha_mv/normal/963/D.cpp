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

const int N=1e5+99,S=27;

int n,q,m=1,a[N],k[N],p[N],par[N],nxt[N][S],child[S];
string s,t[N];
vector<int> vec[N];

void addtrie(string s,int id){
	int now=1;
	f(i,0,s.size()){
		if(nxt[now][s[i]-'a']==0) nxt[now][s[i]-'a']=++m;
		now=nxt[now][s[i]-'a'];
	}
	a[now]=id;
}
void buildaho(){
	queue<int> q;
	q.push(1);
	par[1]=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		f(i,0,S) child[i]=nxt[u][i];
		if(u==1) f(i,0,S) nxt[u][i]=u;
		if(u!=1 && a[par[u]]) p[u]=par[u];
		else p[u]=p[par[u]];
		f(i,0,S){
			if(!child[i]){
				nxt[u][i]=nxt[par[u]][i];
				continue ;
			}
			q.push(child[i]);
			par[child[i]]=nxt[par[u]][i];
			nxt[u][i]=child[i];
			
		}
	}	
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>s; n=s.size();
	cin>>q;
	f(i,1,q+1){
		cin>>k[i]>>t[i];
		addtrie(t[i],i);
	}
	buildaho();
	int now=1;
	f(i,0,n){
		now=nxt[now][s[i]-'a'];
		for(int u=(a[now] ? now : p[now]);u>0;u=p[u]){
			vec[a[u]].pb(i);
		}
	}
	f(i,1,q+1){
		int ans=n+1,len=k[i]-1;
		f(j,len,vec[i].size()){
			minm(ans,vec[i][j]-vec[i][j-len]+sz(t[i]));
		}
		cout<<(ans==n+1 ? -1 : ans)<<'\n';
	}
}