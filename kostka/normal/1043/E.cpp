//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef LOCAL
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<" = "<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<" = "<<h<<", "; _dbg(sdbg+1, a...);
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#define cerr if(false) cout
#endif

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

struct person {
  int a, b, id;
  person(int _a = 0, int _b = 0, int _id = 0) : a(_a), b(_b), id(_id) {}
  bool operator<(const person& other) {
    return a-b < other.a - other.b;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector <person> X;
  for(int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    X.emplace_back(person(b, a, i));
  }
  sort(ALL(X));
  vector <ll> A, B;
  for(int i=0; i<n; i++) A.push_back(X[i].a);
  for(int i=0; i<n; i++) B.push_back(X[i].b);
  partial_sum(ALL(A), A.begin());
  reverse(ALL(B));
  partial_sum(ALL(B), B.begin());
  reverse(ALL(B));
  vector <ll> res(n);
  for(int i=0; i<n; i++) {
    int id = X[i].id;
    res[id] += (1LL * X[i].b * i);
    res[id] += (1LL * X[i].a * (n-i-1));
    res[id] += (i == 0 ? 0 : A[i-1]);
    res[id] += (i+1 == n ? 0 : B[i+1]);
  }
  sort(X.begin(), X.end(), [](const person& a, const person& b) {
    return a.id < b.id;
  });
  while(m--) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    // why min ffs
    int score = min(X[a].a + X[b].b, X[a].b + X[b].a);
    res[a] -= score;
    res[b] -= score;
  }
  for(int i=0; i<n; i++) cout << res[i] << " ";
  cout << "\n";
  return 0;
}