#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Problem {
  ll small_score, large_score, small_time, large_time, fail_prob;
  double cmp_val() {
    if (fail_prob == 1e6) return 1e30;
    return large_time*fail_prob*1./(1e6-fail_prob);
  }
};

bool operator<(Problem a, Problem b) {
  return a.cmp_val() < b.cmp_val();
}

#define score first
#define time second

void umax(pair<ll,double>&a, pair<ll,double> b) {
  if (b.score > a.score || b.score == a.score && b.time < a.time) {
    a = b;
  }
}

Problem p[1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, tot_time;
  cin >> n >> tot_time;
  for (int i = 0; i < n; i++) {
    double f;
    cin >> p[i].small_score >> p[i].large_score >> p[i].small_time >> p[i].large_time >> f;
    p[i].fail_prob = ll(f*1e6+0.5);
    p[i].small_score *= 1e6;
    p[i].large_score *= 1e6-p[i].fail_prob;
  }

  sort(p, p+n);

  vector<pair<ll,double>> dp(tot_time+1,{0,0});
  for (int i = 0; i < n; i++) {
    //Do nothing
    vector<pair<ll,double>> ndp = dp;

    // Do only small
    for (int j = 0; j+p[i].small_time <= tot_time; j++) {
      umax(ndp[j+p[i].small_time],
	   {dp[j].score+p[i].small_score,
	       dp[j].time+p[i].small_time});
    }

    // Do small + large
    int finish_time;
    for (int j = 0; (finish_time = j+p[i].small_time+p[i].large_time) <= tot_time; j++) {
      double f = p[i].fail_prob/1e6;
      double expect_time = (dp[j].time+p[i].small_time)*f + (1-f)*finish_time;
      umax(ndp[finish_time],
	   {dp[j].score+p[i].small_score+p[i].large_score,
	       expect_time});
    }

    swap(dp,ndp);
  }
  pair<ll,double> ans = dp[0];
  for (int j = 0; j <= tot_time; j++) {
    umax(ans, dp[j]);
  }
  cout << setprecision(20) << ans.first*1e-6 << ' ' << ans.second << endl;
}