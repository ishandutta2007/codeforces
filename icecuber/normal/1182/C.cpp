#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int, multiset<string>> a;
  map<pair<int,char>, vector<string>> b;
  string vowel = "aeoiu";
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int vowels = 0;
    char last;
    for (char c : s) {
      for (char v : vowel) {
	if (c == v) last = c, vowels++;
      }
    }
    a[vowels].insert(s);
    b[{vowels, last}].push_back(s);
  }
  int pairs = 0;
  for (auto p : a)
    pairs += p.second.size()/2;
  vector<pair<string,string>> ans;
  for (auto p : b) {
    for (int i = 0; pairs > 1 && i+1 < p.second.size(); i += 2) {
      string sa = p.second[i];
      string sb = p.second[i+1];
      ans.push_back({sa,sb});
      auto&ai = a[p.first.first];
      ai.erase(ai.find(sa));
      ai.erase(ai.find(sb));
      pairs -= 2;
    }
  }
  vector<pair<string,string>> left;
  for (auto p : a) {
    int i = 0;
    pair<string,string> add;
    for (auto it : p.second) {
      (i%2 ? add.second : add.first) = it;
      if (i%2 == 1)
	left.push_back(add);
      i++;
    }
  }
  assert(left.size() >= ans.size());
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << left[i].first << ' ' << ans[i].first << endl;
    cout << left[i].second << ' ' << ans[i].second << endl;
  }
}