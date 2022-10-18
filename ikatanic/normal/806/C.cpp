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

const int B = 50;

bool can(vector<pair<int, int>>& seqs, int K) {
  vector<int> remove;
  REP(i, K) {
    int idx = (int)seqs.size() - i - 1;
    REP(j, seqs[idx].first - seqs[idx].second + 1) {
      remove.push_back(j);
    }
    if (seqs[idx].second) remove.push_back(seqs[idx].first - seqs[idx].second);
  }

  sort(remove.begin(), remove.end());
  REP(i, (int)seqs.size() - K) {
    if (seqs[i].second == 0) {
      if (remove.size()) {
        if (remove.back() > seqs[i].first) return false;
        remove.pop_back();
      }
    }
  }
  return remove.size() == 0;
}

int main(void) {
  int n;
  scanf("%d", &n);

  vector<int> pw(B, 0);
  vector<llint> v;
  REP(i, n) {
    llint x;
    scanf("%lld", &x);

    if ((x & (x-1)) == 0) {
      int j = 0;
      while (x > 1) x /= 2, j++;
      pw[j]++;
    } else {
      v.push_back(x);
    }
  }

  vector<pair<int, int>> seqs;
  for (int i = B-1; i >= 0; --i) {
    while (pw[i] > 0) {
      bool ok = true;
      REP(j, i+1) {
        ok &= pw[j] > 0;
      }

      if (!ok) {
        v.push_back(1LL<<i);
        pw[i]--;
      } else {
        REP(j, i+1) pw[j]--;
        seqs.push_back({i, 0});
      }
    }
  }


  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  for (int i = (int)seqs.size() - 1; i >= 0; --i) {
    if (v.size() && v.back() < (1LL << (seqs[i].first + 1))) {
      seqs[i].first++;
      seqs[i].second = 1;
      v.pop_back();
    }
  }

  if (v.size() > 0) {
    puts("-1");
    return 0;
  }

  int R = seqs.size();
  sort(seqs.begin(), seqs.end(), [&] (const pair<int, int>& a, const pair<int, int>&b) {
      if (a.first != b.first) return a.first > b.first;
      return a.second < b.second;
    });


    
  int lo = 0, hi = R;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (can(seqs, mid)) lo = mid;
    else hi = mid-1;
  }

  int L = R - lo;
  for (int i = L; i <= R; ++i) {
    printf("%d ", i);
  }
  printf("\n");
  return 0;
}