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

struct segtree{
	int val[8000005];
	int n;
	void init(int n_,int m){//n_=n+m
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=0;
		REPN(i,n_,m) val[i+n-1]=1;

		for(int i=n-2;i>=0;--i) val[i]=val[i*2+1]+val[i*2+2];
	}
	void set(int k,int a){
		k+=n-1;
		val[k]=a;
		while(k>0){
			k=(k-1)/2;
			val[k]=val[k*2+1]+val[k*2+2];
		}
	}
	int query(int i,int l,int r,int k){
		if(val[i]<k) return INF;
		if(r-l==1) return l;

		int md=(l+r)>>1;
		int L=query(i*2+1,l,md,k);
		if(L==INF) return query(i*2+2,md,r,k-val[i*2+1]);
		else return L;
	}
};
segtree seg;

int n,m;
pi event[1000005];

int ar[2000005];//[position],position

int res[1000005];//[pos],mark

int used[1000005];//[mark]
int main(){
	cin>>n>>m;
	REP(i,m){
		scanf("%d%d",&event[i].fr,&event[i].sc);
		--event[i].fr;--event[i].sc;
	}
	memset(res,-1,sizeof(res));
	memset(ar,-1,sizeof(ar));
	REP(i,n) ar[i+m]=i;
	seg.init(n+m,m);
	

	REP(i,m){
		int x=event[i].fr,y=event[i].sc;

		int pos=seg.query(0,0,seg.n,y+1);
		int init_pos=ar[pos];
		if(res[init_pos]!=-1 && res[init_pos]!=x){
			puts("-1");
			return 0;
		}
		if(res[init_pos]==-1 && used[x]){
			puts("-1");
			return 0;
		}

		used[x]=1;
		res[init_pos]=x;
		
		ar[pos]=INF;
		seg.set(pos,0);
		seg.set(m-i-1,1);
		ar[m-i-1]=init_pos;
	}
	
	
	int j=0;
	REP(i,n)  if(res[i]==-1){
		while(used[j]) ++j;
		res[i]=j;
		++j;
	}

	REP(i,n) printf("%d%c",res[i]+1,i==n-1?'\n':' ');

	return 0;
}