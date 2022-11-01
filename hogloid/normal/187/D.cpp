#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int n,g,r;
lint zip[200005];
lint loop;
int len[100005];
lint sum[100005];
pair<lint,lint> seg[100005];
struct segtree{
	int val[1000000];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=INF;
	}
	void set(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b){
			val[i]=min(val[i],v);return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		set(a,b,i*2+1,l,md,v);
		set(a,b,i*2+2,md,r,v);
	}
	int query(int k){
		k+=n-1;
		int res=val[k];
		while(k){
			k=(k-1)/2;
			res=min(res,val[k]);
		}
		return res;
	}
};
segtree segm;
lint cost[100005];//from the time of beginning of green
int main(){
	scanf("%d%d%d",&n,&g,&r);
	loop=g+r;
	REP(i,n+1) scanf("%d",&len[i]);
	sum[0]=len[0];
	REP(i,n) sum[i+1]=sum[i]+len[i+1];

	REP(i,n){
		seg[i]=mp(((g-sum[i])%loop+loop)%loop,((-sum[i])%loop+loop)%loop);
		zip[i*2]=seg[i].fr;
		zip[i*2+1]=seg[i].sc;
	}
	sort(zip,zip+n*2);
	int zn=unique(zip,zip+n*2)-zip;
	segm.init(zn);

	cost[n]=len[n];
	for(int i=n-1;i>=0;--i){
		lint begintime=((-sum[i])%loop+loop)%loop;
		int piv=upper_bound(zip,zip+zn,begintime)-zip;
		--piv;
		if(piv<0) piv=zn-1;
		int caught=segm.query(piv);
		if(caught==INF) cost[i]=sum[n]-sum[i];
		else cost[i]=cost[caught]+(sum[caught]-sum[i])/loop*loop+loop;

		seg[i].fr=lower_bound(zip,zip+zn,seg[i].fr)-zip;
		seg[i].sc=lower_bound(zip,zip+zn,seg[i].sc)-zip;
		if(seg[i].sc>seg[i].fr) segm.set(seg[i].fr,seg[i].sc,0,0,segm.n,i);
		else{
			segm.set(seg[i].fr,segm.n,0,0,segm.n,i);
			segm.set(0,seg[i].sc,0,0,segm.n,i);
		}
	}
	int q;scanf("%d",&q);
	REP(hoge,q){
		int t;scanf("%d",&t);
		int prevt=t;
		t%=loop;
		lint res=0;
		int piv=upper_bound(zip,zip+zn,t)-zip;
		--piv;
		if(piv<0) piv=zn-1;
		int caught=segm.query(piv);
		if(caught==INF) res=sum[n]+prevt;
		else res=cost[caught]+(sum[caught]+t)/loop*loop+loop+prevt-t;

		cout<<res<<endl;
	}

	return 0;
}