#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) for(int i = 0; i < n; ++i)
#define _ << " " <<
typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int mod = 1e9 + 7;
int add(int x, int y) {
	x += y;
	if(x >= mod) return x - mod;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if(x < 0) return x + mod;
	return x;
}
int mul(int x, int y) {
	return (ll) x * y % mod;
}

const int MAXN = 2e5 + 5;

bool bio[MAXN];
vector<int> obilazak, e[MAXN], sol[MAXN];

void dfs(int v) {
   bio[v] = true;
   obilazak.push_back(v);
   for(auto w : e[v]) {
      if(!bio[w]) {
         dfs(w);
         obilazak.push_back(v);
      }
   }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   int n, m, k; cin >> n >> m >> k;

   REP(i, m) {
      int x, y; cin >> x >> y;
      e[x].push_back(y);
      e[y].push_back(x);
   }

   dfs(1);

   obilazak.pop_back();

   int tmp = 0;
   int moze = 2 * n / k;
   if((2 * n) % k != 0) moze ++;

   REP(j, k) {
      for(int i = tmp; i < tmp + moze; ++i) {
         if(i >= obilazak.size()) break;
         sol[j].push_back(obilazak[i]);
      }
      tmp += moze;
   }
   REP(i, k) {
      if(sol[i].size() == 0) cout << 1 _ 1 << "\n";
      else {
         cout << sol[i].size();
         for(auto x : sol[i]) cout _ x;
         cout << "\n";
      }
   }
}