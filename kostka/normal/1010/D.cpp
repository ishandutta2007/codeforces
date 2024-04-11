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

enum symbol {AND, OR, XOR, NOT, IN};
unordered_map <string, symbol> str2symbol = {
  {"AND", AND}, {"OR", OR}, {"XOR", XOR}, {"NOT", NOT}, {"IN", IN}
};
typedef tuple<symbol, int, int> bramka;
vector <bramka> B;
vector <bool> value, changed;

bool dfs(int v) {
  symbol s = get<0>(B[v]);
  if(s == IN) return value[v] = get<1>(B[v]);
  if(s == AND or s == OR or s == XOR) {
    bool a = dfs(get<1>(B[v]));
    bool b = dfs(get<2>(B[v]));
    if(s == AND) return value[v] = (a && b);
    if(s == OR) return value[v] = (a || b);
    if(s == XOR) return value[v] = (a != b);
  }
  if(s == NOT) {
    bool a = dfs(get<1>(B[v]));
    return value[v] = (!a);
  }
  assert(false);
}

void dfs2(int v) {
  symbol s = get<0>(B[v]);
  if(s == IN) changed[v] = true;
  if(s == XOR) {
    dfs2(get<1>(B[v]));
    dfs2(get<2>(B[v]));
  }
  if(s == NOT) dfs2(get<1>(B[v]));
  if(s == AND) {
    if(value[get<1>(B[v])]) dfs2(get<2>(B[v]));
    if(value[get<2>(B[v])]) dfs2(get<1>(B[v]));
  }
  if(s == OR) {
    if(!value[get<1>(B[v])]) dfs2(get<2>(B[v]));
    if(!value[get<2>(B[v])]) dfs2(get<1>(B[v]));    
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  value.resize(n);
  changed.resize(n);
  for(int i=0; i<n; i++) {
    string x;
    cin >> x;
    symbol s = str2symbol[x];
    if(s == AND or s == OR or s == XOR) {
      int y, z;
      cin >> y >> z;
      y--; z--;
      B.emplace_back(s, y, z);
    } else {
      int c;
      cin >> c;
      if(s == NOT) c--;
      B.emplace_back(s, c, -1);
    }
  }
  bool dom = dfs(0);
  dfs2(0);
  for(int i=0; i<n; i++) if(get<0>(B[i]) == IN) {
    cout << ((dom ^ changed[i]) ? 1 : 0);
  }
  cout << "\n";
  return 0;
}