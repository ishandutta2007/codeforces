#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 3e3 + 5, inf = 1e9;

int bio[MAXN], dist[MAXN][MAXN];
int cookie;

vector<int> e[MAXN];

void calc(int S) {
   queue<int> Q;
   Q.push(S);
   bio[S] = ++cookie;
   dist[S][S] = 0;
   while(Q.size()) {
      int x = Q.front();
      Q.pop();
      for(auto y : e[x]) {
         if(bio[y] == cookie) continue;

         Q.push(y);
         bio[y] = cookie;
         dist[S][y] = dist[S][x] + 1;
      }
   }
}

point in[MAXN][3], out[MAXN][3];

int a, b, c, d, sol;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);

   rep(i, MAXN) rep(j, MAXN) dist[i][j] = inf;

   rep(i, MAXN) rep(k, 3) in[i][k] = out[i][k] = {-1, -1};

   int n, m;
   cin >> n >> m;

   rep(i, m) {
      int x, y;
      cin >> x >> y;
      e[--x].push_back(--y);
   }

   rep(i, n) calc(i);

   rep(i, n) rep(j, n) {
      if(dist[i][j] != inf && i != j) {
         int mn = in[j][0].first, ind = 0;
         rep(k, 2) {
            if(in[j][k + 1].first < mn) {
               mn = in[j][k + 1].first;
               ind = k + 1;
            }
         }
         in[j][ind] = {dist[i][j], i};
         mn = out[i][0].first; ind = 0;
         rep(k, 2) {
            if(out[i][k + 1].first < mn) {
               mn = out[i][k + 1].first;
               ind = k + 1;
            }
         }
         out[i][ind] = {dist[i][j], j};
      }
   }

   rep(i, n) rep(j, n) {
      if(dist[i][j] == inf || i == j) continue;

      rep(k1, 3) rep(k2, 3) {
         int a1, d1;
         a1 = in[i][k1].second;
         d1 = out[j][k2].second;
         if(a1 == i || a1 == j || d1 == i || d1 == j || a1 == d1 || a1 < 0 || d1 < 0) continue;
         int tmp = dist[i][j] + dist[a1][i] + dist[j][d1];
         if(tmp > sol) {
            sol = tmp;
            a = a1;
            b = i;
            c = j;
            d = d1;
         }
      }
   }

   cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << '\n';
}