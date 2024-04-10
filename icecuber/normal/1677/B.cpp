#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int h, w;
    cin >> h >> w;
    string s;
    cin >> s;
    vector<int> acc(w*h+1);
    for (int i = 0; i < w*h; i++)
      acc[i+1] = acc[i]+(s[i]=='1');

    vector<int> ans(w*h);
    for (int j = 1; j <= w; j++) {
      ans[j-1] = !!(acc[j]-acc[0]);
      for (int i = 1; i < h; i++) {
        ans[j-1+i*w] = ans[j-1+(i-1)*w]+!!(acc[j+i*w]-acc[j+(i-1)*w]);
      }
    }

    vector<int> col(w);
    int sum = 0;
    for (int i = 0; i < w*h; i++) {
      if (s[i] == '1') {
        sum += !(col[i%w]++);
      }
      ans[i] += sum;
    }

    for (int v : ans) cout << v << ' ';
    cout << endl;
  }
}