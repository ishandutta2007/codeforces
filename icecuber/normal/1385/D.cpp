#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
map<tuple<int,int,char>, int> mem;

int f(int l, int r, char c) {
  if (r-l == 1) {
    return (s[l] != c);
  } else {
    int&memo = mem[{l,r,c}];
    if (!memo) {
      int m = (l+r)/2;
      int cost[2] = {};
      for (int i = l; i < r; i++)
	cost[i >= m] += (s[i] != c);
      memo = min(f(l, m, c+1)+cost[1], f(m, r, c+1)+cost[0])+1;
    }
    return memo-1;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n >> s;
    mem.clear();
    cout << f(0, n, 'a') << endl;
  }
}