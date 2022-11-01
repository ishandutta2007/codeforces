#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
typedef pair<int, int> P;
template <class T>
class RMQ{
  int N;
  vector<T> data;
  vector<int> segtree;
  bool compare(const T& a, const T& b){
    return a > b;
    // return a > b; // greater
    // return a.second <= b.second; // pair
    // return a.size() <= b.size() // string, array, ...
    // return abs(a) <= abs(b) // complex
  }
  int build(int idx, int left, int right){
    if(left + 1 == right){
      segtree[idx] = left;
    }else{
      const int mid = (left + right) / 2;
      int left_idx = build(idx * 2 + 1, left, mid);
      int right_idx = build(idx * 2 + 2, mid, right);
      if(compare(data[left_idx], data[right_idx])){
        segtree[idx] = left_idx;
      }else{
        segtree[idx] = right_idx;
      }
    }
    return segtree[idx];
  }
  int update_build(int k, int idx, int left, int right){
    if(!(left <= k && k < right)){
      //do nothing!
    } else if(left + 1 == right){
      segtree[idx] = left;
    }else{
      const int mid = (left + right) / 2;
      int left_idx = update_build(k, idx * 2 + 1, left, mid);
      int right_idx = update_build(k, idx * 2 + 2, mid, right);
      if(compare(data[left_idx], data[right_idx])){
        segtree[idx] = left_idx;
      }else{
        segtree[idx] = right_idx;
      }
    }
    return segtree[idx];
  }
public:
  RMQ(int N){
    data = vector<T>(N);
    this->N = data.size();
    segtree = vector<int>(4 * N, -1);
    build(0, 0, N);
  }
  RMQ(const vector<T>& v){
    data = vector<T>(v.begin(), v.end());
    N = data.size();
    segtree = vector<int>(4 * N, -1);
    build(0, 0, N);
  }

  T operator[](const int idx) const {
    return data[idx];
  }

  void update(int k, T a){
    data[k] = a;
    update_build(k, 0, 0, N);
  }

  inline int query_index(int left, int right) { return query_index(left, right, 0, 0, N); }
  int query_index(int left, int right, int i, int a, int b) {
    // [a, b) is the range of indexes[i]
    if (b <= left || right <= a) {
      // does not intersect
      return -1;
    } else if (left <= a && b <= right) {
      // contains
      return segtree[i];
    } else {
      const int m = (a+b)/2;
      const int l = query_index(left, right, 2*i+1, a, m);
      const int r = query_index(left, right, 2*i+2, m, b);
      if (l == -1) {
        return r;
      } else if (r == -1) {
        return l;
      } else {
        if(compare(data[l], data[r])){
          return l;
        } else {
          return r;
        }
      }
    }
  }
  inline T query_value(int left, int right) { return data[query_index(left, right)]; }

};

int main(){
  int N;
  while(cin>>N){
    vector<int> v(N);
    vector<int> m_idx(N);
    REP(i, N) cin >> v[i];
    vector<P> ps(N);
    REP(i, N) ps[i] = P(-v[i], i);
    sort(ps.begin(), ps.end());
    REP(i, N) m_idx[i] = ps[i].second;
    vector<int> used;
    used.push_back(-1);
    used.push_back(N);
    int ans = 0;
    RMQ<int> rmq(v);
    REP(i, N){
      if(ans > ((-ps[i].first) << 1)) break;
      int M = m_idx[i];
      //printf("take %d(i = %d)\n", v[M], M);
      int ui = lower_bound(used.begin(), used.end(), M) - used.begin();
      int L = used[ui - 1] + 1, R = used[ui] - 1; // [L, R]
      //printf("\tRange: [%d, %d]\n", L, R);
      while(L < M){
        int NL = rmq.query_index(L, M); // [L, M)
        //printf("\tL %d(i = %d)\n", v[NL], NL);
        ans = max(ans, v[M] ^ v[NL]);
        L = NL + 1;
      }
      while(R > M){
        int NR = rmq.query_index(M + 1, R + 1); // [M + 1, R + 1) = (M, R]
        //printf("\tR %d(i = %d)\n", v[NR], NR);
        ans = max(ans, v[M] ^ v[NR]);
        R = NR - 1;
      }
      used.insert(lower_bound(used.begin(), used.end(), M), M);
    }
    cout << ans << endl;
  }
  return 0;
}