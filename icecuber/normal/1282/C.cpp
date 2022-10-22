#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, T, a, b;
    cin >> n >> T >> a >> b;
    vector<pair<int,int>> task(n);
    int num[2] = {};
    for (int i = 0; i < n; i++) {
      cin >> task[i].second;
      num[task[i].second]++;
    }
    for (int i = 0; i < n; i++) {
      cin >> task[i].first;
    }
    task.push_back({T+1,0});
    sort(task.begin(), task.end());
    int best = 0;
    int need[2] = {};
    for (int i = 0; i <= n; i++) {
      int t = task[i].first-1;
      ll left = t - ((ll)a * need[0] + (ll)b * need[1]);
      if (left >= 0) {
	int score = need[0]+need[1];
	int doa = min((int)left/a, num[0]-need[0]);
	left -= doa*a;
	int dob = min((int)left/b, num[1]-need[1]);
	score += doa + dob;
	best = max(best, score);
      }
      need[task[i].second]++;
    }
    cout << best << '\n';
  }
}