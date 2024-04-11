//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

int phi(int n) {
	int res = n;
	for(int i=2; i*i<=n; i++)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			res -= res / i;
		}
	if (n > 1)
		res -= res / n;
	return res;
}

int pot(int a, int b, int mod) {
    int res = 1;
    bool aa = a >= mod;
    bool rr = res >= mod;
    while (b) {
        if (b & 1) {
            if (aa or 1LL * res * a >= mod) rr = true;
            res = 1LL * res * a % mod;
        }
        b >>= 1;
        if (1LL * a * a >= mod) aa = true;
        if (b) a = 1LL * a * a % mod;
    }
    return (int)res + (rr ? mod : 0);
}


vector <int> w, M;

int query(int a, int b, int m=0) {
  if(M[m] == 1) return 1;
  if(a == b) return w[b];
  return pot(w[a], query(a+1, b, m+1), M[m]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  w.resize(n+1);
  for(int i=1; i<=n; i++) cin >> w[i];
  M = {m};
  while(M.back() != 1) {
    M.push_back(phi(M.back()));
  }
  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) % m << "\n";
  }
  return 0;
}