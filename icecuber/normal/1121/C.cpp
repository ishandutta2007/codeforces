#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1001];
int worki[100], done[100];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < k; i++)
    worki[i] = 1000;

  int dones = 0, nexti = 0;
  set<int> ans;
  int moment = 0;
  while (dones < n) {
    int d = (200*dones+n)/(2*n);
    for (int i = 0; i < k; i++) {
      if (done[i] >= a[worki[i]]) {
	done[i] = 0;
	if (nexti < n)
	  worki[i] = nexti++;
	else
	  worki[i] = 1000;
      }

      if (done[i] < a[worki[i]]) {
	done[i]++;
	//if (moment == 74) cout << d << ' ' << done[i] << endl;
	if (done[i] == d) ans.insert(worki[i]);
      }
      if (worki[i] != 1000 && done[i] >= a[worki[i]])
	dones++;
    }
    moment++;
  }
  cout << ans.size() << endl;
}