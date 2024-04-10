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
int n,m,K;
char p[1000005];
int ar[1000005];
int table[1000005];
int sum[1000005];
const lint mod=1000000007;
int main(){
  cin>>n>>m;
  scanf("%s",p);
  K=strlen(p);
  REP(i,m){
    scanf("%d",&ar[i]);
    --ar[i];
    sum[ar[i]]++;
    sum[ar[i]+K]--;
  }
  REP(i,n) sum[i+1]+=sum[i];
  lint res=1;
  REP(i,n) if(sum[i]==0) res=(res*26)%mod;

	int klen=strlen(p);
	table[0]=0;
	REPN(i,klen+1,1){
		int j=table[i-1];
		while(j>0 && p[j]!=p[i]) j=table[j-1];
		if(p[j]==p[i]) ++j;
		table[i]=j;
	}

  int unit=klen-table[klen-1],rest=K%unit;
  REP(i,m-1){
    int x=ar[i],y=ar[i+1];
    if(y-x>=K) ;
    else if((K-(y-x))%unit!=rest){
      puts("0");
      return 0;
    }
  }
  cout<<res<<endl;


  return 0;
}