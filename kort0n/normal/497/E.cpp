#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
ll N, K;
template< class T >
struct Matrix {
  vector< vector< T > > A;

  Matrix() {}

  Matrix(size_t n, size_t m) : A(n, vector< T >(m, 0)) {}

  Matrix(size_t n) : A(n, vector< T >(n, 0)) {};

  size_t height() const {
    return (A.size());
  }

  size_t width() const {
    return (A[0].size());
  }

  inline const vector< T > &operator[](int k) const {
    return (A.at(k));
  }

  inline vector< T > &operator[](int k) {
    return (A.at(k));
  }

  static Matrix I(size_t n) {
    Matrix mat(n);
    for(int i = 0; i < n; i++) mat[i][i] = 1;
    return (mat);
  }

  Matrix &operator+=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        (*this)[i][j] = ((*this)[i][j] + B[i][j]) % mod;
    return (*this);
  }

  Matrix &operator-=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        (*this)[i][j] = ((*this)[i][j] - B[i][j] + mod) % mod;
    return (*this);
  }

  Matrix &operator*=(const Matrix &B) {
    size_t n = height(), m = B.width(), p = width();
    assert(p == B.height());
    vector< vector< T > > C(n, vector< T >(m, 0));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        for(int k = 0; k < p; k++)
          C[i][j] = ((C[i][j] + (*this)[i][k] * B[k][j])) % mod;
    A.swap(C);
    return (*this);
  }

  Matrix &operator^=(long long k) {
    Matrix B = Matrix::I(height());
    while(k > 0) {
      if(k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const {
    return (Matrix(*this) += B);
  }

  Matrix operator-(const Matrix &B) const {
    return (Matrix(*this) -= B);
  }

  Matrix operator*(const Matrix &B) const {
    return (Matrix(*this) *= B);
  }

  Matrix operator^(const long long k) const {
    return (Matrix(*this) ^= k);
  }

  friend ostream &operator<<(ostream &os, Matrix &p) {
    size_t n = p.height(), m = p.width();
    for(int i = 0; i < n; i++) {
      os << "[";
      for(int j = 0; j < m; j++) {
        os << p[i][j] << (j + 1 == m ? "]\n" : ",");
      }
    }
    return (os);
  }


  T determinant() {
    Matrix B(*this);
    assert(width() == height());
    T ret = 1;
    for(int i = 0; i < width(); i++) {
      int idx = -1;
      for(int j = i; j < width(); j++) {
        if(B[j][i] != 0) idx = j;
      }
      if(idx == -1) return (0);
      if(i != idx) {
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      for(int j = 0; j < width(); j++) {
        B[i][j] /= vv;
      }
      for(int j = i + 1; j < width(); j++) {
        T a = B[j][i];
        for(int k = 0; k < width(); k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }

  void rot() {
      Matrix<ll> B(A.size());
      for(int i = 0; i < K; i++) {
          for(int j = 0; j < K; j++) {
              B[i][j] = A[(i+K-1)%K][(j+K-1)%K];
          }
          B[i][K] = A[(i+K-1)%K][K];
          B[K][i] = A[K][(i+K-1)%K];
          B[K][K] = A[K][K];
      }
      for(int i = 0; i < A.size(); i++) {
          for(int j = 0; j < A[0].size(); j++) {
              A[i][j] = B[i][j];
          }
      }
      /*
      for(int i = A.size()-2; i >= 0; i--) {
          swap(A[i], A[i+1]);
      }
      for(int i = 0; i < A.size(); i++) {
          for(int j = A[0].size() - 2; j >= 0; j--) {
              swap(A[i][j], A[i][j+1]);
          }
      }
      */
  }
};

Matrix<ll> mat[70][35];


ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret;
    if(b & 1) ret *= a;
    return ret;
}

int main() {
    cin >> N >> K;
    ll INDEX = 0;
    ll copy = N;
    while(copy >= K) {
        INDEX++;
        copy /= K;
    }
    mat[0][0] = Matrix<ll>::I(K+1);
    for(int i = 1; i < K + 1; i++) mat[0][0][0][i] = 1;
    //cerr << mat[0][0] << endl;
    for(int i = 1; i < K; i++) {
        mat[0][i] = mat[0][i-1];
        mat[0][i].rot();
        //cerr << mat[0][i] << endl;
    }
    for(int index = 1; index <= INDEX; index++) {
    //for(int index = 1; index < 3; index++) {
        mat[index][0] = mat[index-1][0];
        for(int i = 1; i < K; i++) {
            mat[index][0] = mat[index-1][i] * mat[index][0];
        }
        //cerr << index << " " << 0 << endl;
        //cerr << mat[index][0] << endl;
        for(int i = 1; i < K; i++) {
            mat[index][i] = mat[index][i-1];
            mat[index][i].rot();
            //cerr << index << " " << i << endl;
            //cerr << mat[index][i] << endl;
        }
    }
    cerr << INDEX << endl;
    //cerr << INDEX << endl;
    Matrix<ll> ans(K + 1, 1);
    ans[K][0] = 1;
    int used = 0;
    while(INDEX >= 0) {
        for(int i = 0; ; i++) {
            if(beki(K, INDEX) <= N) {
                N -= beki(K, INDEX);
                //ans = mat[INDEX][i] * ans;
                ans = mat[INDEX][used] * ans;
                used++;
                used %= K;
                /*
                cerr << INDEX << " " << i << endl;
                cerr << mat[INDEX][i] << endl;
                cerr << ans << endl;
                */
            } else break;
        }
        INDEX--;
    }
    ll val = 0;
    for(ll i = 0; i < K + 1; i++) {
        val += ans[i][0];
        val %= mod;
    }
    cout << val << endl;
    return 0;
}