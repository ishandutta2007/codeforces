#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=1010;
const ll P=1000000016000000063ll;
int n,m,q;
bitset<maxn>bit[35],A[1<<15];int len,val[1<<15];
unordered_map<bitset<maxn>,int>mpA,mpB;

int main(){
  cin>>n>>m>>q;
  rep(i,1,m){
    int k,x;cin>>k;while(k--)scanf("%d",&x),bit[i][x]=1;
  }
  int m1=m/3,m2=m-m1;bitset<maxn>cur;
  rep(S,0,(1<<m1)-1){
    int ct=0;cur.reset();
    rep(i,1,m1)if(S>>(i-1)&1){
      ct++,cur^=bit[i];
    }
    if(mpA.find(cur)==mpA.end())mpA[cur]=len,val[len]=ct,A[len++]=cur;
    else if(val[mpA[cur]]>ct)val[mpA[cur]]=ct;
  }
  rep(S,0,(1<<m2)-1){
    int ct=0;cur.reset();
    rep(i,m1+1,m)if(S>>(i-m1-1)&1){
      ct++,cur^=bit[i];
    }
    if(mpB.find(cur)==mpB.end()||mpB[cur]>ct)mpB[cur]=ct;
  }
  while(q--){
    cur.reset();int ans=1e9;
    int k,x;cin>>k;while(k--)scanf("%d",&x),cur[x]=1;
    rep(i,0,len-1){
      bitset<maxn>ano=cur^A[i];
      if(mpB.find(ano)!=mpB.end())ans=min(ans,val[i]+mpB[ano]);
    }
    cout<<(ans>m?-1:ans)<<endl;
  }
  return 0;
}