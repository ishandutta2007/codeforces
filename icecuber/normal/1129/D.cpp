#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;
ll dp[101001];

int uniques[101001];

void add_self(ll&a, ll b) {
  a += b;
  if (a >= mod)
    a -= mod;
}
int K;
const int B = 100;
struct Bucket {
  int uniques[B];
  ll pref[B];
  int off;
  int li;
  Bucket() {
    off = 0;
    fill_n(uniques, B, 0);
    fill_n(pref, B, 0);
  }
  void add(int a, int b, int v) {
    if (a <= 0 && b >= B) {
      off += v;
      return;
    } else if (a >= B || b <= 0) return;
    for (int i = max(a, 0); i < min(b, B); i++)
      uniques[i] += v;
    recalc();
  }
  void recalc() {
    int mi = uniques[0];
    for (int i = 0; i < B; i++) {
      mi = min(mi, uniques[i]);
      pref[i] = 0;
    }
    off += mi;
    for (int i = 0; i < B; i++) {
      uniques[i] -= mi;
      add_self(pref[uniques[i]],  dp[li+i]);
    }
    for (int i = 1; i < B; i++)
      add_self(pref[i], pref[i-1]);
  }
  ll query(int n) {
    if (n >= B) {
      if (K < off) return 0;
      else if (K >= off+B-1) return pref[B-1];
      return pref[K-off];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
      if (uniques[i]+off <= K)
	add_self(ans, dp[li+i]);
    return ans;
  }
};

const int buckets = 100000/B+2;
Bucket bucket[buckets];

void add(int a, int b, int v) {
  for (int i = 0; i < buckets; i++)
    bucket[i].add(a-i*B, b-i*B, v);
}
ll query(int n) {
  ll ans = 0;
  for (int i = 0; i < buckets; i++)
    ans = (ans+bucket[i].query(n-i*B))%mod;
  return ans;
}


void add2(int a, int b, int v) {
  for (int i = a; i < b; i++)
    uniques[i] += v;
}
ll query2(int n) {
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (uniques[i] <= K) {
      ans += dp[i];
      if (ans >= mod) ans -= mod;
    }
  }
  return ans;
}



int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < buckets; i++)
    bucket[i].li = i*B;
  int n;
  cin >> n >> K;
  vector<int> a(n);
  vector<int> last(n+1, -1), second(n+1, -1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int li = last[a[i]];
    if (li != -1)
      add(second[a[i]]+1, last[a[i]]+1, -1);
    second[a[i]] = last[a[i]];
    last[a[i]] = i;
    add(second[a[i]]+1, last[a[i]]+1, 1);
    bucket[i/B].recalc();
    dp[i+1] = query(i+1)%mod;
  }
  cout << dp[n] << endl;
}