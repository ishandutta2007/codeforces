#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string input[20];
ll c[1<<19], x[1<<19];
ll tree[20][1<<19];
ll sign[19];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    cin >> input[i];

  for (int j = 0; j < w; j++) {
    int v = 0;
    for (int i = 0; i < h; i++)
      v |= input[i][j]-'0'<<i;
    if (v>>h-1&1) v = (1<<h)-1-v;
    x[v]++;
  }

  int n = h-1;
  for (int i = 0; i < 1<<n; i++)
    c[i] = min(__builtin_popcount(i), __builtin_popcount((1<<h)-1-i));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 1<<n; j++) {
      if (j&1<<i) {
	int k = j-(1<<i);
	c[j] = c[j]+c[k];
	c[k] = c[j]-c[k]*2;
	x[j] = x[j]+x[k];
	x[k] = x[j]-x[k]*2;
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < 1<<n; i++) {
    tree[n][i] = x[i]*c[i];
    sum += x[i]*c[i];
  }

  for (int i = 0; i < n; i++) sign[i] = 1;

  for (int i = n-1; i >= 0; i--)
    for (int j = 0; j < 1<<i; j++)
      tree[i][j] = sign[i]*tree[i+1][j]+tree[i+1][j+(1<<i)];

  ll ans = tree[0][0];
  for (int x = 1; x < 1<<n; x++) {
    int maxchange = 0;
    for (int k = 0; k < n; k++) {
      if (sign[k] != 1-(x>>k&1)*2) {
	sign[k] *= -1;
	maxchange = k;
      }
    }
    for (int i = maxchange; i >= 0; i--)
      for (int j = 0; j < 1<<i; j++)
	tree[i][j] = sign[i]*tree[i+1][j]+tree[i+1][j+(1<<i)];
    ans = min(ans, tree[0][0]);
  }
  cout << (ans>>n) << endl;
}