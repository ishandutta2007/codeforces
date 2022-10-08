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

const int MAXN = 1e5+7;
vi G[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vi KAN;
  for(int i=1; i<=n; i++) {
    if(SZ(G[i]) > 2) {
      KAN.push_back(i);
    }
  }
  if(SZ(KAN) > 1) {
    cout << "No\n";
    return 0;
  }
  int v = 1;
  if(!KAN.empty()) {
    v = KAN[0];
  }
  vi K;
  for(int i=1; i<=n; i++) {
    if(i != v and SZ(G[i]) == 1) {
      K.push_back(i);
    }
  }
  cout << "Yes\n";
  cout << SZ(K) << "\n";
  for(auto k : K) {
    cout << v << " " << k << "\n";
  }
  return 0;
}