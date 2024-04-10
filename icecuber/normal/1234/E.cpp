#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans[200010];
void add(int a, int b, int v) {
  ans[a] += v;
  ans[b+1] -= v;
  //for (int i = a; i <= b; i++)
  //  ans[i] += v;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int last;
  cin >> last;
  for (int i = 1; i < m; i++) {
    int x;
    cin >> x;
    int a = min(x,last), b = max(x,last);
    if (a == b) continue;
    add(1,a-1,abs(a-b));
    add(a,a,b-1);
    add(a+1,b-1, abs(a-b)-1);
    add(b,b,a);
    add(b+1,n,abs(a-b));
    last = x;
  }
  for (int i = 1; i <= n; i++)
    ans[i] += ans[i-1];
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}