#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> h(n), a, b;
  int m = 0;
  for (int&v : h) {
    cin >> v;
    m += v;
  }
  for (int i = 0; i < n; i++) {
    int good;
    cin >> good;
    if (good) b.push_back(h[i]);
    else a.push_back(h[i]);
  }
  sort(b.begin(), b.end());

  int goods = b.size();
  int pass = 0, fail = goods+1;
  for (int v : a) b.push_back(v);

  while (fail-pass > 1) {
    int mid = pass+fail>>1;
    map<int,int> cnt, good;
    for (int i = mid-1; i < n; i++) {
      ++cnt[b[i]];
      if (i < goods)
	good[b[i]] = 1;
    }
    vector<int> dp1(m+1), dp2(m+1);
    dp1[0] = 1;
    for (auto [w,c] : cnt) {
      c++;
      for (int i = w; i <= m; i++) {
	dp1[i] += dp1[i-w];
	dp2[i] += dp2[i-w];
      }
      vector<int> ndp1(m+1), ndp2(m+1);
      if (good[w]) {
	for (int i = 0; i <= m; i++) {
	  ndp1[i] = (dp1[i]-(i-w*c >= 0 ? dp1[i-w*c] : 0) > 0);
	  ndp2[i] = (dp2[i]-(i-w*c >= 0 ? dp2[i-w*c] : 0) > 0);
	  ndp2[i]|= ((i >= w ? dp1[i-w] : 0)-(i-w*c >= 0 ? dp1[i-w*c] : 0) > 0);
	}
      } else {
	for (int i = 0; i <= m; i++) {
	  ndp1[i] = (dp1[i]-(i-w*c >= 0 ? dp1[i-w*c] : 0) > 0);
	  ndp2[i] = (dp2[i]-(i-w*c >= 0 ? dp2[i-w*c] : 0) > 0);
	}
      }
      swap(dp1, ndp1);
      swap(dp2, ndp2);
    }


    int nw = 0;
    for (int i = 0; i < mid-1; i++)
      nw += b[i];

    int ok = 0;
    for (int i = 0; i <= m; i++) {
      if (i-nw >= l && i <= r && dp2[m-i]) ok = 1;
    }
    if (ok) pass = mid;
    else fail = mid;
  }
  cout << pass << endl;
}