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

string s, sol = "";
int tmpush, tmpop;
list<point> L;

void push() {
   while(!L.empty() && L.back().first >= s[tmpush] - 'a')
      L.pop_back();
   L.push_back({s[tmpush] - 'a', tmpush});
   tmpush ++;
}
void pop() {
   if(L.front().second == tmpop)
      L.pop_front();
   tmpop ++;
}
int query() {
   return L.front().second;
}
int query2() {
   return L.front().first;
}

const int MAXN = 1e5 + 10;

int n, m;
bool bio2[28];
bool bio[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

   cin >> m >> s;

   n = s.size();

   rep(i, m) {
      push();
   }
   int tmp = query();
   bio[tmp] = true;

   rep(i, n - m) {
      pop();
      push();
      if(tmp < i + 1 || query2() < s[tmp] - 'a') {
         tmp = query();
      }
      bio[tmp] = true;
   }

   rep(i, n) {
      if(bio[i]) bio2[s[i] - 'a'] = true;
   }
   int l = -1;
   rep(i, 26) if(bio2[i]) l = i;
   bio2[l] = false;
   rep(i, l) bio2[i] = true;
   rep(i, n) {
      if(bio[i] || bio2[s[i] - 'a']) sol += s[i];
   }

   sort(sol.begin(), sol.end());
   cout << sol;
}