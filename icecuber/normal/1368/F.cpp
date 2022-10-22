#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int best = 0, bestk = 1;
  for (int k = 1; k <= n; k++) {
    int score = n-(n+k-1)/k-(k-1);
    if (score > best) {
      best = score;
      bestk = k;
    }
  }
  {
    int k = bestk;
    vector<int> target;
    for (int i = 0; i < n; i++) {
      target.push_back(!(i%k == k-1 || i == n-1));
    }
    //cout << count(target.begin(), target.end(), 1) << ' ' << best+k-1 << endl;
    //assert(count(target.begin(), target.end(), 1) == best+k-1);
    //for (int i : target) cout << i;
    //cout << endl;
    vector<int> cur(n);
    while (count(cur.begin(), cur.end(), 1) < best) {
      set<int> s;
      for (int i = 0; i < n; i++) {
	if ((int)s.size() < k && target[i] && !cur[i])
	  s.insert(i);
      }
      {
	int j = 0;
	while ((int)s.size() < k)
	  s.insert(j++);
      }
      for (int i : s) cur[i] = 1;

      cout << k;
      for (int i : s) cout << ' ' << i+1;
      cout << endl;

      int ans;
      cin >> ans;
      if (ans == -1) return 0;
      ans--;
      for (int i = 0; i < k; i++)
	cur[(ans+i)%n] = 0;
    }
    cout << 0 << endl;
  }
}