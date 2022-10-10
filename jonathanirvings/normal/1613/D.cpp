#include <bits/stdc++.h>
using namespace std;

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
constexpr int Mod = Mod998244353;

using Int = ModInt<Mod>;
using BinomCoeff = ModBinomCoeff<Mod>;

int main()
{
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    
    vector<vector<Int>> tot(N + 3, vector<Int>(3));
    for (int i = N - 1; i >= 0; --i) {
      tot[A[i]][0] += 1 + tot[A[i]][0] + tot[A[i] + 1][0] + tot[A[i] + 2][2];
      tot[A[i]][1] += 1 + tot[A[i]][1] + tot[A[i] + 2][2];
      tot[A[i]][2] += 1 + (A[i] >= 2 ? tot[A[i] - 2][1] : 0) + tot[A[i]][2];
    }
    Int answer = tot[0][0] + tot[1][2];
    printf("%d\n", answer.get());
  }
  return 0;
}