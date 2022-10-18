#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
typedef pair<llint, llint> par;
#define len first
#define cnt second

vector<par> V;

void split(llint len) {
  V.clear();
  if (len == 0) return;

  V.push_back({len+1, 0});
  V.push_back({len, 1});
  
  for (int i = 0; i < (int)V.size(); i += 2) {
    assert(V[i].len == V[i+1].len + 1);

    llint next_len1 = V[i].len / 2, next_cnt1 = V[i].cnt;
    llint next_len2 = (V[i+1].len-1) / 2, next_cnt2 = V[i+1].cnt;
    
    V[i+1].len/2 == next_len1 ? next_cnt1 += V[i+1].cnt : next_cnt2 += V[i+1].cnt;
    (V[i].len-1)/2 == next_len1 ? next_cnt1 += V[i].cnt : next_cnt2 += V[i].cnt;
    
    if (next_len1 == 0 && next_len2 == 0) break;
    V.push_back({next_len1, next_cnt1});
    V.push_back({next_len2, next_cnt2});
  }
  
  while (V.size() && V.back().first == 0) V.pop_back();
  llint cnt1 = 0;
  while (V.size() && V.back().first == 1) {
    cnt1 += V.back().cnt;
    V.pop_back();
  }
  if (cnt1 > 0) V.push_back({1, cnt1});
}


llint countGaps(llint n, llint d) {
  split(n);
  llint ret = 0;
  for (auto& p: V) {
    if (p.len > 0 && (p.len - 1) / 2 >= d) ret += p.cnt;
  }
  return ret;
}

llint solve(llint l, llint r, llint d, llint k) {
  llint m = (l + r - 1) / 2;
  if (k == 1) {
    return m;
  }
  --k;
  
  llint left = countGaps(m - l, d);
  llint right = countGaps(r - m - 1, d + 1);

  if (left + right >= k) {
    return solve(l, m, d, k - right);
  } else {
    return solve(m+1, r, d, k - left);
  }
}

int main(void) {
  llint k, n;
  scanf("%lld %lld", &n, &k);

  if (k == 1) {
    printf("%lld\n", 1LL);
    return 0;
  }
  if (k == 2) {
    printf("%lld\n", n);
    return 0;
  }
  
  n -= 2;
  k -= 2;

  llint lo = 0, hi = n;
  while (lo < hi) {
    llint mid = (lo + hi + 1) / 2;
    if (countGaps(n, mid) < k) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
  
  printf("%lld\n", solve(0, n, lo, k) + 2);
  return 0;
}