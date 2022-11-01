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


typedef char item ;
static const int MAX_N=100005;
int len,dif;
const int INF2=1000000015;
int rank[MAX_N],tmp[MAX_N],sa[MAX_N],rev[MAX_N],lcp[MAX_N];
bool cmp(const int& a,const int& b){
	if(rank[a]!=rank[b]) return rank[a]<rank[b];
	int a1=(a+dif<=len?rank[a+dif]:-INF2),b1=(b+dif<=len?rank[b+dif]:-INF2);
	return a1<b1;
}

struct segtree{
	static const int MAX_N=400005;
	int val[MAX_N];
	int n;
	void init(int n_,int *a){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=INF;
		REP(i,n_) val[i+n-1]=a[i];
		for(int i=n-2;i>=0;--i) val[i]=min(val[i*2+1],val[i*2+2]);
	}
	void set(int k,int a){
		k+=n-1;
		val[k]=a;
		while(k>0){
			k=(k-1)/2;
			val[k]=min(val[k*2+1],val[k*2+2]);
		}
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return INF;
		int md=(l+r)>>1;
		return min(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};
segtree rmq;
int n;
void buildSA(item *s,int slen){	
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
	rmq.init(len+1,lcp);
}//lcp[i] :=longest common prefix between suffix[i] and suffix[i+1]

int getend(int i,int j){
	int lb=i,ub=n+1;
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		if(rmq.query(i,md,0,0,rmq.n)<j) ub=md;
		else lb=md;
	}
	return lb-i+1;
}

char s[100005];


int main(){
	scanf("%s",s);
	n=strlen(s);
	int k;scanf("%d",&k);
	--k;
	
	buildSA(s,n);

	REP(i,n+1){
		int len=n-sa[i];
		int back;
		if(i==0) back=1;
		else back=lcp[i-1]+1;
		for(int j=back;j<=len;++j){
			int v=getend(i,j);
			if(v>k){
				REP(j2,j) putchar((s+sa[i]+j2)[0]);
				putchar('\n');
				return 0;
			}
			k-=v;
		}
	}
	puts("No such line.");

	return 0;
}