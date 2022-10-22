#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Fenwick {
  int data[2001];
  void clear() {
    fill_n(data, 2001, 0);
  }
  int add(int i, int v) {
    for (; i <= 2000; i+=i&-i) data[i] += v;
  }
  int sum(int i) {
    int r = 0;
    for (; i; i-=i&-i) r += data[i];
    return r;
  }
  int get(int i) {
    return sum(i)-sum(i-1);
  }
};

ll mod = 998244353;

ll a[2000], b[2000];
ll fac[2001], cnt[2001][2001];
ll basepow[2001];

ll dp[2001][2001];
ll dp2[2001][2001];

Fenwick fa, fb;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  cnt[0][0] = 1;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    cnt[i][0] = 1;
    for (int j = 1; j <= n; j++) {
      cnt[i][j] = cnt[i-1][j-1]+cnt[i-1][j];
      if (cnt[i][j] >= mod) cnt[i][j] -= mod;
    }
    fac[i] = fac[i-1]*i%mod;
  }

  ll base = 0;
  for (int i = 0; i <= n; i++)
    base = (base+(i%2?-1:1)*cnt[n][i]*fac[n-i])%mod;
  basepow[0] = 1;
  for (int i = 1; i < n; i++)
    basepow[i] = basepow[i-1]*base%mod;

  base = (base+mod)%mod;
  /*(for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++) {
      dp[i][j] = 0;
      for (int k = 0; k <= j; k++)
	dp[i][j] = (dp[i][j]+(k%2?-1:1)*cnt[j][k]*fac[i-k])%mod;
	}*/
  for (int i = 1; i <= n; i++) {
    dp2[i][0] = fac[i];
    for (int j = 1; j <= i; j++) {
      dp2[i][j] = (dp2[i][j]+(j>=2?dp2[i-1][j-2]*(j-1):0)+(j<i?(i-j)*dp2[i-1][j-1]:0))%mod;
      //cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << dp2[i][j] << endl;
      //assert(dp2[i][j] == dp[i][j]);
    }
  }
  assert(base==dp2[n][n]);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll y = 0;
    //set<int> leftb, lefta;
    set<int> toleft;
    fa.clear(), fb.clear();
    for (int j = 0; j < n; j++) {
      cin >> a[j];
      ll a0l = 0, a0r = 0;
      /*for (int k = 1; k < a[j]; k++)
	if (!lefta.count(k) && k != b[j]) {
	  if (leftb.count(k)) a0l++;
	  else a0r++;
	  }*/
      int ar;
      {
	int rem = i && !fb.get(b[j]);
	if (rem) fb.add(b[j],1);
	ar = a[j]-1-fb.sum(a[j]-1);
	//assert(a0l+a0r == a[j]-1-fb.sum(a[j]-1));
	if (rem) fb.add(b[j],-1);
	fb.add(a[j],1);
      }
      {
	int rem = i && !fa.get(b[j]);
	if (rem) fa.add(b[j],1);
	a0r = a[j]-1-fa.sum(a[j]-1);
	a0l = ar-a0r;
	//assert(a0r == a[j]-1-fa.sum(a[j]-1));
	if (rem) fa.add(b[j],-1);
	if (!fa.get(a[j])) fa.add(a[j],1);
	if (i && !fa.get(b[j])) fa.add(b[j],1);
      }

      //ll overlap = 0;
      //for (int i = 1; i <= n; i++)
      //if (!lefta.count(i) && !leftb.count(i) && i != b[j]) overlap++;
      toleft.insert(b[j]);
      int overlap = n-toleft.size();
      if (i == 0) overlap = 0, swap(a0r,a0l);
      y = (y+a0l*dp2[n-j-1][overlap]+(overlap ? a0r*dp2[n-j-1][overlap-1] : 0))%mod;
      //y = (y+(a[j]-1-sum(a[j]))*fac[n-1-j])%mod;
      //add(a[j],1);
      toleft.insert(a[j]);
      //lefta.insert(a[j]);
      //leftb.insert(b[j]);
      b[j] = a[j];
    }
    ans = (ans+basepow[n-1-i]*y)%mod;
  }
  cout << (ans+mod)%mod << endl;
}