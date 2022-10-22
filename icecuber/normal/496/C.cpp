#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s[100];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    cin >> s[i];
  int ans = 0;
  for (int j = 0; j < s[0].size(); j++) {
    int ok = 1;
    for (int i = 1; i < h; i++)
      if (s[i-1].substr(0,j+1) > s[i].substr(0,j+1)) ok = 0;
    if (!ok) {
      ans++;
      for (int i = 0; i < h; i++)
	s[i] = s[i].substr(0,j)+s[i].substr(j+1,max(int(s[i].size()-j-1),0));
      j--;
    }
  }
  cout << ans << endl;
}