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

const int DRZ = 1<<19;
ll drz[2*DRZ];

ll suma(int p, int q)
{
	p += DRZ;
	q += DRZ;
	ll ret=0;
	while (q>p)
  {
	  if(p%2) ret += drz[p++];
    if(q%2==0) ret += drz[q--];
    p/=2;
    q/=2;
  }
  if (p==q) ret += drz[p];
	return ret;
}

void _set(int x, int ile)
{
	int i = x+DRZ;
  drz[i] = ile;
	while(i > 1)
	{
		i /= 2;
		drz[i] = drz[2*i] + drz[2*i+1];
	}
}

const int MAXE = 1e6+7;
int sito[MAXE];

int divisors(int x) {
  int res = 1;
  if(x == 1) return res;
  while(x != 1) {
    int d = sito[x];
    int ile = 0;
    while(x % d == 0) {
      ile++;
      x /= d;
    }
    res *= (ile+1);
  }
  return res;
}

void preprocessing() {
  for(int i=2; i*i<MAXE; i++) {
    if(!sito[i]) {
      for(int j=i*i; j<MAXE; j+=i) sito[j] = i;
    }
  }
  for(int i=2; i<MAXE; i++) {
    if(!sito[i]) sito[i] = i;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  preprocessing();
  int n, m;
  cin >> n >> m;
  vector <vector <int>> a(n);
  set <int> change;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    _set(i, x);
    a[i].push_back(x);
    while(true) {
      int d = divisors(a[i].back());
      // cerr << x << " " << d << "\n";
      if(a[i].back() == d) break;
      a[i].push_back(d);
    }
    if(SZ(a[i]) != 1) {
      reverse(a[i].begin(), a[i].end());
      change.insert(i);
    }
  }
  while(m--) {
    int t, l, r;
    cin >> t >> l >> r;
    l--; r--;
    if(t == 1) {
      auto st = change.lower_bound(l);
      auto ed = change.upper_bound(r);
      vector <int> to_remove;
      for(auto it = st; it != ed; it++) {
        a[*it].pop_back();
        _set(*it, a[*it].back());
        if(SZ(a[*it]) == 1) to_remove.push_back(*it);
      }
      for(auto x : to_remove) change.erase(x);
    } else {
      cout << suma(l, r) << "\n";
    }
  }
  return 0;
}