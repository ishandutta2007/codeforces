#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> divs[200000];
int par[8][6000000];
int a[15][20][200000];

int isprime[10000], prime[10000], primes = 0;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i < 10000; i++) isprime[i] = 1;
  for (int i = 2; i < 10000; i++) {
    if (!isprime[i]) continue;
    prime[primes++] = i;
    for (int j = i*2; j < 10000; j += i)
      isprime[j] = 0;
  }
  int n, q;
  cin >> n >> q;
  fill_n((int*)par, int(8*6e6), -1);
  fill_n((int*)a, 15*20*200000, -1);

  for (int i = 0; i < n; i++) {
    int a0;
    cin >> a0;
    int cp = a0;
    for (int j = 0; j < primes && prime[j]*1ll*prime[j] <= cp; j++) {
      if (cp%prime[j] == 0) {
	int c = 0;
	while (cp%prime[j] == 0) {
	  cp /= prime[j];
	  c ^= 1;
	}
	if (c) divs[i].push_back(prime[j]);
      }
    }
    if (cp > 1) divs[i].push_back(cp);
    a0 = 1;
    for (int i : divs[i]) a0 *= i;
    //cout << endl;
    //cout << a0 << endl;
    //cout << divs[i].size() << endl;
    for (int k = 0; k < 1<<divs[i].size(); k++) {
      int cp = a0, pop = 0;
      for (int j = 0; j < divs[i].size(); j++) {
	if (k>>j&1)
	  cp /= divs[i][j], pop++;
      }
      //cout << cp << endl;
      //cout << pop << ": ";
      for (int j = 0; j < 8; j++) {
	a[j+pop][0][i] = max(a[j+pop][0][i], par[j][cp]);
	//cout << a[j+pop][0][i] << ' ';
      }
      //cout << endl;
      par[pop][cp] = i;
    }
  }
  for (int k = 0; k < 15; k++) {
    for (int l = 1; l < 20; l++) {
      for (int i = 0; i+(1<<l) <= n; i++)
	a[k][l][i] = max(a[k][l-1][i], a[k][l-1][i+(1<<l-1)]);
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    int log2 = 0;
    while (l+(1<<log2+1) <= r) log2++;
    for (int k = 0; k < 15; k++) {
      ll ma = max(a[k][log2][l], a[k][log2][r-(1<<log2)]);
      if (ma >= l) {
	cout << k << '\n';
	break;
      }
    }
  }
}