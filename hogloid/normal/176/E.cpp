#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;

int n;
lint dep[100005];
struct cmp{
	const bool operator ()(const int& a,const int& b)const{
		if(dep[a]==dep[b]) return a<b;
		return dep[a]<dep[b];
	}
};
vector<pi> g[100005];
set<int,cmp> vs;
int par[20][100005],dep2[100005];
int begin[100005],end[100005],cnt;
void prep(int v,int p,lint d,int d2=0){
	dep[v]=d;
	dep2[v]=d2;
	par[0][v]=p;
	begin[v]=cnt++;
	REP(i,g[v].size()){
		pi& e=g[v][i];
		if(e.fr==p) continue;
		prep(e.fr,v,d+e.sc,d2+1);
	}
	end[v]=cnt;
}
struct BIT{
	int val[100005];
	int n;
	void init(int n_){
		n=n_;
		memset(val,0,sizeof(val));
	}
	void add(int k,int a){
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
	int query(int k){//...k)
		int res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return res;
	}
};
BIT bit;

lint ans;

int findA(int v,int k){//find lowest ancestor of v that satisfy (size of subtree >k )
	if(bit.query(end[v])-bit.query(begin[v])>k) return v;
	for(int i=19;i>=0;--i){
		int p=par[i][v];
		if(p!=-1 && bit.query(end[p])-bit.query(begin[p])<=k){
			v=p;
		}
	}
	return par[0][v];
}

int root;
int lca(int a,int b){
	if(dep2[a]>dep2[b]) swap(a,b);
	int dif=dep2[b]-dep2[a];
	REP(i,20) if(dif>>i&1){
		b=par[i][b];
	}
	if(a==b) return a;
	for(int i=19;i>=0;--i) if(par[i][a]!=par[i][b]){
		a=par[i][a];
		b=par[i][b];
	}
	return par[0][a];
}

int main(){
	scanf("%d",&n);
	REP(i,n-1){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
	}
	bit.init(n);
	prep(0,-1,0);

	REP(i,19) REP(j,n){
		if(par[i][j]==-1) par[i+1][j]=-1;
		else par[i+1][j]=par[i][par[i][j]];
	}


	int m;scanf("%d",&m);
	char tmp[10];
	REP(hoge,m){
		scanf("%s",tmp);
		if(tmp[0]=='+'){
			int x;scanf("%d",&x);--x;

			if(vs.empty()){
				root=x;
				vs.insert(x);
			}else if(!(begin[root]<=begin[x] && begin[x]<end[root])){
				int L=lca(root,x);
				ans+=dep[root]+dep[x]-2*dep[L];
				root=L;
				vs.insert(x);
			}else if(bit.query(end[x])-bit.query(begin[x])==0){
				int p=findA(x,0);
				ans+=dep[x]-dep[p];
				vs.insert(x);
			}else{
				vs.insert(x);
			}
			bit.add(begin[x],1);
		}else if(tmp[0]=='-'){
			int x;scanf("%d",&x);--x;
			if(vs.size()==1){
				vs.erase(x);
			}else if(root==x){
				vs.erase(x);
				int p2=*vs.begin();
				bit.add(begin[x],-1);
				int p=findA(p2,vs.size()-1);
				bit.add(begin[x],1);
				ans-=dep[p]-dep[root];
				root=p;
			}else if(bit.query(end[x])-bit.query(begin[x])==1){
				vs.erase(x);
				int p=findA(x,1);
				if(p==root){
					int p2=*vs.begin();
					bit.add(begin[x],-1);
					int p3=findA(p2,vs.size()-1);
					bit.add(begin[x],1);
					ans-=dep[p3]+dep[x]-dep[root]*2;
					root=p3;
				}else ans-=dep[x]-dep[p];
			}else{
				vs.erase(x);
			}
			bit.add(begin[x],-1);
		}else{
			cout<<ans<<endl;
		}
	}


	return 0;
}