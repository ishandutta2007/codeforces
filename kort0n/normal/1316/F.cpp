#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<ll, ll> i_i;
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

const ll mod = 1000000007;
template<typename R, size_t N>
struct SquareMatrix{
  typedef array<R, N> arr;
  typedef array<arr, N> mat;
  mat dat;
 
  SquareMatrix I() {
    for(int i = 0; i < N; i++) dat[i][i] = 1;
  }
 
  bool operator==(const SquareMatrix& a) const{
    return dat==a.dat;
  }
 
  size_t size() const{return N;}
  arr& operator[](size_t k){return dat[k];}
  const arr& operator[](size_t k) const {return dat[k];}
 
  SquareMatrix operator*(const SquareMatrix &B) const{
    SquareMatrix res;
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++) {
        res[i][j] = 0;
        for(size_t k=0;k<N;k++) {
          res[i][j]=(res[i][j]+dat[i][k]*B[k][j])%mod;
        }
      }
    return res;
  }
 
};
typedef SquareMatrix<ll, 3> Matrix;
ll inv2 = 500000004;

SquareMatrix<ll, 3> I() {
  SquareMatrix<ll, 3> A;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      A[i][j] = 0;
    }
  }
  for(int i = 0; i < 3; i++) A[i][i] = 1;
  return A;
}

Matrix f(ll x) {
  Matrix ret;
  ret[0][0] = 1;
  ret[1][0] = x;
  ret[2][0] = 0;
  ret[0][1] = 0;
  ret[1][1] = inv2;
  ll factor = x * inv2 % mod;
  factor = factor * inv2 % mod;
  ret[2][1] = factor;
  ret[0][2] = 0;
  ret[1][2] = 0;
  ret[2][2] = 1;
  return ret;
}
ll N;
vector<ll> p;
ll Q;
vector<ll> IDX, X;
vector<i_i> cmp;
void print(Matrix A) {
  cerr << "-----------" << endl;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cerr << A[i][j] << " ";
    }
    cerr << endl;
  }
  cerr << "------------" << endl;
}

struct SegmentTree {
    int n;
    vector<Matrix> node;
 
public:
    SegmentTree() {
        int sz = 600001;
        //cerr << sz << endl;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, I());
        for(int i=0; i<sz; i++) node[i+n-1] = I();
        for(int i = 0; i < N; i++) {
            l_l tmp = {p[i], i};
            auto itr = lower_bound(cmp.begin(), cmp.end(), tmp);
            //cerr << (*itr).first << " " << (*itr).second << endl;
            int idx = distance(cmp.begin(), itr);
            //int idx = mp[tmp];
            //cerr << i << " " << "{" << p[i] << ", " << i << "} " << idx << endl;
            node[idx+n-1] = f(p[i]);
        }
        for(int i=n-2; i>=0; i--) node[i] = (node[2*i+1] * node[2*i+2]);
    }
 
    void update(int x, Matrix A) {
        x += (n - 1);
        node[x] = A;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = (node[2*x+1] * node[2*x+2]);
        }
    }
    Matrix getproduct(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return I();
        if(a <= l && r <= b) return node[k];
 
        auto vl = getproduct(a, b, 2*k+1, l, (l+r)/2);
        auto vr = getproduct(a, b, 2*k+2, (l+r)/2, r);
        return (vl * vr);
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    p.resize(N);
    for(int i = 0; i < N; i++) {
      cin >> p[i];
      cmp.push_back({p[i], i});
    }
    //cmp.push_back({1e10, 1e10});
    //cmp.push_back({-1, -1});
    cin >> Q;
    IDX.resize(Q);
    X.resize(Q);
    for(int i = 0; i < Q; i++) {
      cin >> IDX[i] >> X[i];
      IDX[i]--;
      cmp.push_back({X[i], IDX[i]});
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    /*
    cerr << cmp.size() << endl;
    for(auto tmp : cmp) cerr << "{" << tmp.first << ", " << tmp.second << "} ";
    cerr << endl;
    */
    SegmentTree seg;
    int SIZE = cmp.size();
    /*
    Matrix tmp = f(p[0]);
    print(tmp);
    auto tmp2 = I();
    print(tmp2);
    auto tmp3 = tmp * tmp2;
    print(tmp3);
    */
    auto tmp = seg.getproduct(0, SIZE);
    cout << tmp[2][0] << "\n";
    for(int q = 0; q < Q; q++) {
        l_l tmp = {p[IDX[q]], IDX[q]};
        auto itr = lower_bound(cmp.begin(), cmp.end(), tmp);
        int idx = distance(cmp.begin(), itr);
        seg.update(idx, I());
        tmp.first = X[q];
        itr = lower_bound(cmp.begin(), cmp.end(), tmp);
        idx = distance(cmp.begin(), itr);
        seg.update(idx, f(X[q]));
        //Matrix tmp2 = seg.getproduct(0, SIZE);
        Matrix tmp2 = seg.node[0];
        cout << tmp2[2][0] << "\n";
        p[IDX[q]] = X[q];
    }
    return 0;
}