#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef double lf;
typedef long long ll;

int ms[1 << 19 + 1];

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int n; cin >> n;
   rep(i, n) {
      char c; cin >> c;
      if(c == '+' || c == '-') {
         ll x; cin >> x;
         int mask = 0;
         ll y = x;
         int tmp = 1;
         while(y) {
            if((y % 10) % 2) mask |= tmp;
            y /= 10;
            tmp *= 2;
         }
         if(c == '+') ms[mask]++;
         else ms[mask]--;
      }
      else {
         string s; cin >> s;
         int mask = 0;
         for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] == '1') {
               mask |= 1 << (s.size() - 1 - i);
            }
         }
         cout << ms[mask] << endl;
      }
   }
}