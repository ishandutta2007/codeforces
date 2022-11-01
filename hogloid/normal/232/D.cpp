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
static const int INF =1000000015; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;

struct RMQ{
	int val[800005];
	int n;
	void init(int n_,int *a){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=INF;
		REP(i,n_) val[i+n-1]=a[i];
		for(int i=n-2;i>=0;--i) val[i]=min(val[i*2+1],val[i*2+2]);
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return INF;
		int md=(l+r)>>1;
		return min(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};
RMQ rmq;
struct segtree{
	vector<int> val[800005];
	int n;
	void init(int n_,int *a){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n_) val[i+n-1].pb(a[i]);
		for(int i=n-2;i>=0;--i){
			val[i].resize(val[i*2+1].size()+val[i*2+2].size());
			merge(ALL(val[i*2+1]),ALL(val[i*2+2]),val[i].begin());
		}
	}
	int query(int a,int b,int i,int l,int r,int v1,int v2){//[v1...v2)
		if(a<=l && r<=b) return lower_bound(ALL(val[i]),v2)-lower_bound(ALL(val[i]),v1);
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		return query(a,b,i*2+1,l,md,v1,v2)+query(a,b,i*2+2,md,r,v1,v2);
	}
};
segtree seg;


typedef int item ;
static const int MAX_N=200010;
int len,dif;
int rank[MAX_N],tmp[MAX_N],sa[MAX_N],rev[MAX_N],lcp[MAX_N];
bool cmp(const int& a,const int& b){
	if(rank[a]!=rank[b]) return rank[a]<rank[b];
	int a1=(a+dif<=len?rank[a+dif]:-INF),b1=(b+dif<=len?rank[b+dif]:-INF);
	return a1<b1;
}
void buildSA(item *s,int slen){//slen:=the exact size of elements
	len=slen;
	REP(i,len+1){
		rank[i]=s[i];
		sa[i]=i;
	}
	for(dif=1;dif<=len;dif*=2){
		sort(sa,sa+len+1,cmp);
		tmp[sa[0]]=0;
		REP(i,len) tmp[sa[i+1]]=tmp[sa[i]]+cmp(sa[i],sa[i+1]);
		REP(i,len+1) rank[i]=tmp[i];
	}


	int h=0;
	REP(i,len+1) rev[sa[i]]=i;
	REP(i,len+1){
		if(rev[i]==len) lcp[rev[i]]=0;
		else{
			for(int j=sa[rev[i]+1];j+h<=len && i+h<=len && s[i+h]==s[j+h];++h);
			lcp[rev[i]]=h;
		}
		if(h>0) --h;
	}
}//lcp[i] :=longest common prefix between suffix[i] and suffix[i+1]

int n,q;
int h[100005];
int dife[200005];
int main(){
	cin>>n;
	REP(i,n) scanf("%d",&h[i]);
	REP(i,n-1) dife[i]=(h[i+1]-h[i]);
	
	dife[n-1]=INF;

	REP(i,n-1) dife[i+n]=-(h[i+1]-h[i]);
	dife[n*2-1]=INF;
	buildSA(dife,n*2-1);
	rmq.init(n*2,lcp);
	seg.init(n*2,sa);
	cin>>q;
	REP(hoge,q){
		int l,r;scanf("%d%d",&l,&r);--l;
		if(r-l==1){
			printf("%d\n",n-1);
			continue;
		}
		int p=rev[l];
		int lb=-1,ub=p,m=r-l-1;
		while(ub-lb>1){
			int md=(ub+lb)>>1;
			if(rmq.query(md,p,0,0,rmq.n)<m) lb=md;
			else ub=md;
		}
		int begin=ub;
		lb=p;ub=n*2;
		while(ub-lb>1){
			int md=(lb+ub)>>1;
			if(rmq.query(p,md,0,0,rmq.n)<m) ub=md;
			else lb=md;
		}
		int end=lb;//[begin,end]
		++end;
		int res=seg.query(begin,end,0,0,seg.n,n,max(n,n+l-m))
				+seg.query(begin,end,0,0,seg.n,min(n*2-m,r+n),n*2-m);
		printf("%d\n",res);
	}
	return 0;
}