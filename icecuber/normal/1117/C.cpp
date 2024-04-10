#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[100001], dy[100001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x0,y0,x1,y1;
  cin >> x0 >> y0 >> x1 >> y1;
  int tx = x1-x0, ty = y1-y0;
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    dx[i+1] = dx[i]+(s[i]=='R')-(s[i]=='L');
    dy[i+1] = dy[i]+(s[i]=='U')-(s[i]=='D');
  }
  ll fail = 0, pass = 1e16;
  while (pass-fail > 1) {
    ll mid = pass+fail>>1;
    ll x = mid/n*dx[n]+dx[mid%n]-tx;
    ll y = mid/n*dy[n]+dy[mid%n]-ty;
    if (abs(x)+abs(y) <= mid) pass = mid;
    else fail = mid;
  }
  cout << (pass<1e16 ? pass : -1) << endl;
}