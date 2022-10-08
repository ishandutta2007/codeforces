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

const int MAXN = 100007;
const int MAXG = 107;
int A[MAXN];
bool V[MAXG][MAXN];
int D[MAXG][MAXN];
vi G[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m, s, k;
  cin >> n >> m >> k >> s;
  for(int i=1; i<=n; i++) {
    cin >> A[i];
  }
  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i=1; i<=k; i++) {
    queue <int> Q;
    for(int d=1; d<=n; d++) {
      if(A[d] == i) {
        V[i][d] = true;
        Q.push(d);
      }
    }
    while(!Q.empty()) {
      int q = Q.front();
      Q.pop();
      for(auto x : G[q]) {
        if(!V[i][x]) {
          V[i][x] = true;
          D[i][x] = D[i][q] + 1;
          Q.push(x);
        }
      }
    }
  }
  for(int i=1; i<=n; i++) {
    vi R;
    for(int j=1; j<=k; j++) {
      if(V[j][i]) R.push_back(D[j][i]);
    }
    sort(R.begin(), R.end());
    ll res = 0;
    for(int j=0; j<s; j++) {
      res += R[j];
    }
    cout << res << " ";
  }
  cout << "\n";
  return 0;
}