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
typedef pair<lint,lint> pi;

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

const lint INF=1e18;
int n;
lint pos[100005];
lint stre[100005];

pi range1[400005],range2[400005];//(start_pos,rightmost-column)
int m1,m2;
void solve(pi* range,int& m){
  range[m++]=mp(0,0);
  stack<int> stk;
  stk.push(0);
  lint seek;
  for(int i=1;i<n+1;++i){
    stk.push(i);
    seek=pos[i]+1;
    dump(i);
    while(stk.size()>1){
      int p=stk.top(),last;
      stk.pop();
      last=stk.top();
      lint lim=stre[p]-(pos[p]-pos[last])+pos[p];
      dump(p);dump(last);
      dump(stre[p]);
      dump(lim);dump(pos[i+1]);
      dump(seek);
      if(lim<pos[i+1]){
        if(seek<=lim) range[m++]=mp(seek,pos[p]);
        seek=max(seek,lim+1);
      }else{
        stk.push(p);
        break;
      }
    }
    if(seek<=pos[i+1]) range[m++]=mp(seek,pos[stk.top()]);
  }
}
lint L;   
lint solve2(pi* range,int m,lint p){
  p=L-p;
  int q=lower_bound(range,range+m,mp(p+1,-1ll))-range;
  --q;
  return (p-range[q].sc);
}


int main(){
  cin>>n;
  REP(i,n+2) pos[i]=readL();
  REP(i,n) stre[i+1]=readL()*2;
  stre[0]=stre[n+1]=INF;


  solve(range1,m1);
  dump(m1);
  debug(range1,range1+m1);

  if(range1[m1-1].sc>0){
    puts("0");
    return 0;
  }

  L=pos[n+1];
  reverse(pos,pos+n+2);
  REP(i,n+2) pos[i]=L-pos[i];
  reverse(stre,stre+n+2);

  solve(range2,m2);
  debug(range2,range2+m2);

  lint res=INF;
  REP(i,m1){
    if(i) chmin(res,solve2(range2,m2,range1[i].fr)+range1[i].fr-range1[i].sc);
    if(i+1<m1) chmin(res,solve2(range2,m2,range1[i+1].fr-1)+range1[i+1].fr-1-range1[i].sc);
    dump(res);
  }
  REP(i,m2){
    if(i) chmin(res,solve2(range1,m1,range2[i].fr)+range2[i].fr-range2[i].sc);
    if(i+1<m2) chmin(res,solve2(range1,m1,range2[i+1].fr-1)+range2[i+1].fr-1-range2[i].sc);
    dump(res);
  }
  printf("%f\n",(double)res/2);

  return 0;
}