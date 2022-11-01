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

//const int INF=5e8;
static const int MAXN=2005;
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
  int query(int l,int r){
    return query(r)-query(l);
  }
};
BIT bit[2005];
int h,w,k;

char buf[2005][2005];
pi ps[2005];

int res[2005];

int dp[2005][2005];
int getans(){
  int res=0;
  REP(i,h) REP(j,w) {
    if(buf[i][j]=='X') ;
    else if(i==0 || j==0) dp[i][j]=1;
    else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
    chmax(res,dp[i][j]);
  }
  return res;
}


int main(){
  cin>>h>>w>>k;
  REP(i,h) scanf("%s",buf[i]);

  REP(i,k){
    int y,x;scanf("%d%d",&y,&x);--y;--x;
    ps[i]=mp(y,x);
    buf[y][x]='X';
  }

  REP(i,h) bit[i].init(w);

  REP(i,h) REP(j,w) if(buf[i][j]=='X'){
    bit[i].add(j,1);
  }

  res[k-1]=getans();

   
  int ans=res[k-1];
  static int right[2005],left[2005];
  
  for(int i=k-1;i>0;--i){
    int y=ps[i].fr,x=ps[i].sc;
    bit[y].add(x,-1);
    
    int p=w-1,q=0;
    for(int j=y;j>=0;--j){
      while(bit[j].query(x,p+1)>0) --p;
      right[j]=p;

      while(bit[j].query(q,x+1)>0) ++q;
      left[j]=q;
    }

    p=w-1;q=0;
    for(int j=y;j<h;++j){
      while(bit[j].query(x,p+1)>0) --p;
      right[j]=p;

      while(bit[j].query(q,x+1)>0) ++q;
      left[j]=q;
    }

    
    bool changed=true;
    while(changed){
      changed=false;
      int tmp=ans+1;
      REP(j,y+1) if(right[j]>=x){

        int a=j,b=right[j],c=j+tmp-1,d=b-tmp+1;
        if(c>=h || d<0) continue;
        if(right[c]>=b && left[c]<=d && left[a]<=d){
          changed=true;
          ++ans;
          goto exi;
        }
      }
      REPN(j,h,y) if(right[j]>=x){
        int a=j,b=right[j],c=j-tmp+1,d=b-tmp+1;
        if(c<0 || d<0) continue;
        if(right[c]>=b && left[c]<=d && left[a]<=d){
          changed=true;
          ++ans;
          goto exi;
        }
      }
exi:;
    }
    res[i-1]=ans;
  }

  REP(i,k) printf("%d\n",res[i]);

  return 0;
}