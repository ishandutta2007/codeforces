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

const int N=505,d[4]={1,0,-1,0},b[4]={0,1,0,-1};

int n,m,a[N][N],mark[N][N];
string s[N];
vector<pair<int,int> > g[N][N];

void dfs(int u,int v,int x){
	a[u][v]=x;
	mark[u][v]=1;
	f(i,0,g[u][v].size()){
		pair<int,int> p=g[u][v][i];
		if(!mark[p.F][p.S])
			dfs(p.F,p.S,5-x);	
	}
}

int main(){
	cin>>n>>m;
	f(i,0,n)
		cin>>s[i];
	f(i,0,n){
		f(j,0,m){
			if(s[i][j]=='X'){
				vector<pair<int,int> > v;
				f(k,0,4)
					if(s[i+d[k]][j+b[k]]=='.')
						v.pb(mp(i+d[k],j+b[k]));
				if(int(v.size())%2==1)
					return cout<<"NO",0;
				for(int k=0;k<v.size();k+=2){
					g[v[k].F][v[k].S].pb(v[k+1]);
					g[v[k+1].F][v[k+1].S].pb(v[k]);
				}
				a[i][j]=v.size()/2*5;
			}
		}
	}
	f(i,0,n)
		f(j,0,m)
			if(!mark[i][j] && s[i][j]=='.')
				dfs(i,j,1);
	cout<<"YES"<<endl;
	f(i,0,n){
		f(j,0,m)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}