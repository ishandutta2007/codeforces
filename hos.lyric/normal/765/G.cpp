#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }


template<int M_> struct ModInt {
  static constexpr int M = M_;
  int x;
  constexpr ModInt() : x(0) {}
  constexpr ModInt(long long x_) : x(x_ % M) { if (x < 0) x += M; }
  ModInt &operator+=(const ModInt &a) { x += a.x; if (x >= M) x -= M; return *this; }
  ModInt &operator-=(const ModInt &a) { x -= a.x; if (x < 0) x += M; return *this; }
  ModInt &operator*=(const ModInt &a) { x = static_cast<int>((static_cast<long long>(x) * a.x) % M); return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  ModInt operator-() const { return ModInt(-x); }
  ModInt pow(long long e) const {
    ModInt x2 = x, xe = 1;
    for (; e; e >>= 1) {
      if (e & 1) xe *= x2;
      x2 *= x2;
    }
    return xe;
  }
  ModInt inv() const {
    int a = x, b = M, y = 1, z = 0, t;
    for (; ; ) {
      t = a / b; a -= t * b;
      if (a == 0) {
        assert(b == 1 || b == -1);
        return ModInt(b * z);
      }
      y -= t * z;
      t = b / a; b -= t * a;
      if (b == 0) {
        assert(a == 1 || a == -1);
        return ModInt(a * y);
      }
      z -= t * y;
    }
  }
  friend ModInt operator+(long long a, const ModInt &b) { return (ModInt(a) += b); }
  friend ModInt operator-(long long a, const ModInt &b) { return (ModInt(a) -= b); }
  friend ModInt operator*(long long a, const ModInt &b) { return (ModInt(a) *= b); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};

constexpr int MO = 1'000'000'007;
using Mint = ModInt<MO>;


constexpr int MAX_L = 40;
constexpr int MAX_N = 500005;

constexpr Int DATA[][MAX_L + 2] = {
{9054368LL,0,0,0,0,0,0,0,0,0,0,0,0,0,246,6269,70380,474134,1997304,5366588,9157172,9922540,6727466,2752528,631924,71988,3550,56,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{9054376LL,0,0,0,0,0,0,32,2180,51953,522464,2997142,10489360,22925776,31297838,26212616,12959852,3548604,502642,34964,1012,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{545925248LL,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,392,24477,373756,2731632,11507898,30249270,51256820,56392210,39855894,17705862,4753036,736600,65030,3440,124,0,0,0,0,0,0,0,0,0},
{545925280LL,0,0,0,0,0,0,0,0,0,0,0,206,9613,171828,1699424,10684738,44402696,123070612,227588052,279828552,226672908,118300966,38100170,7053276,670736,28082,346,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{545925288LL,0,0,0,0,0,302,23513,573932,6575464,43353410,177434750,464916264,787263042,857118220,587858054,244165588,57824430,7273870,454072,11704,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{2156538016LL,0,0,0,0,0,0,0,0,0,0,0,76,7345,148232,1565668,10340564,44512582,126866036,239744224,299957786,246712224,130833350,42993694,8139682,790732,33846,454,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{2156538024LL,0,0,0,0,10,586,26651,585422,6621874,43953704,182310016,485221556,834884724,922233200,640351458,268770870,64256856,8185868,522746,13944,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{2693408896LL,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,138,28087,905664,11204926,74359108,301811376,798694444,415628691,693315009,359485047,722197034,247597354,52831450,6756022,510834,23786,680,0,0,0,0,0,0,0,0,0},
{2693408928LL,0,0,0,0,0,0,0,0,0,24,5285,208220,3497270,34439076,220552234,955076744,833157574,777712771,91123270,739426025,992505790,117708604,565324882,88472834,7269162,265590,2804,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{2693408936LL,0,0,0,44,4677,236170,5801070,75392202,580015338,815955538,913868468,661527080,876115763,533859699,724178233,935232300,33482635,117650454,6763568,161168,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{137448007840LL,0,0,0,0,0,0,0,0,0,0,0,0,3559,103560,1296282,9593496,45020070,137527508,274954408,360420286,308370698,169024174,57149494,11114942,1110766,49414,708,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{137448007848LL,0,0,0,0,0,264,18989,519358,6460400,45481630,197697272,547818900,977275862,115463479,797614406,343507210,83831690,10817102,693114,18412,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{137984878720LL,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8087,517510,8418000,65605474,297935076,857578000,623666977,47595474,715832303,944247514,333918330,73462050,9705572,760072,36734,1116,0,0,0,0,0,0,0,0,0},
{137984878752LL,0,0,0,0,0,0,0,0,0,0,2467,132092,2682842,29740368,208093574,968564918,52632667,551778338,581965199,513068367,336312466,763197528,756308872,121323688,10244908,388668,4378,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{137984878760LL,0,0,0,0,1945,172348,5116768,72885350,594476948,19239449,928957169,502074137,746642572,763126856,209805581,331263640,350755171,155616886,8976106,213024,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{139595491488LL,0,0,0,0,0,0,0,0,0,0,889,97708,2291254,27214952,199942860,963984306,122377527,848352134,192173750,270147862,937772500,73388911,857232092,140373302,12095134,469126,5742,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{139595491496LL,0,0,0,40,3729,198416,5261382,73399522,600943628,86460349,289324372,603453002,775497058,52942119,787738992,979671300,502946889,175328194,10337468,253624,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{140132362368LL,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2419,517430,17911010,239726696,721479799,608503767,145468590,809524021,626443107,849620935,728231867,380346897,352306510,784464202,87224860,5908042,249868,6120,0,0,0,0,0,0,0,0,0},
{140132362400LL,0,0,0,0,0,0,0,0,219,56862,2615574,50778066,566198330,75876394,885450171,113789175,287902,122793862,26304015,411520378,909860841,118620403,893093928,498500671,110234134,3664094,35492,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{140132362408LL,0,0,133,22408,1465024,45177858,737722240,79342415,742227626,901983232,128736318,173853446,870421252,588710950,634971248,882490569,938943961,506620632,133419564,2932608,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

char S[MAX_L + 1];
int N;
pair<int, int> PE[MAX_N];

int L;
Int A;

Mint dp[MAX_N + 1][MAX_L + 1];

int main() {
  map<Int, vector<Mint>> prec;
  const int numData = sizeof(DATA) / sizeof(DATA[0]);
  for (int h = 0; h < numData; ++h) {
    const Int key = DATA[h][0];
    vector<Mint> val(MAX_L + 1);
    for (int l = 0; l <= MAX_L; ++l) {
      val[l] = DATA[h][1 + l];
    }
    prec[key] = val;
  }
  
  for (; ~scanf("%s", S); ) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d", &PE[i].first, &PE[i].second);
    }
    sort(PE, PE + N);
/*
if(PE[N-1].first>23)continue;
for(int x=0;x<L;++x){
 S[x]='1';
 for(int i=0;i<N;++i)if((123456789+x)%PE[i].first==0)S[x]='0';
}
*/
    
    L = strlen(S);
    A = 0;
    for (int x = 0; x < L; ++x) {
      if (S[x] == '0') {
        A |= 1LL << x;
      }
    }
    
    int I = 0;
    for (int i = 0; i < N; ++i) {
      if (PE[i].first < L) {
        ++I;
      }
    }
    
    Int key = 0;
    for (int i = 0; i < I; ++i) {
      key |= 1LL << PE[i].first;
    }
    
    for (int i = I; i <= N; ++i) {
      fill(dp[i], dp[i] + L + 1, Mint(0));
    }
    auto it = prec.find(key);
    if (L == MAX_L && A == (1LL << L) - 1 && it != prec.end()) {
      for (int l = 0; l <= L; ++l) {
        dp[I][l] = (it->second)[l];
      }
    } else {
      map<Int, Mint> crt;
      crt[A] = 1;
int maxSize=1;
      for (int i = 0; i < I; ++i) {
        int lb, ub;
        if (i + 1 == I) {
          lb = 0;
          ub = L;
        } else {
          lb = L - PE[i + 1].first;
          ub = PE[i + 1].first;
        }
        const Int maskSub = (lb < ub) ? ((1LL << ub) - (1LL << lb)) : 0;
        vector<Int> subs{0};
        if (maskSub) {
          for (int x = lb; x < ub; ++x) {
            if ((A >> x) & 1) {
              const Int sub = subs.back() | 1LL << x;
              subs.push_back(sub);
            }
          }
        }
        vector<Int> pats;
        for (int r = 0; r < PE[i].first; ++r) {
          Int pat = 0;
          for (int x = 0; x < L; ++x) {
            if ((r + x) % PE[i].first == 0) {
              pat |= 1LL << x;
            }
          }
          if (!(~A & pat)) {
            pats.push_back(pat);
          }
        }
        map<Int, Mint> nxt;
        for (const auto &entry : crt) {
          for (const Int pat : pats) {
            Int p = entry.first & ~pat;
            if (maskSub) {
              const int pop = __builtin_popcountll(p & maskSub);
              p = (p & ~maskSub) | subs[pop];
            }
            nxt[p] += entry.second;
          }
        }
// cerr<<PE[i]<<"; |nxt| = "<<nxt.size()<<endl;
chmax(maxSize,(int)nxt.size());
        crt = nxt;
      }
      for (const auto &entry : crt) {
        dp[I][__builtin_popcountll(entry.first)] += entry.second;
      }
    }
    
// cerr<<"dp[I] = ";pv(dp[I],dp[I]+L+1);
/*
if(maxSize>=1'000'000){
 fprintf(stderr,"{%lldLL",key);
 for(int l=0;l<=L;++l)fprintf(stderr,",%d",dp[I][l].x);
 fprintf(stderr,"},\n");
 fflush(stderr);
}
//*/
    const int LA = __builtin_popcountll(A);
    for (int i = I; i < N; ++i) {
      for (int l = 0; l <= L; ++l) {
        dp[i + 1][l] += dp[i][l] * ((PE[i].first - L) + (LA - l));
        if (l >= 1) {
          dp[i + 1][l - 1] += dp[i][l] * l;
        }
      }
    }
    
    Mint ans = dp[N][0];
/*
int brt=0;
int prod=1;for(int i=0;i<N;++i)prod*=PE[i].first;
for(int r=0;r<prod;++r){
 bool ok=true;
 for(int x=0;x<L;++x)if((__gcd(r+x,prod)==1)!=(S[x]=='1')){ok=false;break;}
 if(ok)++brt;
}
assert(brt==ans.x);
//*/
    for (int i = 0; i < N; ++i) {
      ans *= Mint(PE[i].first).pow(PE[i].second - 1);
    }
    printf("%d\n", ans.x);
  }
  return 0;
}