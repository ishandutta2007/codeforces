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


template<lint mod>
struct Int_{
	unsigned x;
	unsigned mpow(Int_ a,unsigned k){
		Int_ res=1;
		while(k){
			if(k&1) res=res*a;
			a=a*a;
			k>>=1;
		}
		return res.x;
	}
	unsigned inverse(Int_ a){
		return mpow(a,mod-2);
	}
	Int_(): x(0) { }
	Int_(long long sig) {
    if(sig<0) x=sig%mod+mod;
    else x=sig%mod;
  }
	unsigned get() const { return (unsigned)x; }
	
	Int_ &operator+=(Int_ that) { if((x += that.x) >= mod) x -= mod; return *this; }
	Int_ &operator-=(Int_ that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
	Int_ &operator*=(Int_ that) { x = (unsigned long long)x * that.x % mod; return *this; }
	Int_ &operator=(Int_ that) { x=that.x; return *this;}
	Int_ &operator/=(Int_ that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
	bool operator==(Int_ that) const { return x==that.x; }
	bool operator!=(Int_ that) const { return x!=that.x; }

	Int_ operator-() const { return Int_(0)-Int_(*this);}
	Int_ operator+(Int_ that) const { return Int_(*this) += that; }
	Int_ operator-(Int_ that) const { return Int_(*this) -= that; }
	Int_ operator*(Int_ that) const { return Int_(*this) *= that; }
	Int_ operator/(Int_ that) const { return Int_(*this) /= that; }

};

namespace std{
	template<lint mod>
	ostream &operator <<(ostream& out,const Int_<mod>& a){
		out<<a.get();
		return out;
	}
	template<lint mod>
	istream &operator >>(istream& in,Int_<mod>& a){
		in>>a.x;
		return in;
	}
};

typedef Int_<1000000007> Int;



//const int INF=5e8;

Int dCsum1[100005],dCsum2[100005];
Int dAsum1[100005],dAsum2[100005];
Int size[100005];

int n;
vector<pi> g[100005];


static const int MAXN=100005,LOG_MAX=18;

int dep[MAXN];
Int len[MAXN];
int par[LOG_MAX][MAXN];

int lca(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	int dif=dep[b]-dep[a];
	REP(i,LOG_MAX) if(dif>>i&1) b=par[i][b];
	if(a==b) return a;
	for(int i=LOG_MAX-1;i>=0;--i) if(par[i][a]!=par[i][b]){
		a=par[i][a];
		b=par[i][b];
	}
	return par[0][a];
}

void build(){
	REP(i,LOG_MAX-1){
		REP(j,n){
			if(par[i][j]==-1){
				par[i+1][j]=-1;
			}else{
				par[i+1][j]=par[i][par[i][j]];
			}
		}
	}
}

Int prep(int v,int p,int d=0,Int len_=0){
  par[0][v]=p;
  dep[v]=d;
  len[v]=len_;
  for(auto e:g[v]){
    int to=e.fr;
    if(e.fr==p) continue;
    size[v]+=prep(to,v,d+1,len_+e.sc);
    dCsum1[v]+=dCsum1[to]+size[to]*e.sc;
    dCsum2[v]+=dCsum2[to]+dCsum1[to]*e.sc*2+Int(1)*e.sc*e.sc*size[to];
  }
  size[v]+=1;

  return size[v];
}

void prep2(int v,int p){
  for(auto e:g[v]){
    int to=e.fr;
    if(e.fr==p) continue;
    dAsum1[to]=dAsum1[v]-size[to]*e.sc+(-size[to]+n)*e.sc;
    prep2(to,v);
  }
}

void prep3(int v,int p){
  for(auto e:g[v]){
    int to=e.fr;
    if(e.fr==p) continue;

    dAsum2[to]=dAsum2[v]-(dCsum1[to]+size[to]*e.sc)*2*e.sc+size[to]*e.sc*e.sc
                +(dAsum1[v]-dCsum1[to]-size[to]*e.sc)*2*e.sc+(-size[to]+n)*e.sc*e.sc;
    prep3(to,v);
  }
}


Int getlen(int a,int b){
  int L=lca(a,b);
  return len[a]+len[b]-len[L]*2;
}

int main(){
  cin>>n;
  REP(i,n-1){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
    g[a].pb(mp(b,c));
    g[b].pb(mp(a,c));
  }


  prep(0,-1);
  build();
  dAsum1[0]=dCsum1[0];
  dAsum2[0]=dCsum2[0];
  prep2(0,-1);
  prep3(0,-1);

  int q;cin>>q;

  debug(dAsum1,dAsum1+n);
  debug(dAsum2,dAsum2+n);
  REP(hoge,q){
    int u,v;scanf("%d%d",&u,&v);--u;--v;

    Int res=0;
    Int dist=getlen(u,v);;

    int L=lca(u,v);
    if(L==v){//u is child of v
      res=dAsum2[u];
      int pv=par[0][v];
      if(pv!=-1){
        prl;
        Int d=len[v]-len[pv];
        Int dist2=d+dist;
        res-=(dAsum2[pv]-(dCsum2[v]+d*2*dCsum1[v]+d*d*size[v])+
          (dAsum1[pv]-dCsum1[v]-size[v]*d)*2*dist2+dist2*dist2*(-size[v]+n))*2;
      }else{//v==root
        prl;
      }
    }else{
        prl;
      res=-dAsum2[u];
      res+=(dCsum2[v]+dist*2*dCsum1[v]+dist*dist*size[v])*2;
    }
    printf("%d\n",res.x);
  }

  return 0;
}