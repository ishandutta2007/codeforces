#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
struct segtree{
	int val[400005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		memset(val,0,sizeof(val));
	}
	void add(int k,int a){
		k+=n-1;
		val[k]+=a;
		while(k>0){
			k=(k-1)/2;
			val[k]+=a;
		}
	}
	int sum(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		return sum(a,b,i*2+1,l,md)+sum(a,b,i*2+2,md,r);
	}
	void set(int k,int a){
		k+=n-1;
		val[k]=max(val[k],a);
		while(k>0){
			k=(k-1)/2;
			val[k]=max(val[k],a);
		}
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return -1;
		int md=(l+r)>>1;
		return max(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};
segtree seg;
int zip[100005];
pi plane[100005];
pair<pi,int> p[100005];
pair<pi,pi> q[100005];
int res[100005];
bool cmp(const pair<pi,int>& a,const pair<pi,int>& b){
	if(a.fr.sc!=b.fr.sc) return a.fr.sc<b.fr.sc;
	return a<b;
}
bool cmp2(const pair<pi,pi>& a,const pair<pi,pi>& b){
	if(a.sc.fr!=b.sc.fr) return a.sc.fr<b.sc.fr;
	return a<b;
}
int main(){
	int n,k;scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&p[i].fr.sc);
	REP(i,n) scanf("%d",&p[i].fr.fr),zip[i]=p[i].fr.fr;
	REP(i,n) plane[i]=p[i].fr;
	sort(zip,zip+n);
	int zn=unique(zip,zip+n)-zip;
	REP(i,n) p[i].fr.fr=lower_bound(zip,zip+zn,p[i].fr.fr)-zip;
	
	seg.init(zn);
	sort(p,p+n,cmp);
	REP(i,n){
		int j=i;
		while(j<n && p[i].fr.sc==p[j].fr.sc){
			seg.add(p[j].fr.fr,1);
			++j;
		}
		REPN(i2,j,i) p[i2].sc=
		seg.sum(lower_bound(zip,zip+zn,zip[p[i2].fr.fr]-k)-zip,
			upper_bound(zip,zip+zn,zip[p[i2].fr.fr]+k)-zip,	0,0,seg.n);
		i=j-1;
	}

	memset(seg.val,-1,sizeof(seg.val));

	int query;scanf("%d",&query);
	REP(i,query){
		scanf("%d%d",&q[i].fr.fr,&q[i].fr.sc);
		--q[i].fr.fr;--q[i].fr.sc;
		q[i].sc.fr=max(plane[q[i].fr.fr].sc,plane[q[i].fr.sc].sc);
		q[i].sc.sc=i;
	}
	sort(q,q+query,cmp2);
	int j=n-1;
	for(int i=query-1;i>=0;--i){
		while(j>=0 && p[j].fr.sc>=q[i].sc.fr){
			seg.set(p[j].fr.fr,p[j].sc);
			--j;
		}
		int n1=q[i].fr.fr,n2=q[i].fr.sc;
		int l1=plane[n1].fr-k,r1=plane[n1].fr+k,l2=plane[n2].fr-k,r2=plane[n2].fr+k;
		int l=max(l1,l2),r=min(r2,r1);
		res[q[i].sc.sc]=
		seg.query(lower_bound(zip,zip+zn,l)-zip,upper_bound(zip,zip+zn,r)-zip,0,0,seg.n);
	}
	REP(i,query) printf("%d\n",res[i]);



	return 0;
}