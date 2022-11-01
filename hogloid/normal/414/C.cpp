#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

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

static const int MAX_N=(1<<20);
struct BIT{
	int val[MAX_N*2+2];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n+1) val[i]=0;
	}
	void add(int k,int a){
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
	int query(int k){	//[0,k)
		int res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return res;
	}
};

BIT bit;

//const int INF=5e8;

int ar[1<<20];
int n,k;

struct segtree{
	vector<int> val[2*(1<<20)];
	lint inv[25],same[25],tot[25];

	void init(int* ar){
		REP(i,n) val[i+n-1].pb(ar[i]);
		for(int i=n-2;i>=0;--i){
			int p=0,q=0;
			lint inver=0;
			vector<int>& a=val[i*2+1],&b=val[i*2+2];
			while(p<a.size() || q<b.size()){
				if(p!=a.size() && (q==b.size() || a[p]<=b[q])){
					val[i].pb(a[p]),++p;
				}else{
					val[i].pb(b[q]),++q;
					inver+=(a.size()-p);
				}
			}


			
			int lastbit=0;
			REP(j,22) if((i+1)>>j&1) lastbit=j;
			
			inv[k-lastbit]+=inver;

			REP(j,val[i].size()){
				int j2=j;
				while(j2<val[i].size() && val[i][j]==val[i][j2]) ++j2;
				same[k-lastbit]+=(j2-j)*(lint)(j2-j-1)/2;
				j=j2-1;
			}
			dump(k-lastbit);
			tot[k-lastbit]+=a.size()*(lint)b.size();
		}

		for(int i=k;i>=1;--i) same[i]-=same[i-1];
		debug(inv,inv+k+1);
		debug(tot,tot+k+1);
		debug(same,same+k+1);
	}
	lint query(int q){
		REP(i,q+1){
			inv[i]=tot[i]-same[i]-inv[i];
		}
		lint res=0;
		REP(j,k+1) res+=inv[j];
		return res;
	}
};

segtree seg;
int main(){
	scanf("%d",&n);
	k=n;
	n=(1<<n);

	REP(i,n) scanf("%d",&ar[i]);
	
	seg.init(ar);

	int m;scanf("%d",&m);
	REP(hoge,m){
		int q;scanf("%d",&q);

		lint res=seg.query(q);

#ifdef ONLINE_JUDGE
		printf("%I64d\n",res);
#else
		cout<<res<<'\n';
#endif
	}


	return 0;
}