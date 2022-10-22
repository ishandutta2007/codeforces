#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int evens(string s) {
  int odd = 0, ret = 0;
  for (char c : s) {
    if (c == '1') odd ^= 1;
    else if (!odd) ret++;
  }
  return ret;
}

vector<array<int,2>> canon(string s, int k) {
  int ones = count(s.begin(), s.end(), '1');
  assert(ones >= k+1 && k);

  vector<array<int,2>> ans;
  int n = s.size();
  int even = evens(s), odd = n-ones-even;
  auto Add = [&](int l, int r) {
    ans.push_back({l,r});
    int in1 = 0;
    for (int i = l; i < r; i++)
      in1 += (s[i] == '1');
    reverse(s.begin()+l, s.begin()+r);
    assert(in1 == k);
  };

  while (1) {
    int last0 = n-1;
    while (s[last0] != '0') last0--;
    int l = last0, cp = k;
    for (; l >= 0; l--) {
      cp -= (s[l] == '1');
      if (!cp) break;
    }
    if (l < 0) break;
    Add(l, last0+1);
  }

  {
    //No 0 after first k 1s
    int sofar = 0;
    for (int i = 0; i < n; i++) {
      sofar += s[i] == '1';
      if (sofar >= k) assert(s[i] == '1');
    }
  }

  int side = 1;
  //int it = 0;
  while (1) {
//#warning it
    //if (it++ == 100) assert(0);
    //cout << s << ' ' << k << endl;
    //No 0 after first k%2+1 1s
    int sofar = 0, ok = 1, kp1 = -1, f2 = -1, f1 = -1;
    for (int i = 0; i < n; i++) {
      sofar += s[i] == '1';
      if (sofar != 0 && sofar != k+1 && s[i] == '0') ok = 0;
      if (kp1 == -1 && sofar == k+1) kp1 = i;
      if (f2 == -1 && sofar == 2) f2 = i;
      if (f1 == -1 && sofar == 1) f1 = i;
    }
    if (ok) break;

    if (side)
      Add(k%2 ? f2 : f1+1, kp1+1);
    else
      Add(f1, kp1);
    side ^= 1;
  }

  assert((int)ans.size() <= n*4);
  if (k%2)
    assert(s == string(n-ones, '0')+string(ones, '1'));
  else 
    assert(s == string(even, '0')+string(k+1, '1')+string(odd, '0')+string(ones-k-1, '1'));
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    assert((int)a.size() == n && (int)b.size() == n);

    //cout << n << ' ' << k << ' ' << a << ' ' << b << endl;
    auto Print = [&](vector<array<int,2>> path) {
      auto cp = a;
      cout << path.size() << endl;
      for (auto [l,r] : path) {
        int ones = 0;
        for (int i = l; i < r; i++) ones += (cp[i] == '1');
        cout << l+1 << ' ' << r << endl;
        reverse(cp.begin()+l, cp.begin()+r);
        assert(ones == k);
      }
      assert((int)path.size() <= n*4);
      assert(cp == b);
    };
    if (a == b) {
      Print({});
      continue;
    }
    int ca = count(a.begin(), a.end(), '1'); 
    if (ca != count(b.begin(), b.end(), '1') || k == 0 || k > ca || (k%2 == 0 && evens(a) != evens(b))) {
      cout << -1 << endl;
      continue;
    }
    assert(ca);

    if (k == ca) {
      auto pref0 = [](string s) {
        return find(s.begin(), s.end(), '1')-s.begin();
      };
      auto suf0 = [](string s) {
        int ret = 0;
        while (s.size() && s.back() == '0') s.pop_back(), ret++;
        return ret;
      };
      auto strip = [&](string s) {
        return s.substr(pref0(s), (int)s.size()-suf0(s)-pref0(s));
      };
      string reva = strip(a);
      reverse(reva.begin(), reva.end());
      int pa = pref0(a), pb = pref0(b), sa = suf0(a), sb = suf0(b);
      int right = max(0, sb-sa), left = max(0, pb-pa);
      if (strip(a) == strip(b)) {
        Print({{pa-right, n-sa+left}, {pb, n-sb}});
      } else if (reva == strip(b)) {
        Print({{pa-right, n-sa+left}});
      } else {
        cout << -1 << endl;
      }
      continue;
    }

    auto part1 = canon(a, k);
    auto part2 = canon(b, k);
    reverse(part2.begin(), part2.end());
    for (auto x : part2) part1.push_back(x);
    Print(part1);
  }
}