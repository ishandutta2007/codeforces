#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int h,w,r,c;
int n;
int cnt=0;
int id[3005][6005];
struct uf{
	int par[18000005];
	void init(){
		REP(i,h*w*2) par[i]=-1;
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
uf u;

int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef vector<int> vi;

vi getadj(int a,int b,int& sum){
	vi res;
	if(b==0) sum|=1;
	if(b==c*2-1) sum|=2;
	REPN(i,2,-1) if(a+i>=0 && a+i<h) REPN(j,2,-1) if(
			id[a+i][(b+j+c*2)%(c*2)]!=-1){
		int tmp=u.root(id[a+i][(b+j+c*2)%(c*2)]);
		res.pb(tmp);
	}
	return res;
}
void mark(int a,int b,vi& ar){
	id[a][b]=cnt;
	REP(i,ar.size()) u.unite(cnt,ar[i]);
	++cnt;
}
bool can(int a,int b){
	int sum1=0,sum2=0;
	vi adj1=getadj(a,b,sum1),adj2=getadj(a,b+c,sum2);

	REP(i,adj1.size()) REP(j,adj2.size()) if(adj1[i]==adj2[j]) return false;
	mark(a,b,adj1);
	mark(a,b+c,adj2);
	return true;
}


int main(){
	scanf("%d%d%d",&h,&w,&n);
	r=h;c=w;
	memset(id,-1,sizeof(id));
	u.init();
	
	if(c==1){
		puts("0");
		return 0;
	}
	int ans=0;
	REP(hoge,n){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		
		if(can(a,b)){
			++ans;
		}
	}
	cout<<ans<<endl;




	return 0;
}