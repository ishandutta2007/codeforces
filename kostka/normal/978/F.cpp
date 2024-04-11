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

const int MAXN = 200007;
vi G[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vi a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  vi b = a;
  sort(b.begin(), b.end());
  while(m--) {
    int p, q;
    cin >> p >> q;
    p--; q--;
    G[p].push_back(q);
    G[q].push_back(p);
  }
  for(int i=0; i<n; i++) {
    int w = distance(b.begin(), lower_bound(b.begin(), b.end(), a[i]));
    for(auto g : G[i]) {
      if(a[g] < a[i]) w--;
    }
    cout << w << " ";
  }
  cout << "\n";
  return 0;
}