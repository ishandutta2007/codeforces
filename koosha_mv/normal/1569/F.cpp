#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll
 
const int N=14;
 
int n,m,k,ans,mark[N],P[N],pos[N];
int g[N][N];
vector<int> v;
map<vector<int> ,bool> Ans;
vector<vector<int> > e;
 
void add(int x){
	v[x]++;
	if(v[x]==n/2 && x!=0){
		v[x]=0;
		add(x-1);
	}
}
bool check(){
	fill(pos,pos+N,n);
	f_(i,v.size()-1,0)
		pos[v[i]]=i;
	f(i,0,n)
		if(pos[i]>pos[i+1])
			return 0;
	return 1;
}
void pre(){
	while(v[0]<1){
		if(check()){
			//cout<<"V : ";
			//f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl;
			e.pb(v);
		}
		add(n/2-1);
	}
	f(i,0,v.size()) v[i]=0;
}
void Add(int x){
	v[x]++;
	if(v[x]==n-1-x*2)
		v[x]=0,Add(x-1);	
}
void solve(vector<int> v){
	fill(mark,mark+N,0);
	vector<pair<int,int> > p;
	f(i,0,v.size()){
		int x=0,t=0;
		while(mark[x])
			x++;
		f(j,0,n){
			if(t>v[i] && !mark[j]){
				mark[x]=mark[j]=1;
				p.pb(mp(x,j));
				break;
			}
			if(!mark[j]) t++;
		}
	}
	int res=0;
	f(i,0,n/2) P[i]=i;
	do{
		int mv=1;
		if(g[p[P[0]].F][p[P[0]].S]==0) mv=0;
		f(i,0,p.size()-1){
			int u=P[i],v=P[i+1];
			if((g[p[u].F][p[v].F]==0 || g[p[u].S][p[v].S]==0) && (g[p[u].F][p[v].S]==0 || g[p[u].S][p[v].F]==0)) mv=0;
		} 
		if(mv==1) res=1;
	}while ( std::next_permutation(P,P+n/2) );
	if(res==0) return ;
//	f(i,0,v.size())
//		cout<<v[i]<<" "; cout<<endl;
//	f(i,0,p.size())
//		erorp(p[i]);
	vector<int> V(n);
	f(i,0,e.size()){
		f(j,0,p.size())
			V[p[j].F]=V[p[j].S]=e[i][j];
		int c=0;
		f(i,0,n){
			if(V[i]>=c){	
				f_(j,n-1,0)
					if(V[j]==V[i])
						V[j]=c;
				c++;			
			}
		}
		if(Ans[V]!=1){
			int res=1;
			Ans[V]=1;
			f_(q,k,k-c+1)
				res=res*q;
		//	cout<<"MV : ";
		//	f(i,0,V.size()) cout<<V[i]<<" "; cout<<endl; 
			ans+=res;
		}	
	}
}
 
main(){
	cin>>n>>m>>k;
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[u][v]=1,g[v][u]=1;
	}
	f(i,0,n/2) v.pb(0);
	pre();
	while(1){
		solve(v);
		int mv=1;
		f(i,0,v.size())
			if(v[i]<n-2-i*2)
				mv=0;
		if(mv) break;
		Add(n/2-1);
	}
	cout<<ans;
}