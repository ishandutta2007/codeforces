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

const int MAXN = 107;
vector <pii> G[MAXN];

bool was[MAXN][MAXN][27];
bool res[MAXN][MAXN][27];

bool go(int a, int b, int x) {
  if(was[a][b][x]) return res[a][b][x];
  was[a][b][x] = true;
  bool win = false;
  for(auto ele : G[a]) {
    int p, q;
    tie(p, q) = ele;
    if(q >= x and !go(b, p, q)) win = true;
  }
  return res[a][b][x] = win;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    G[a].emplace_back(b,c-'a');
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) cout << (go(i,j,0) ? "A" : "B");
    cout << "\n";
  }
  return 0;
}