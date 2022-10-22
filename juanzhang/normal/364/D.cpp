#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
typedef long long ll;
const int maxn=1e6+10;
int n;ll A[maxn];

signed main(){
  srand(time(0));
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;rep(i,1,n)cin>>A[i];
  ll res=1;
  rep(T,1,11){
    ll x=A[(1ll*rand()<<15|rand())%n+1];
    static int pr[maxn],ts[maxn];
    static ll vec[maxn];
    int ct=0;
    rep(i,1,sqrt(x))if(x%i==0)vec[++ct]=i;
    bool flg=vec[ct]*vec[ct]==x;
    rep(i,1,ct)vec[ct+i-flg]=x/vec[ct-i+1];
    ct=ct+ct-flg;
    memset(pr,0,(ct+2)<<2),memset(ts,0,(ct+2)<<2);
    rep(i,1,n){
      ts[lower_bound(vec+1,vec+ct+1,__gcd(A[i],x))-vec]++;
    }
    per(i,ct,1){
      ll tp=vec[i];int k=ts[i];
      if(tp<=res)break;
      if((pr[i]+=k)>=(n+1)/2){
        res=tp;break;
      }
      rep(j,1,i-1)if(tp%vec[j]==0)pr[j]+=k;
    }
  }
  cout<<res<<endl;
  return 0;
}