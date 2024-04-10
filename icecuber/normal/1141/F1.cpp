#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Segment {
  int s, e;
};
bool operator<(Segment a, Segment b) {
  return a.e < b.e;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> acc(n+1);
  map<int,vector<Segment>> segments;
  for (int i = 1; i <= n; i++) {
    int d;
    cin >> d;
    acc[i] = acc[i-1]+d;
    for (int j = 0; j < i; j++)
      segments[acc[i]-acc[j]].push_back({j, i});
  }
  vector<Segment> ans;
  for (auto&p : segments) {
    vector<Segment>& seg = p.second;
    sort(seg.begin(), seg.end());
    vector<Segment> subset;
    int last = -1e9;
    for (Segment&s : seg) {
      if (s.s >= last) {
	subset.push_back(s);
	last = s.e;
      }
    }
    if (subset.size() > ans.size())
      ans = subset;
  }
  cout << ans.size() << endl;
  for (Segment s : ans)
    cout << s.s+1 << ' ' << s.e << endl;
}