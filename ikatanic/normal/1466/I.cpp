#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

const int MAX = 222;

map<string, int> cache[MAX];

bool ask(int i, const string& s) {
  for (auto& p : cache[i]) {
    if (p.first >= s && p.second == 1) return true;
    if (p.first <= s && p.second == 0) return false;
  }

  cout << i + 1 << ' ' << s << '\n';
  cout.flush();
  string resp;
  cin >> resp;
  cache[i][s] = resp[0] == 'y';
  return resp[0] == 'y';
}

string go(vector<int> a, int b, string pref) {
  if (b == 0) return pref;

  auto gt = [&](int i, const string& cp) -> bool {
    string query = pref + cp + string(b - cp.size(), '1');
    return ask(i, query);
  };

  auto lte = [&](int i, const string& cp) -> bool {
    string query = pref + cp + string(b - cp.size(), '0');
    return !ask(i, query);
  };

  vector<int> v;
  string cpref;
  for (int i : a) {
    while (v.size() && gt(i, cpref)) {
      v.pop_back();
      cpref.pop_back();
    }
    if (cpref.size() == b) continue;

    if (gt(i, cpref + "0")) {
      cpref.push_back('1');
    } else {
      cpref.push_back('0');
    }
    v.push_back(i);
  }

  while (v.size()) {
    int nk = v.size();
    for (int i = (int)v.size() - 2; i >= 0; --i) {
      if (gt(v[i], cpref)) {
        nk = i + 1;
        break;
      }
    }
    if (v.size() == nk) break;
    v.resize(nk);
    cpref.resize(nk);
  }

  int k = v.size();
  return go(v, b - k, pref + cpref);
}

int main() {
  ios_base::sync_with_stdio(false);

  int n, b;
  cin >> n >> b;
  vector<int> v;
  for (int i = 0; i < n; ++i) v.push_back(i);
  auto ans = go(v, b, "");
  cout << "0 " << ans << "\n";
  return 0;
}