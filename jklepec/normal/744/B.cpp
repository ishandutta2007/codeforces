#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int mod = 1e9 + 7, offset = 1024;
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

int B;

vector<int> p[22];
int sol[22][1005];
int ispis[22];
vector<int> pitachu;

int main() {
   ios_base::sync_with_stdio(false); cout.tie(0);
   rep(i, 22) rep(j, 1005) sol[i][j] = 1e9 + 5;
	int n; cin >> n;
   int korak = 1;
   for(int i = 0; i < 10; ++i) {
      int tmp = 1;
      while(tmp <= 1000) {
         for(int j = tmp; j < tmp + korak; ++j) p[i].push_back(j);
         tmp += 2 * korak;
      }
      korak *= 2;
   }
   korak = 1;
   for(int i = 10; i < 20; ++i) {
      int tmp = 1;
      while(tmp <= 1000) {
         for(int j = tmp + korak; j < tmp + 2 * korak; ++j) p[i].push_back(j);
         tmp += 2 * korak;
      }
      korak *= 2;
   }
   for(int i = 0; i < 20; i++) {
      pitachu.clear();
      for(auto x : p[i]) if(x <= n) pitachu.push_back(x);
      if(pitachu.size() == 0) continue;
      cout << pitachu.size() << '\n';
      for(auto x : pitachu) cout << x << " ";
      cout << '\n';
      fflush(stdout);
      for(int j = 0; j < n; ++j) cin >> sol[i][j];
   }
   for(int i = 0; i < n; ++i) {
      int tmp = offset + i;
      int br = 0, mn = 1e9 + 5;
      while(tmp != 1) {
         if(tmp % 2 == 1) {
            mn = min(mn, sol[br][i]);
         }
         else {
            mn = min(mn, sol[br + 10][i]);
         }
         tmp /= 2;
         br ++;
      }
      ispis[i] = mn;
   }
   cout << -1 << '\n';
   for(int i = 0; i < n; ++i) cout << ispis[i] << " ";
   cout << '\n';
   fflush(stdout);
}