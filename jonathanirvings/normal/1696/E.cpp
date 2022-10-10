//start of jonathanirvings' template v3.0.3 (BETA)

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG 
  #define VALUE(x)
  #define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}

inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}

inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}

inline string uppercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string lowercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}

inline void OPEN (string s) {
  #ifndef TESTING
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
  #endif
}

//end of jonathanirvings' template v3.0.3 (BETA)

template <int Mod>
struct ModInt {
  
  ModInt() : num_(0) {}

  template <class T>
  ModInt(T num) {
    long long x = (long long)(num % (long long)(Mod));
    if (x < 0) x += Mod;
    num_ = (int)(x);
  }

  ModInt& operator++() {
    num_++;
    if (num_ == Mod) num_ = 0;
    return *this;
  }
  ModInt& operator--() {
    if (num_ == 0) num_ = Mod;
    num_--;
    return *this;
  }
  ModInt operator++(int) {
    ModInt result = *this;
    ++*this;
    return result;
  }
  ModInt operator--(int) {
    ModInt result = *this;
    --*this;
    return result;
  }

  ModInt& operator+=(const ModInt& rhs) {
    num_ += rhs.num_;
    if (num_ >= Mod) num_ -= Mod;
    return *this;
  }
  ModInt& operator-=(const ModInt& rhs) {
    num_ -= rhs.num_;
    if (num_ < 0) num_ += Mod;
    return *this;
  }
  ModInt& operator*=(const ModInt& rhs) {
    long long z = num_;
    z *= rhs.num_;
    num_ = (int)(z % Mod);
    return *this;
  }
  ModInt& operator/=(const ModInt& rhs) { return *this = *this * rhs.inv(); }

  ModInt operator+() const { return *this; }
  ModInt operator-() const { return ModInt() - *this; }

  ModInt pow(long long n) const {
    assert(0 <= n);
    ModInt x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  ModInt inv() const {
    return pow(Mod - 2);
  }
 
  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) += rhs;
  }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) -= rhs;
  }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) *= rhs;
  }
  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) /= rhs;
  }
  friend bool operator==(const ModInt& lhs, const ModInt& rhs) {
    return lhs.num_ == rhs.num_;
  }
  friend bool operator!=(const ModInt& lhs, const ModInt& rhs) {
    return lhs.num_ != rhs.num_;
  }

  int get() const { return num_; }
 
  int num_;
};

template <int Mod>
struct ModBinomCoeff {

  ModBinomCoeff() {}
  ModBinomCoeff(int N) : fact_(N + 1), inv_fact_(N + 1) {
    fact_[0] = 1;
    for (int i = 1; i <= N; ++i) {
      fact_[i] = fact_[i - 1] * (i);
    }
    inv_fact_[N] = fact_[N].inv();
    for (int i = N - 1; i >= 0; --i) {
      inv_fact_[i] = inv_fact_[i + 1] * (i + 1);
    }
  }

  ModInt<Mod> fact(int N) {
    assert(N < fact_.size());
    return fact_[N];
  }
  ModInt<Mod> choose(int N, int K) {
    assert(N < fact_.size());
    return fact_[N] * inv_fact_[K] * inv_fact_[N - K];
  }

  vector<ModInt<Mod>> fact_;
  vector<ModInt<Mod>> inv_fact_;
};

constexpr int Mod998244353 = 998244353;
constexpr int Mod1000000007 = 1000000007;
constexpr int Mod = Mod1000000007;

using Int = ModInt<Mod>;
using BinomCoeff = ModBinomCoeff<Mod>;

int n;
int a[200005];
BinomCoeff bf(1000000);

int main()
{
  scanf("%d",&n);
  Int risan = 0;
  FORN(i,1,n+1)
  {
    scanf("%d",&a[i]);
    if (a[i] > 0) risan += bf.choose(a[i] + i - 1,i);
  }
  printf("%d\n",risan.get());
  return 0;
}