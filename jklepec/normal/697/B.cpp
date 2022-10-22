#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e5 + 5, mod = 1e9 + 7;

int num(string s) {
   int ret = 0;
   int n = s.size();

   int pot = 1;

   for(int i = n - 1; i >= 0; --i) {
      ret += (s[i] - '0') * pot;
      pot *= 10;
   }

   return ret;
}

void load() {
   string s; cin >> s;

   if(s.substr(1, s.size() - 1) == ".0e0") {
      cout << s.substr(0, 1);
      return;
   }

   int t, e;
   int n = s.size();
   rep(i, n) {
      if(s[i] == '.') t = i;
      if(s[i] == 'e') e = i;
   }
   int exp = num(s.substr(e + 1, s.size() - e - 1));
   string S = "";
   rep(i, n) {
      if(s[i] == 'e') break;
      if(s[i] == '.') continue;
      S += s[i];
   }
   s = S;
   n = s.size();
   t += exp;

   if(t > n) rep(i, t - n) s += '0';

   string l = "", r = "";
   rep(i, t) l += s[i];
   for(int i = t; i < s.size(); ++i) r += s[i];
   int poc = 0;
   while(l[poc] == '0' && poc != l.size() - 1) poc ++;
   for(int i = poc; i < l.size(); ++i) cout << l[i];
   if(r.size()) cout << '.';
   rep(i, r.size()) cout << r[i];

}


int main() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   load();
}