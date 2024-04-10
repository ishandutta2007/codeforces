#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define For(i,n) for (int i = 0; i < (n); i++)

ll mod = 998244353;
string s;

ll solve1(ll p, ll q) {
  static ll dp[110][10][10][2][2][2];
  if (!(p <= q)) swap(p,q);
  int n = s.size();
  //dp[i][cp][cq][more][hasp][hasq] = number of ways up to digit i with carry cp and cq
  For(i,n+1) For(cp,9) For(cq,9) For(more,2) For(hasp,2) For(hasq,2)
    dp[i][cp][cq][more][hasp][hasq] = 0;
  dp[0][0][0][0][0][0] = 1;
  For(i,n) For(cp,9) For(cq,9) For(more,2) For(hasp,2) For(hasq,2) {
    ll&cur = dp[i][cp][cq][more][hasp][hasq];

    int ni = s[n-1-i]-'0';
    For(d,10) {
      int np = cp+d*p;
      int nq = cq+d*q;
      int new_more = nq%10 > ni || nq%10 == ni && more;
      ll&nxt =
	dp[i+1]
	[np/10]
	[nq/10]
	[new_more]
	[hasp|(np%10==p)]
	[hasq|(nq%10==q)];

      nxt += cur;
      if (nxt >= mod)
	nxt -= mod;
    }
  }
  //cout << p << ' ' << q << ' ' << dp[n][0][0][0][1][1] << endl;
  return dp[n][0][0][0][1][1];
}

ll solve2(ll p, ll q) {
  if (!(p <= q)) swap(p,q);
  int n = s.size();

  //Carry bound
  int cps = p, cqs = q;

  set<int> trackp, trackq;
  for (int x = 1; x <= 9; x++) {
    for (int y = 1; y <= 9; y++) {
      if (x*q == y*p) {
	trackp.insert(x);
	trackq.insert(y);
      }
    }
  }

  //Number of digits to track
  int psz = trackp.size(), qsz = trackq.size();
  int p_map[10], q_map[10];
  fill_n(p_map, 10, -1);
  fill_n(q_map, 10, -1);

  int c = 0;
  for (int i : trackp) {
    p_map[i] = c++;
  }
  c = 0;
  for (int i : trackq) {
    q_map[i] = c++;
  }

  int dp[n+1][cps][cqs][2][1<<psz][1<<qsz];// = {};
  For(i,n+1) For(cp,cps) For(cq,cqs) For(more,2) For(pmask,1<<psz) For(qmask,1<<qsz) {
    dp[i][cp][cq][more][pmask][qmask] = 0;
  }
  dp[0][0][0][0][0][0] = 1;

  For(i,n) For(cp,cps) For(cq,cqs) For(more,2) For(pmask,1<<psz) For(qmask,1<<qsz) {
    int&cur = dp[i][cp][cq][more][pmask][qmask];
    if (!cur) continue;
    int ni = s[n-1-i]-'0';
    For(d,10) {
      int np = cp+d*p;
      int nq = cq+d*q;
      int new_cp = np/10;
      int new_cq = nq/10;
      np -= new_cp*10;
      nq -= new_cq*10;

      int new_more = nq > ni || nq == ni && more;
      int new_pmask = pmask;
      if (p_map[np] != -1) new_pmask |= 1<<p_map[np];
      int new_qmask = qmask;
      if (q_map[nq] != -1) new_qmask |= 1<<q_map[nq];

      int&nxt =
	dp[i+1]
	[new_cp]
	[new_cq]
	[new_more]
	[new_pmask]
	[new_qmask];

      nxt += cur;
      if (nxt >= mod)
	nxt -= mod;
    }
  }

  ll ans = 0;
  For(pmask,1<<psz) For(qmask,1<<qsz) {
    int ok = 0;
    for (int x = 1; x <= 9; x++) {
      for (int y = 1; y <= 9; y++) {
	if (p_map[x] != -1 && q_map[y] != -1 &&
	    x*q == y*p &&
	    (pmask>>p_map[x]&1) &&
	    (qmask>>q_map[y]&1)) ok = 1;
      }
    }
    if (ok)
      (ans += dp[n][0][0][0][pmask][qmask]) %= mod;
  }

  if (p != q) {
    ans = ans*2%mod;
  }
  return ans;
}

ll brute(ll p, ll q) {
  if (s.size() > 3) exit(0);
  ll n = stoi(s);
  ll ans = 0;
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      if (x*q == y*p) {
	string sx = to_string(x);
	string sy = to_string(y);
	int ok = 0;
	for (char a : sx)
	  for (char b : sy)
	    if (a != '0' && b != '0' && (a-'0')*q == (b-'0')*p)
	      ok = 1;
	  //if (x == p && y == q) continue;
	  //cout << x << '/' << y << " = " << p << '/' << q << endl;
	//if (p == 1 && q == 1 && ok) cout << '(' << x << '/' << y << ')';
	ans += ok;
      }
    }
  }
  if (p != q) {
    ans = ans*2%mod;
  }
  return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  ll ans = 0;
  for (int p = 1; p < 10; p++) {
    for (int q = p; q < 10; q++) {
      if (__gcd(p,q) == 1) {
	/*if (brute(p,q) != solve2(p,q)) {
	  cout << p << ' ' << q << endl;
	  cout << brute(p,q) << ' ' << solve2(p,q) << endl;
	  cout << endl;
	  }*/
	//(ans += brute(p,q)) %= mod;
	(ans += solve2(p,q)) %= mod;
      }
    }
  }
  cout << ans << endl;
}