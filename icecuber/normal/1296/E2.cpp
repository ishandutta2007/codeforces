#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<char, vector<int>>> lis;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    char best = 0;
    int besti = -1;
    for (int j = 0; j < (int)lis.size(); j++) {
      char d = lis[j].first;
      if (c >= d && d > best) {
	best = d;
	besti = j;
      }
      //cout << d;
    }
    //cout << endl;
    if (besti == -1) {
      lis.push_back({c, {i}});
    } else {
      lis[besti].first = c;
      lis[besti].second.push_back(i);
    }
  }
  cout << lis.size() << endl;
  vector<int> col(n);
  for (int j = 0; j < (int)lis.size(); j++) {
    auto&[c,v] = lis[j];
    for (int i : v) col[i] = j+1;
  }
  for (int i : col) cout << i << ' ';
  cout << endl;
}