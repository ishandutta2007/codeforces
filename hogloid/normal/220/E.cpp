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
struct segtree{
	int n;
	int val[400005];
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=0;
	}
	void add(int k,int a){
		k+=n-1;
		val[k]+=a;
		while(k>0){
			k=(k-1)/2;
			val[k]+=a;
		}
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		return query(a,b,i*2+1,l,md)+query(a,b,i*2+2,md,r);
	}
};
segtree seg,lef,rig;
int n;
lint k;
int a[100005],zip[100005];
lint sum_lef[100005],//...i]
	sum_rig[100005];//[i...
int zn;
int main(){
	cin>>n>>k;
	REP(i,n) scanf("%d",&a[i]),zip[i]=a[i];
	sort(zip,zip+n);
	zn=unique(zip,zip+n)-zip;
	REP(i,n) a[i]=lower_bound(zip,zip+zn,a[i])-zip;
	seg.init(zn);
	REP(i,n){
		seg.add(a[i],1);
		sum_lef[i]=(i?sum_lef[i-1]:0)+seg.query(a[i]+1,zn,0,0,seg.n);
	}
	seg.init(zn);
	for(int i=n-1;i>=0;--i){
		seg.add(a[i],1);
		sum_rig[i]=sum_rig[i+1]+seg.query(0,a[i],0,0,seg.n);
	}
	lef.init(zn);rig.init(zn);
	REP(i,n-1) rig.add(a[i+1],1);
	int j=1;
	lint cursum=0,res=0;
	REP(i,n-1){
		lef.add(a[i],1);
		cursum+=rig.query(0,a[i],0,0,seg.n);
		while(i>=j || (j<n && sum_lef[i]+sum_rig[j]+cursum>k)){
			rig.add(a[j],-1);
			cursum-=lef.query(a[j]+1,zn,0,0,seg.n);
			++j;
		}
		if(sum_lef[i]+sum_rig[j]+cursum<=k) res+=n-j;
	}
	cout<<res<<endl;
	return 0;
}