#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 2e5, K = 100;
int grundy[M], a[M], b[M];
int isprime[M], prime[M], primes = 0;
vector<int> pos[M];
int found[M];

int stat[M];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i < M; i++) isprime[i] = 1;
  for (int i = 2; i < M; i++) {
    if (!isprime[i]) continue;
    prime[primes++] = i;
    for (int j = i*2; j < M; j += i)
      isprime[j] = 0;
  }
  for (int i = 0; i < primes; i++) {
    a[prime[i]] = 1;
    for (int j = i; j < primes && 1ll*prime[i]*prime[j] < M; j++)
      a[prime[i]*prime[j]] = 1;
  }

  int n, f;
  cin >> n >> f;

  a[f] = 0;
  int moves = 0;
  for (int i = 0; i < M; i++) {
    if (a[i]) b[moves++] = i;
  }
  //for (int i = 0; i < 20; i++) cout << b[i] << ' ';
  //cout << endl;
  //cout << moves << endl;


  for (int k = 0; k < M; k++) {
    fill_n(found, K, 0);
    int ok = 0;
    for (int i = 0; i < K; i++) {
      /*if (found[i]) continue;
      for (int j = 0; j < moves && b[j] <= k; j++) {
	int c = grundy[k-b[j]];
	found[c]++;
	if (c == i) break;
	}*/
      int f = 0;
      //for (int j = int(pos[i].size())-1; j >= 0; j--)
      for (int j = 0; j < pos[i].size(); j++)
	if (a[k-pos[i][j]]) {
	  f = 1;
	  break;
	}
      if (!f) {
	grundy[k] = i;
	pos[i].push_back(k);
	stat[i]++;
	ok = 1;
	break;
      }
    }
    if (!ok) cout << "Overflow!" << endl;
  }

  /*for (int i = 0; i < 20; i++)
    cout << grundy[i] << ' ';
    cout << endl;*/

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    ans ^= grundy[b-a-1];
    ans ^= grundy[c-b-1];
  }
  //cout << endl;
  //cout << ans << endl;
  string sa = "Alice", sb = "Bob";
  if (ans == 0) swap(sa,sb);
  cout << sa << endl;
  cout << sb << endl;

  /*
  for (int i = 0; i < 100; i++)
    cout << grundy[i] << ' ';
  cout << endl;
  for (int i = 0; i < 100; i++)
    cout << stat[i] << ' ';
  cout << endl;
  cout << primes << ' ' << moves << endl;*/
}