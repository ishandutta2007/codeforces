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
int n,N;
int ar[100005];


int cnt[100005];
int C;

bool check(int* ar,int k,int n){
  CLR(cnt);
  if(n&1){
    int mid=n/2;
    if(k<=mid){
      for(int i=1;mid-i>=k;++i) if(ar[mid-i]!=ar[mid+i]) return false;
      REP(i,k){
        cnt[ar[i]]++;
        cnt[ar[n-1-i]]--;
      }

      REP(i,N) if(cnt[i]!=0) return false;
      return true;
    }else{
      REP(i,n) ++cnt[ar[i]];
      int odd=-1;
      REP(i,N) if(cnt[i]&1) {
        if(odd==-1) odd=i;
        else odd=-2;
      }
      if(odd<0) return false;

      --cnt[odd];
      REPN(i,n,k) cnt[ar[i]]-=2;

      REP(i,N) if(cnt[i]<0) return false;
      return true;
    }
  }else{
    int half=n/2;
    if(k<=half){
      for(int i=0;half-i-1>=k;++i) if(ar[half-1-i]!=ar[half+i]) return false;
      REP(i,k){
        cnt[ar[i]]++;
        cnt[ar[n-1-i]]--;
      }

      REP(i,N) if(cnt[i]!=0) return false;
      return true;
    }else{
      REP(i,n) ++cnt[ar[i]];
      REP(i,N) if(cnt[i]&1) return false;

      REPN(i,n,k) cnt[ar[i]]-=2;

      REP(i,N) if(cnt[i]<0) return false;
      return true;
    }
  }
}

lint solve(int* ar,int n){
  int lb=0,ub=n;
  while(ub-lb>1){
    int md=(lb+ub)>>1;
    if(check(ar,md,n)) ub=md;
    else lb=md;
  }

  return n-ub;
}
int main(){
  cin>>n;
  N=n;
  REP(i,n) scanf("%d",&ar[i]),--ar[i];


  while(C<n && ar[C]==ar[n-1-C]) ++C;
  
  lint res=0;
  dump(C);
  if(C==n) res=n*(lint)(n+1)/2;
  else{
    if(!check(ar+C,n-C*2,n-C*2)) ;
    else{
      res+=(C+1)*(lint)(C+1);

      res+=solve(ar+C,n-C*2)*(lint)(C+1);
      reverse(ar+C,ar+n-C);
      res+=solve(ar+C,n-C*2)*(lint)(C+1);
    }
  }
  cout<<res<<endl;

  return 0;
}