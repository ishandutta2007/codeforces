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
int ar[100005];
int zip[200005];
pair<int,pi> query[100005];

struct segtree{
	struct node{
		bool ignore;
		lint cost,num,toL,toR;
		lint left,right;

	};
	node null;
	node val[800005];
	int n;
	void init(int n_){
		null.ignore=1;
		n=1;
		while(n<n_) n<<=1;
		REP(i,n_){
			val[i+n-1].left=val[i+n-1].right=zip[i];
		}
		REPN(i,n,n_) val[i+n-1].left=val[i+n-1].right=zip[n_-1];
		for(int i=n-2;i>=0;--i) update(val[i],val[i*2+1],val[i*2+2]);
	}

	void update(node& a,node b,node& c){
		if(b.ignore){
			a=c;return;
		}
		if(c.ignore){
			a=b;return;
		}

		a.cost=b.cost+c.cost+b.toR*c.num+c.toL*b.num+
			b.num*c.num*(c.left-b.right);
		a.num=b.num+c.num;
		a.toL=b.toL+c.toL+(c.left-b.left)*c.num;
		a.toR=b.toR+c.toR+(c.right-b.right)*b.num;
		a.left=b.left;
		a.right=c.right;
	}

	void set(int k,int a){
		k+=n-1;
		val[k].num=a;
		while(k>0){
			k=(k-1)/2;
			update(val[k],val[k*2+1],val[k*2+2]);
		}
	}
	node rets;
	void query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b){
			update(rets,rets,val[i]);
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		query(a,b,i*2+1,l,md);
		query(a,b,i*2+2,md,r);
	}
	lint query2(int a,int b){
		rets=null;
		query(a,b,0,0,n);
		return rets.cost;
	}
};

segtree seg;
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&ar[i]),zip[i]=ar[i];
	scanf("%d",&m);

	int cnt=n;
	REP(i,m){
		int t,a,b;scanf("%d%d%d",&t,&a,&b);
		
		query[i]=mp(t,mp(a,b));
		if(t==1){
			zip[cnt++]=ar[a-1]+b;
			ar[a-1]+=b;
		}
	}


	REP(i,n) ar[i]=zip[i];
	sort(zip,zip+cnt);
	cnt=unique(zip,zip+cnt)-zip;

	seg.init(cnt);
	REP(i,n){
		int p=lower_bound(zip,zip+cnt,ar[i])-zip;
		seg.set(p,1);
	}
	
	REP(i,m){
		int t=query[i].fr,a=query[i].sc.fr,b=query[i].sc.sc;
		if(t==1){
			--a;
			int p=lower_bound(zip,zip+cnt,ar[a])-zip;
			seg.set(p,0);
			ar[a]+=b;
			p=lower_bound(zip,zip+cnt,ar[a])-zip;
			seg.set(p,1);
		}else{
			++b;
			a=lower_bound(zip,zip+cnt,a)-zip;
			b=lower_bound(zip,zip+cnt,b)-zip;

			cout<<seg.query2(a,b)<<endl;
		}
	}



	return 0;
}