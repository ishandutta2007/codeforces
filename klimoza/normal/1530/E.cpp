#include <math.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double) -1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
  cout << fixed; cout.precision(15);
  solve();
  return 0;
}

const int A = 26;
int cnt[A];

void solve() {
  int q; cin >> q;
  while(q--) {
    fill(cnt, cnt + A, 0);
    string s; cin >> s;
    int n = s.size();
    for(char c : s)
      cnt[c - 'a']++;
    bool fl = false;
    bool bl = false;
    vector<int> kek;
    for(int i = 0; i < A; i++) {
      if(cnt[i] == n)
        fl = true;
      if(cnt[i] == 1)
        bl = true;
      if(cnt[i])
        kek.push_back(i);
    }
    if(fl) {
      cout << s << endl;
    } else if(bl) {
      int mem = 0;
      for(int i = 0; i < A; i++) {
        if(cnt[i] == 1) {
          mem = i;
          break;
        }
      }
      cout << (char)(mem + 'a');
      cnt[mem]--;
      for(int i = 0; i < A; i++) {
        while(cnt[i]) {
          cout << (char)(i + 'a');
          cnt[i]--;
        }
      }
      cout << endl;
    } else if(2 * cnt[kek[0]] - 2 <= n) {
      int l = 1;
      cout << (char)(kek[0] + 'a') << (char)(kek[0] + 'a');
      cnt[kek[0]] -= 2;
      while(l < (int)(kek.size())) {
        cout << (char)(kek[l] + 'a');
        cnt[kek[l]]--;
        if(cnt[kek[0]]) {
          cout << (char)(kek[0] + 'a');
          cnt[kek[0]]--;
        }
        if(!cnt[kek[l]])
          l++;
      }
      cout << endl;
    } else if(kek.size() == 2) {
      cout << (char)(kek[0] + 'a');
      cnt[kek[0]]--;
      while(cnt[kek[1]]) {
        cout << (char) (kek[1] + 'a');
        cnt[kek[1]]--;
      }
      while(cnt[kek[0]]) {
        cout << (char)(kek[0] + 'a');
        cnt[kek[0]]--;
      }
      cout << endl;
    } else {
      cout << (char)(kek[0] + 'a');
      cnt[kek[0]]--;
      cout << (char)(kek[1] + 'a');
      cnt[kek[1]]--;
      while(cnt[kek[0]]) {
        cout << (char)(kek[0] + 'a');
        cnt[kek[0]]--;
      }
      cout << (char)(kek[2] + 'a');
      cnt[kek[2]]--;
      for(int c : kek) {
        while(cnt[c]) {
          cout << (char)(c + 'a');
          cnt[c]--;
        }
      }
      cout << endl;
    }
  }
}