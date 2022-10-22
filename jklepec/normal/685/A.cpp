#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;

int N, M, n, m;

bool took[8];

int ln, lm, fn, fm;

vector<pair<ll, int> > v1, v2;

ll veliki(int pos, int num = 0, int pot = 1) {
   if(pos == N && num <= n) return 1;
   if(pos == N) return 0;
   ll ret = 0;
   rep(i, 7) {
      if(!took[i]) continue;
      took[i] = false;
      ret += veliki(pos + 1, num + pot * i, pot * 7);
      took[i] = true;
   }
   return ret;
}

ll veliki2(int pos, int num = 0, int pot = 1) {
   if(pos == M && num <= m) return 1;
   if(pos == M) return 0;
   ll ret = 0;
   rep(i, 7) {
      if(!took[i]) continue;
      took[i] = false;
      ret += veliki2(pos + 1, num + pot * i, pot * 7);
      took[i] = true;
   }
   return ret;
}

bool imam[8];

ll sol;

bool bio[1000000], bio2[1000000];

void duboka(int pos) {
   if(pos == N) {
      int stanje = 0, pot = 1;
      rep(i, 7) {if(imam[i]) stanje += pot; pot *= 2;}
      if(bio[stanje]) return;
      bio[stanje] = true;
      rep(i, 7) took[i] = imam[i];
      v1.push_back({veliki(0), stanje});
      return;
   }
   rep(i, 7) {
      if(!imam[i]) {
         imam[i] = true;
         duboka(pos + 1);
         imam[i] = false;
      }
   }
}

void duboka2(int pos) {
   if(pos == M) {
      int stanje = 0, pot = 1;
      rep(i, 7) {if(imam[i]) stanje += pot; pot *= 2;}
      if(bio2[stanje]) return;
      bio2[stanje] = true;
      rep(i, 7) took[i] = imam[i];
      v2.push_back({veliki2(0), stanje});
      return;
   }
   rep(i, 7) {
      if(!imam[i]) {
         imam[i] = true;
         duboka2(pos + 1);
         imam[i] = false;
      }
   }
}

int main() {
   cin >> n >> m;

   --n; --m;

   if(n == 0) N = 1;
   if(m == 0) M = 1;

   int d = n;
   while(d) {
      d /= 7;
      N ++;
   }
   d = m;
   while(d) {
      d /= 7;
      M ++;
   }
   if(N + M > 7) {cout<<0;return 0;}

   fn = n % 7 + 1;
   fm = m % 7 + 1;

   ln = n / 7 + 1;
   lm = m / 7 + 1;

   if(n < 7) ln = 10;
   if(m < 7) lm = 10;

   duboka(0); duboka2(0);

   for(auto p1 : v1) for(auto p2 : v2) {
      ll x = p1.first;
      ll y = p2.first;
      int s1 = p1.second, s2 = p2.second;
      bool pok = true;
      rep(i, 7) {
         if(s1 % 2 == s2 % 2 && s1 % 2 == 1) pok = false;
         s1 /= 2;
         s2 /= 2;
      }
      if(pok) sol += x * y;
   }

   cout << sol;
}