#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
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

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MAX = 400;

bool bio[MAX][MAX];
bool uzeo[MAX][MAX][8];
bool nuzeo[MAX][MAX][8];

int main() {
   uzeo[200][200][0] = true;
   int n; cin >> n; int sol = 0;
   rep(i, n) {
      int t; cin >> t;
      rep(nx, MAX) rep(ny, MAX) rep(ns, 8) if(uzeo[nx][ny][ns]) {
         int x = nx, y = ny, s = ns;
         rep(j, t) {
            if(!bio[x][y]) sol ++;
            bio[x][y] = true;
            if(j != t - 1) {
               x += dx[s];
               y += dy[s];
            }
         }
         nuzeo[x + dx[(s + 1) % 8]][y + dy[(s + 1) % 8]][(s + 1) % 8] = true;
         nuzeo[x + dx[(s - 1 + 8) % 8]][y + dy[(s - 1 + 8) % 8]][(s - 1 + 8) % 8] = true;
      }
      memcpy(uzeo, nuzeo, sizeof uzeo);
      memset(nuzeo, 0, sizeof nuzeo);
   }
   cout << sol;
}