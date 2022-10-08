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
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

const int MAXN = 607;
bool odw[MAXN];
int col[MAXN], prz[MAXN];
vector <int> G[MAXN];

int ask(vector <int> &A) {
  if(SZ(A) == 1) return 0;
  cout << "? " << SZ(A) << "\n";
  for(auto a : A) cout << a << " ";
  cout << endl;
  int ret;
  cin >> ret;
  return ret;
}

bool connected(vector <int>& A, int v) {
  int a = ask(A);
  A.push_back(v);
  int b = ask(A);
  A.pop_back();
  return b > a;
}

int binsrch(vector <int> &A, int v) {
  int p = 0, k = SZ(A) - 1;
  while(p < k) {
    int m = (p+k) >> 1;
    vi S;
    S.insert(S.end(), A.begin(), A.begin()+m+1);
    if(connected(S, v)) k = m;
    else p = m+1;
  }
  return A[p];
}

int find(vector <int> &A, int v) {
  if(A.empty()) return -1;
  if(connected(A, v)) return binsrch(A, v);
  return -1;
}


int n;

void dfs(int v, int clr = 0, int f = -1) {
  // cerr << "V" << v << " " << clr << "\n";
  odw[v] = true;
  col[v] = clr;
  prz[v] = f;

  vi K;
  for(int i=1; i<=n; i++) {
    if(i == v) continue;
    if(odw[i] and col[v] == col[i]) K.push_back(i);
  }
  int c = find(K, v);
  if(c > 0) {
    vi D;
    int x = v;
    while(x != c) {
      D.push_back(x);
      x = prz[x];
    }
    D.push_back(x);
    cout << "N " << SZ(D) << "\n";
    for(auto d : D) cout << d << " ";
    cout << endl;
    exit(0);
  }

  while(true) {
    vi N;
    for(int i=1; i<=n; i++) if(!odw[i]) N.push_back(i);
    int w = find(N, v);
    if(w == -1) return;
    G[v].push_back(w);
    G[w].push_back(v);
    dfs(w, clr^1, v);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=1; i<=n; i++) {
    if(!odw[i]) dfs(i);
  }
  vi V;
  for(int i=1; i<=n; i++) {
    if(!col[i]) V.push_back(i);
  }
  cout << "Y " << SZ(V) << "\n";
  for(auto v : V) cout << v << " ";
  cout << endl;
  return 0;
}