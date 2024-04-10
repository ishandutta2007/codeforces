#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
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

lint readL(){
  lint res;
#ifdef ONLINE_JUDGE
  scanf("%I64d",&res);
#else
  scanf("%lld",&res);
#endif
  return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
  printf("%I64d",res);
#else
  printf("%lld",res);
#endif
}
//const int INF=5e8;
static const int MAXN=200005;
struct BIT{
	int val[MAXN*2+2];
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


int n;
int p[200005],q[200005];

BIT bit1,bit2;;

int res[200005];
int main(){
  cin>>n;
  REP(i,n) scanf("%d",&p[i]);
  REP(i,n) scanf("%d",&q[i]);

  bit1.init(n);bit2.init(n);

  REP(i,n){
    bit1.add(i,1);
    bit2.add(i,1);
  }

  REP(i,n){
    res[i]=(bit1.query(p[i])+bit2.query(q[i]));
    bit1.add(p[i],-1);
    bit2.add(q[i],-1);
  }
  for(int i=n-1;i>=0;--i){
    if(res[i]>=n-i){
      if(i) res[i-1]+=res[i]/(n-i);
      res[i]%=n-i;
    }
  }
  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> left;

  REP(i,n) left.insert(i);
  REP(i,n){
    int t=*left.find_by_order(res[i]);
    res[i]=t;
    left.erase(t);
  }

  REP(i,n) printf("%d\n",res[i]);

  return 0;
}