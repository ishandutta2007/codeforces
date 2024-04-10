#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
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
int h,w;

int buf[2000][2000];
int core[2000][2000];
int sum[2000][2000];
struct uf{
	int par[4000000];
	void init(){
		memset(par,-1,sizeof(par));
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		par[a]=b;
	}
};
uf u,uc;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

int id[4000005];
int main(){
	cin>>h>>w;
	REP(i,h) REP(j,w){
		scanf("%d",&buf[i+5][j+5]);
	}
	h+=10;w+=10;
	REP(i,h) REP(j,w){
		sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+buf[i][j];
	}
	REP(i,h) REP(j,w) if(buf[i][j]){
		int tot=sum[i+3][j+3]-sum[i+3][j-3]-sum[i-3][j+3]+sum[i-3][j-3];
		core[i][j]=(tot==36);
	}
	u.init();
	uc.init();

	
	vector<int> res;
	
	REP(i,h) REP(j,w) if(buf[i][j]){
		REP(d,4){
			int px=j+dx[d],py=i+dy[d];
			if(px<0 || py<0 || px>=w || py>=h) continue;
			if(buf[py][px]) u.unite(i*w+j,py*w+px);
		}
	}
	REP(i,h) REP(j,w) if(core[i][j]&1){
		int sz=6;
		REPN(dx,sz,-sz) REPN(dy,sz,-sz){
			if(i+dy<h && i+dy>=0 && j+dx>=0 && j+dx<=w) core[i+dy][j+dx]|=2;
		}
	}
	REP(i,h) REP(j,w) if(!core[i][j] && buf[i][j]){
		REP(d,4){
			int px=j+dx[d],py=i+dy[d];
			if(px<0 || py<0 || px>=w || py>=h) continue;
			if(!core[py][px] && buf[py][px]) uc.unite(i*w+j,py*w+px);
		}
	}
	
	int cnt=0;
	REP(i,h) REP(j,w) if( buf[i][j] && u.root(i*w+j)==i*w+j){
		id[i*w+j]=cnt++;
	}
	res.resize(cnt);

	REP(i,h) REP(j,w) if(!core[i][j] && buf[i][j] && uc.root(i*w+j)==i*w+j){
		int belong=id[u.root(i*w+j)];
		res[belong]++;
	}

	sort(ALL(res));
	printf("%d\n",res.size());
	REP(i,res.size()) printf("%d\n",res[i]);


	return 0;
}