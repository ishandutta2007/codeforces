#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int,int> pos[200001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<int> left, right;
  int q;
  cin >> q;
  while (q--) {
    char cmd;
    int id;
    cin >> cmd >> id;
    if (cmd == 'L') {
      pos[id] = {0,left.size()};
      left.push_back(id);
    } else if (cmd == 'R') {
      pos[id] = {1,right.size()};
      right.push_back(id);
    } else {
      if (pos[id].first == 0) {
	cout << min(left.size()-1-pos[id].second, pos[id].second+right.size()) << endl;
      } else
	cout << min(right.size()-1-pos[id].second, pos[id].second+left.size()) << endl;
    }
  }
}