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

unordered_map<string, vector<int>> v;
unordered_map<string, int> bio;
unordered_map<string, int> sz;

vector<string> strs;

int cookie = 1;

string rev(string s) {
   reverse(s.begin(), s.end());
   return s;
}

int sol, mx;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   int n, k; cin >> n >> k;
   rep(i, n) {
      string s; int x; cin >> s >> x;
      v[s].push_back(x);
      strs.push_back(s);
   }

   for(auto s : strs) {
      if(bio[s] == cookie) continue;

      string rs = rev(s);
      bio[s] = bio[rs] = cookie;

      sort(v[s].begin(), v[s].end(), greater<int>());
      sort(v[rs].begin(), v[rs].end(), greater<int>());

      int tmp = 0;
      if(s == rev(s)) {
      while(true) {
         if(tmp + 1 >= v[s].size()) break;
         if(v[s][tmp] + v[s][tmp + 1] <= 0) break;
         sol += v[s][tmp] + v[s][tmp + 1];
         tmp += 2;
      }
      }else {
      while(true) {
         if(tmp >= v[s].size() || tmp >= v[rs].size()) break;
         if(v[s][tmp] + v[rs][tmp] <= 0) break;
         sol += v[s][tmp] + v[rs][tmp];
         tmp ++;
      }}
      sz[rs] = sz[s] = tmp;
   }

   ++cookie;
   for(auto s : strs) {
      if(bio[s] == cookie || s != rev(s)) continue;
      bio[s] = cookie;

      if(sz[s] < v[s].size()) mx = max(mx, v[s][sz[s]]);
      if(sz[s] != 0) mx = max(mx, - v[s][sz[s] - 1]);
   }

   cout << sol + mx;
}