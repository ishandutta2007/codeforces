
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>

#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}



//const int INF=5e8;
	

int n;
int ar[100005];

struct segtree{
	int val[400005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;

		REP(i,n*2) val[i]=1;
		REP(i,n_) val[i+n-1]=ar[i];
		for(int i=n-2;i>=0;--i) val[i]=__gcd(val[i*2+1],val[i*2+2]);
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		return __gcd(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};

segtree seg;
pi ar2[100005];
int main(){
	cin>>n;
	REP(i,n){
		scanf("%d",&ar[i]);
		ar2[i]=mp(ar[i],i);
	}
	sort(ar2,ar2+n);

	seg.init(n);

	int q;cin>>q;
	REP(hoge,q){
		int l,r;scanf("%d%d",&l,&r);
		--l;

		int g=seg.query(l,r,0,0,seg.n);

		int cnt=lower_bound(ar2,ar2+n,mp(g,r))-lower_bound(ar2,ar2+n,mp(g,l));
		
		cnt=(r-l)-cnt;
		printf("%d\n",cnt);
	}

	return 0;
}