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
int n,m;
const lint B=1009;
lint powerB[200005];
int pos[200005];
struct segtree{
	struct State{
		lint code;
		int cnt;
		void make(lint in){
			code=in;
			if(code) cnt=1;
			else cnt=0;
		}
		void merge(const State& a,const State& b){
			code=a.code+b.code*powerB[a.cnt];
			cnt=a.cnt+b.cnt;
		}
	};
	State val[800005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i].make(0);
	}
	void set(int k,int a){
		k+=n-1;
		val[k].make(a);
		while(k>0){
			k=(k-1)/2;
			val[k].merge(val[k*2+1],val[k*2+2]);
		}
	}
	lint get(){
		return val[0].code;
	}
};
segtree seg;

int main(){
	powerB[0]=1;
	REP(i,200004) powerB[i+1]=powerB[i]*B;
	scanf("%d%d",&n,&m);
	seg.init(m);
	lint target=0;
	lint sum=0;
	REP(i,n){
		sum+=powerB[i];
		int a;scanf("%d",&a);
		target+=a*powerB[i];
	}
	REP(i,m){
		int a;scanf("%d",&a);
		pos[a]=i;
	}
	int res=0;
	REP(i,n-1) seg.set(pos[i+1],i+1);
	for(int i=n-1;i<m;++i){
		seg.set(pos[i+1],i+1);
		if(seg.get()==target) ++res;
		target+=sum;
		seg.set(pos[i-n+2],0);
	}
	printf("%d\n",res);


	return 0;
}