#include <bits/stdc++.h>
using namespace std;

#define ALL(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=2e6+10,P=1e9+7;
int n,q,lev,len[25];char S[maxn],T[maxn],W[maxn];

const int P1 = 1e9 + 7, P2 = 1e9 + 9;
int base, pow1[maxn], pow2[maxn];

struct Hash {
  int v1, v2;

  Hash() {}
  Hash(int x, int y) : v1(x), v2(y) {}

  void print() {
    printf("#(%d %d)\n", v1, v2);
  }

  void get(Hash &o, char ch) {
    v1 = (1ll * o.v1 * base + ch) % P1;
    v2 = (1ll * o.v2 * base + ch) % P2;
  }

  bool operator == (const Hash &o) const {
    return v1 == o.v1 && v2 == o.v2;
  }

  bool operator != (const Hash &o) const {
    return v1 != o.v1 || v2 != o.v2;
  }
}H[maxn],G[maxn];

Hash getsum(Hash *A, int l, int r) {
  return Hash((A[r].v1 + 1ll * (P1 - A[l - 1].v1) * pow1[r - l + 1]) % P1,
              (A[r].v2 + 1ll * (P2 - A[l - 1].v2) * pow2[r - l + 1]) % P2);
}

void init() {
  base = Rnd();
  if (base < 0) base = -base;
  base %= 19260817, base += 257;
  pow1[0] = pow2[0] = 1;
  rep(i, 1, maxn - 1) {
    pow1[i] = 1ll * base * pow1[i - 1] % P1;
    pow2[i] = 1ll * base * pow2[i - 1] % P2;
  }
}

int pw2[maxn],ipw2[maxn];
vi ch_pos[26],ch_sum[26];

void solve(){
  init();
  scanf("%d%d%s%s",&n,&q,S+1,T+1);
  pw2[0]=ipw2[0]=1;
  rep(i,1,n){
    pw2[i]=2*pw2[i-1]%P,ipw2[i]=1ll*(P+1)/2*ipw2[i-1]%P;
    ch_pos[T[i]-'a'].push_back(i);
    vi&vec=ch_sum[T[i]-'a'];
    vec.push_back(((vec.empty()?0:vec.back())+ipw2[i])%P);
  }
  len[0]=strlen(S+1);
  rep(i,1,22){
    len[i]=len[i-1]*2+1;
    if(len[i]<2e6&&i<=n){
      lev=i,S[len[i-1]+1]=T[i];
      rep(j,1,len[i-1])S[len[i-1]+j+1]=S[j];
    }
  }
  rep(i,1,len[lev])H[i].get(H[i-1],S[i]);
  while(q--){
    int k;scanf("%d%s",&k,W+1);int wlen=strlen(W+1);
    int res=0,p=0;while(p<=lev&&len[p]<wlen)p++;
    if(k<p){
      puts("0");continue;
    }
    rep(i,1,wlen)G[i].get(G[i-1],W[i]);
    rep(i,1,len[p]-wlen+1)res+=getsum(H,i,i+wlen-1)==getsum(G,1,wlen);
    res=1ll*res*pw2[k-p]%P;
    rep(i,1,wlen)if((i==1||getsum(H,len[p]-i+2,len[p])==getsum(G,1,i-1))&&(i==wlen||getsum(H,1,wlen-i)==getsum(G,i+1,wlen))){
      vi&pos=ch_pos[W[i]-'a'],&sum=ch_sum[W[i]-'a'];
      int l=upper_bound(ALL(pos),p)-pos.begin();
      int r=upper_bound(ALL(pos),k)-pos.begin()-1;
      res=(res+1ll*pw2[k]*(l<=r?sum[r]-(l?sum[l-1]:0)+P:0))%P;
//      rep(j,p+1,k)if(T[j]==W[i])res=(res+pw2[k-j])%P;
    }
    printf("%d\n",res);
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}