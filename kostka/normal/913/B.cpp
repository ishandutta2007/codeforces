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

const int MAXN = 1007;
vi G[MAXN];

bool check(int v) {
  int ile = 0;
  for(auto w : G[v]) {
    if(G[w].empty()) ile++;
    else if(!check(w)) return false;
  }
  return (ile >= 3);
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=2; i<=n; i++) {
    int p;
    cin >> p;
    G[p].push_back(i);
  }
  cout << (check(1) ? "Yes\n" : "No\n");
  return 0;
}