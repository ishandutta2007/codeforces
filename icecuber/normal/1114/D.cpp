#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[5000];
int mem[5000][5001][2];
int f(int l, int r, int c) {
  if (r-l <= 1) return 0;
  int&memo = mem[l][r][c];
  if (!memo) {
    int ans;
    int t = c?a[r-1]:a[l];
    ans = min({
	f(l+1,r,0)+(a[l+1]!=a[l])+(a[l]!=t),
	  f(l+1,r,1)+(a[r-1]!=a[l])+(a[l]!=t),
	  f(l,r-1,1)+(a[r-2]!=a[r-1])+(a[r-1]!=t),
	  f(l,r-1,0)+(a[l]!=a[r-1])+(a[r-1]!=t)});
    //cout << l << ' ' << r << ' ' << c << ' ' << ans << endl;
    memo = ans+1;
  }
  return memo-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << min(f(0,n,0),f(0,n,1)) << endl;
}