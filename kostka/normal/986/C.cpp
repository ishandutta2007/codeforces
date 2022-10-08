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

const int MAX = 1<<23;

vector <bool> A, V;
vi O;
int n, m;

bool dfs(int v, bool direction) {
  // cerr << "V" << v << "\n";
  V[v] = true;
  bool czy = A[v] and !(v & 1);
  // if(czy) cerr << "C" << v << "\n";
  if(A[v]) {
    if(bool(v&1) == direction) {
      if(!V[v^1]) czy |= dfs(v^1, direction);
    } else {
      // (((~0) & ((1<<(m+1))-1)) xD
      int w = ((1<<(m+1))-1);
      if(!V[v^w]) czy |= dfs(v^w, direction);
    }
    if(v & 1) {
      for(int i=2; i<1<<(m+1); i<<=1) {
        if(bool(v & i) == direction) {
          if(!V[v^i]) czy |= dfs(v^i, direction);
        }
      }
    }
  }
  if(!direction) O.push_back(v);
  return czy;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> m >> n;
  A.resize(1<<(m+1));
  V.resize(1<<(m+1));
  for(int i=1; i<(1<<(m+1)); i+=2) A[i] = true;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    A[x<<1] = true;
  }
  for(int i=0; i<(1<<(m+1)); i++) {
    if(!V[i]) dfs(i, false);
  }
  reverse(O.begin(), O.end());
  for(int i=0; i<(1<<(m+1)); i++) V[i] = false;
  int ret = 0;
  for(auto o : O) {
    if(!V[o] and dfs(o, true)) ret++;
  }
  cout << ret << "\n";
  return 0;
}