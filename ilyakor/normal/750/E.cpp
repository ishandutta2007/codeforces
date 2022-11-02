#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

using namespace std;
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

const bool DEBUG = false;

typedef long long int64;

const char BAD[] = "2016";
const int BASE = 10;
const int OMAX = 4 * 200 * 1000;

int calculated = 0;
int num_calls = 0;

class CalcDigits {
 public:
  CalcDigits(){}

  void reset(const string& ss) {
    s = ss;
    n = s.size();
    for (int i = 0; i < BASE; ++i) {
      cnt[i].clear();
      cnt[i].resize(n + 1, 0);
      prev[i].clear();
      prev[i].resize(n + 1, -1);
    }
    for (int i = 0; i < s.size(); ++i) {
      cnt[s[i] - '0'][i + 1] += 1;
      prev[s[i] - '0'][i + 1] = i;
    }
    for (int i = 0; i < BASE; ++i) for (int j = 1; j <= n; ++j) {
      cnt[i][j] = cnt[i][j] + cnt[i][j - 1];
      if (prev[i][j] == -1) prev[i][j] = prev[i][j - 1];
    }
  }

  

  int count(int digit, int from, int to) {
    //int ans = 0;
    //for (int i = from; i < to; ++i) if (s[i] - '0' == digit) ++ans;
    // return ans;
    return cnt[digit][to] - cnt[digit][from];
  }

  int last(int digit, int from, int to) {
    //int ans = -1;
    //for (int i = from; i < to; ++i) if (s[i] - '0' == digit) ans = i;
    //return ans;
    int p = prev[digit][to];
    if (p == -1 || p < from) return -1;
    return p;
  }

  int n;
  string s;
  vector<int> cnt[BASE];
  vector<int> prev[BASE];
};



int BUBEN = 1;

class CalcSubstrings {
 public:
  void reset(const string& ss) {
    s = ss;
    digits.reset(s);
    n = s.size();
    for (int z = 0; z < OMAX; ++z) 
    for (int from = 0; from <= 3; ++from) for (int to = from; to <= 3; ++to) {
      a[z][from * 4 + to] = -10;
    }
  }

  int calc(int from, int to) {
    ++BUBEN;
    return calc(0, 0, n, 
      0, 3, // indices of "2016"
      from, to);
  }
  
  // n, cur_from, cur_to - current vertex in segment tree
  // [find_first, find_last] - which digits are we looking for (find_last should NOT be present). E.g. [0,3] corresponds to "201 but not 2016".
  // from, to - indices in string.
  int calc(int n, int cur_from, int cur_to, int find_first, int find_last, int from, int to) {
    if (from < cur_from) from = cur_from;
    if (to > cur_to) to = cur_to;
    if (from >= to) {
      return (find_first == find_last ? 0 : -1);
    }
    if (cur_from == cur_to - 1) {
      if (find_first == find_last) return (BAD[find_first] == s[from] ? 1 : 0);
      if (find_first == find_last - 1) return (BAD[find_first] == s[from] ? 0 : -1);
      return -1;
    }


    if (find_first == find_last) {
      // only constraint is for digit to not be there.
      int bad_digit = BAD[find_first] - '0';
      int ans = digits.count(bad_digit, from, to);
//      b[n][find_first * 4 + find_last] = ans;
      return ans;
    }

    
    if (a[n][find_first * 4 + find_last] == -10) {
      calculated += 1;
      int ans = -1;
      int mid = (cur_from + cur_to) / 2;
      for (int first_missing_digit_in_left_part = find_first; first_missing_digit_in_left_part <= find_last; ++first_missing_digit_in_left_part) {
        int x = calc(n * 2 + 1, cur_from, mid, find_first, first_missing_digit_in_left_part, cur_from, mid);
        if (x == -1) continue;
        int y = calc(n * 2 + 2, mid, cur_to, first_missing_digit_in_left_part, find_last, mid, cur_to);
        if (x == -1 || y == -1) continue;
        int z = x + y;
        if (ans == -1 || ans > z) ans = z;
      }
      a[n][find_first * 4 + find_last] = ans;
    }

    if (cur_from == from && cur_to == to) {
//      b[n][find_first * 4 + find_last] = a[n][find_first * 4 + find_last];
      return a[n][find_first * 4 + find_last];
    }

    if (c[n][find_first * 4 + find_last] == BUBEN) {
      return b[n][find_first * 4 + find_last];
    }
    c[n][find_first * 4 + find_last] = BUBEN;


    ++num_calls;
    //cerr << "Call: " << find_first << " " << find_last << " " << cur_from << " " << cur_to << "\n";

    // Multiple digits, should split.
    int ans = -1;
    int mid = (cur_from + cur_to) / 2; // left is [cur_from, mid), right is [mid, cur_to)
    for (int first_missing_digit_in_left_part = find_first; first_missing_digit_in_left_part <= find_last; ++first_missing_digit_in_left_part) {
      int x = calc(n * 2 + 1, cur_from, mid, find_first, first_missing_digit_in_left_part, from, to);
      if (x == -1) continue;
      int y = calc(n * 2 + 2, mid, cur_to, first_missing_digit_in_left_part, find_last, from, to);
      if (y == -1) continue;
      int z = x + y;
      if (ans == -1 || ans > z) ans = z;
    }
    b[n][find_first * 4 + find_last] = ans;

    return ans;
  }

  string s;
  int n;
  CalcDigits digits;
  int a[OMAX][16];
  int b[OMAX][16];
  int c[OMAX][16];
};

CalcSubstrings precalc; 

void solve(int test_num) {
  int n, q;
  scanf("%d%d", &n, &q);
  string s;
  while (s.size() == 0) {
    getline(cin, s);
  }
  precalc.reset(s);
  for (int i = 0; i < q; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; // do not decrease b since we want [a, b) as an interval.
    int last_7 = precalc.digits.last(7, a, b);
    if (last_7 == -1) {
      printf("-1\n");
    } else {
      int was = num_calls;
      //cerr << "Call\n";
      int t1 = precalc.calc(a, last_7);
      int total = num_calls - was;
      //assert(total < 120);
      int t2 = precalc.digits.count(6, last_7, b);
      if (t1 == -1) {
        printf("-1\n");
      } else {
        printf("%d\n", t1 + t2);
      }
    }
  }
  // cout << s << endl;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int i = 0; i < t; ++i) solve(i);
//  cerr << "Num calls: " << num_calls << "\n";
  return 0;
}