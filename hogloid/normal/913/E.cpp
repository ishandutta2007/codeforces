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
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
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


/*

int isE[10][10],isT[10][10],isF[10][10];//init:-1 fail:-2

int chkT(int,int);
int chkF(int,int);
int chkE(int l,int r){
  int& res=isE[l][r];
  if(~res) return res;
  int tmp;
  if((tmp=chkT(l,r))!=-2) return tmp;
  REPN(i,r-1,l+1) if(S[i]=='|'){
    int a=chkT(l,i),b=chkT(i+1,r);
    if(a>=0 && b>=0) return (a|b);
  }
  return res=-2;
}
int chkT(int l,int r){
  int& res=isT[l][r];
  if(~res) return res;
  int tmp;
  if((tmp=chkF(l,r))!=-2) return tmp;
  REPN(i,r-1,l+1) if(S[i]=='&'){
    int a=chkF(l,i),b=chkF(i+1,r);
    if(a>=0 && b>=0) return (a&b);
  }
  return res=-2;
}
int chkF(int l,int r){
  int& res=isF[l][r];
  if(~res) return res;
  if(r-l==1){
    if(S[l]=='x') return res=(15<<4);
    else if(S[l]=='y') return res=(3<<2)+(3<<6);
    else if(S[l]=='z') return res=(2+8+32+128);
    return res=-2;
  }
  if(r-l>=2 && S[l]=='!' && chkF(l+1,r)>=0){
    return res=((~chkF(l+1,r))&255);
  }
  if(r-l>=3 && S[l]=='(' && S[r-1]==')' && chkE(l+1,r-1)>=0){
    return res=chkE(l+1,r-1);
  }
  return res=-2;
}

int solve(string s){
  S=s;
  memset(isF,-1,sizeof(isF));
  memset(isT,-1,sizeof(isT));
  memset(isE,-1,sizeof(isE));
  return chkE(0,s.size());
}
*/



string Es[300],Ts[300],Fs[300];

int L=256;

string alph="&|!xyz()";
const int M=8;

string ans[300];

void renew(string& S,string T){
  if(S.empty()) S=T;
  else if(S.size()>T.size()) S=T;
  else if(S.size()==T.size() && S>T) S=T;
}
int main(){
  sort(ALL(alph));
  Fs[2+8+32+128]="z";
  Fs[(3<<2)+(3<<6)]="y";
  Fs[15<<4]="x";
  for(int len=1;len<=12;++len){
//    dump(len);
    REP(bit,L){
      {
        if(!Ts[bit].empty()){
          renew(Es[bit],Ts[bit]);
        }
        REP(j,L) REP(k,L) if((j|k)==bit && !Es[j].empty() && !Ts[k].empty()){
          renew(Es[bit],Es[j]+'|'+Ts[k]);
        }
      }
      {
        if(!Fs[bit].empty()){
          renew(Ts[bit],Fs[bit]);
        }
        REP(j,L) REP(k,L) if((j&k)==bit && !Ts[j].empty() && !Fs[k].empty()){
          renew(Ts[bit],Ts[j]+'&'+Fs[k]);
        }
      }
      {
        if(!Fs[(~bit)&255].empty()){
          renew(Fs[bit],(string)"!"+Fs[(~bit)&255]);
        }
        if(!Es[bit].empty()){
          renew(Fs[bit],(string)"("+Es[bit]+")");
        }
      }
    }
  }
  int q;
  cin>>q;
  while(q--){
    string T;cin>>T;
    int n=0;
    REP(i,8) if(T[i]=='1') n+=(1<<i);
    cout<<Es[n]<<endl;
  }
  return 0;
}