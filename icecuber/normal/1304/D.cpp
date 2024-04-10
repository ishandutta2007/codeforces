#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    {
      vector<int> mi = {1};
      for (char c : s) {
	if (c == '<') mi.back()++;
	else mi.push_back(1);
      }
      vector<int> path;
      int x = n;
      for (int v : mi) {
	x -= v;
	for (int i = 0; i < v; i++)
	  path.push_back(++x);
	x -= v;
      }
      for (int v : path) cout << v << ' ';
      cout << endl;
    }
    {
      reverse(s.begin(), s.end());
      vector<int> mi = {1};
      for (char c : s) {
	if (c == '>') mi.back()++;
	else mi.push_back(1);
      }
      vector<int> path;
      int x = n;
      for (int v : mi) {
	x -= v;
	for (int i = 0; i < v; i++)
	  path.push_back(++x);
	x -= v;
      }
      reverse(path.begin(), path.end());
      for (int v : path) cout << v << ' ';
      cout << endl;
    }
  }
}