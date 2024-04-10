#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<list>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<cstdlib>
#include<cmath>
#define REP(num,num2) for(int num=0;num<(int)(num2);++num)
#define REPN(num,num2,init) for(int num=init;num<(int)(num2);++num)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define ITR(tp) __typeof((tp).begin())
#define SZ(t) ((int)t.size())
#define ALL(typ) (typ).begin(),(typ).end()
#define pb push_back
#define mp make_pair
#define EPS (1e-8)
#define fr first
#define sc second
#define SPR(x) ((x)*(x))
#define INF ((int)1e7)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef long long int lint;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int,int> > vp;
typedef pair<int,int> pi;
typedef vector<string> vs;
const double PI  = acos(-1.0);
template<class T> void debug(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template<class T> inline void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> inline void chmax(T& a,const T& b) { if(a<b) a=b; }
int v44[2500000],v47[2500000],v74[2500000],v77[2500000];
int flip[2500000];
char seq[1000010];
struct segtree{
	int n;
	void renew(int i){
		v44[i]=v44[i*2+1]+v44[i*2+2];
		v77[i]=v77[i*2+1]+v77[i*2+2];
		v47[i]=max(v47[i*2+1]+v77[i*2+2],v44[i*2+1]+v47[i*2+2]);
		v74[i]=max(v74[i*2+1]+v44[i*2+2],v77[i*2+1]+v74[i*2+2]);
	}
	void swp(int i){
		swap(v44[i],v77[i]);
		swap(v47[i],v74[i]);
	}
	segtree(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n_){
			if(seq[i]=='4') v44[i+n-1]=1;
			else v77[i+n-1]=1;
			v47[i+n-1]=v74[i+n-1]=1;
		}
		REPN(i,n,n_) v44[i+n-1]=v47[i+n-1]=v74[i+n-1]=v77[i+n-1]=0;
		for(int i=n-2;i>=0;--i){
			renew(i);
		}
	}
	void change(int a,int b,int node,int l,int r){
		if(a<=l && r<=b){
			swp(node);
			flip[node]^=1;
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		if(flip[node]){
			swp(node*2+1);
			swp(node*2+2);
			flip[node]=0;
			flip[node*2+1]^=1;
			flip[node*2+2]^=1;
		}
		change(a,b,node*2+1,l,md);
		change(a,b,node*2+2,md,r);
		renew(node);
	}
};
int n,m;
char tmp[20];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",seq);
	int sum7=0;
	REP(i,n) if(seq[i]=='7'){
		++sum7;
	}
	segtree seg(n);
	REP(i,m){
		scanf("%s",tmp);
		if(tmp[0]=='c'){
			printf("%d\n",v47[0]);
		}else{
			int a,b;scanf("%d%d",&a,&b);--a;
			seg.change(a,b,0,0,seg.n);
		}
	}


	return 0;
}