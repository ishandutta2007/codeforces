#include<bits/stdc++.h>
#include<unistd.h>
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

const int INF=5e8;

int n,c;
int ch[1000005][2];


void imp(){
  puts("IMPOSSIBLE");
  exit(0);
}

vector<int> sub[1000005][2];

int maxi[1000005],divi[1000005];

void dfs(int v,int p,int till){
  if(divi[v]==v+1){
    if(v+1<till){
      ch[v][1]=v+1;
      dfs(v+1,v,till);
    }
  }else if(v+1<till){
    ch[v][0]=v+1;
    dfs(v+1,v,min(till,divi[v]));

    if(divi[v]<till){
      ch[v][1]=divi[v];
      dfs(divi[v],v,till);
    }
  }
}


void dfs2(int v){
  int L=ch[v][0],R=ch[v][1];
  if(~L) dfs2(L);
  printf("%d ",v+1);
  if(~R) dfs2(R);
}

bool check(int v,int c){
  if(v==-1) return false;
  if(v==c) return true;
  int L=ch[v][0],R=ch[v][1];
  if(~L && check(L,c)) return true;
  if(~R && check(R,c)) return true;
  return false;
}
struct segtree{
	static const int MAX_N=2200000;
	int val[MAX_N];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=INF;
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
segtree seg;

int main(){
  cin>>n>>c;
  char tmp[10];

  memset(ch,-1,sizeof(ch));
  REP(i,c){
    int a,b;
    scanf("%d%d%s",&a,&b,tmp);
    --a;--b;
    int t;

    if(a>=b) imp();

    if(tmp[0]=='L') t=0;
    else t=1;

    if(a>=b) imp();
    
    sub[a][t].pb(b);
  }
  seg.init(n);
  for(int i=n-1;i>=0;--i){
    maxi[i]=i;
    int Lmaxi=i;
    REP(t,2){
      sort(ALL(sub[i][t]));
      for(auto e:sub[i][t]){
        if(t==0) chmax(Lmaxi,maxi[e]);
        chmax(maxi[i],maxi[e]);
      }
    }
    chmax(maxi[i],-seg.query(i,maxi[i]+1,0,0,seg.n));
    seg.set(i,-maxi[i]);


    chmax(Lmaxi,-seg.query(i+1,Lmaxi+1,0,0,seg.n));
    if(!sub[i][1].empty() && Lmaxi>=sub[i][1][0]) imp();

    divi[i]=Lmaxi+1;
  }

  dfs(0,-1,n);

  dfs2(0);
  putchar('\n');
  return 0;
}