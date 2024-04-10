#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  map<string,vector<string>> entry;
  for (int i = 0; i < n; i++) {
    string name;
    int k;
    cin >> name >> k;
    for (int j = 0; j < k; j++) {
      string number;
      cin >> number;
      entry[name].push_back(number);
    }
  }
  cout << entry.size() << endl;
  for (auto p : entry) {
    cout << p.first << ' ';
    set<string> unique;
    for (string a : p.second) {
      int found = 0;
      for (string b : p.second) {
	if (b.size() > a.size() && b.substr(b.size()-a.size(),a.size()) == a)
	  found = 1;
      }
      if (!found) unique.insert(a);
    }
    cout << unique.size();
    for (string s : unique) {
      cout << ' ' << s;
    }
	cout << endl;
  }
}