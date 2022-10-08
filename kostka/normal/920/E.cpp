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
unordered_set <int> G[MAXN];
unordered_set <int> unvisited;

int bfs(int s) {
  queue <int> Q;
  Q.push(s);
  unvisited.erase(s);
  int res = 0;
  while(!Q.empty()) {
    res++;
    int v = Q.front();
    Q.pop();
    vector <int> T;
    for(auto w : unvisited) {
      if(G[v].find(w) == G[v].end()) {
        T.push_back(w);
      }
    }
    for(auto t : T) {
      unvisited.erase(t);
      Q.push(t);
    }
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    G[a].insert(b);
    G[b].insert(a);
  }
  for(int i=1; i<=n; i++) unvisited.insert(i);
  vector <int> X;
  for(int i=1; i<=n; i++) {
    if(unvisited.find(i) != unvisited.end()) X.push_back(bfs(i));
  }
  cout << SZ(X) << "\n";
  sort(X.begin(), X.end());
  for(auto x : X) cout << x << " ";
  cout << "\n";
  return 0;
}