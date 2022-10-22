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

const int MAXN = 1005;

bool solved[MAXN];
string a[MAXN], b[MAXN], sol[MAXN];

map<string, bool> bio;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   int n; cin >> n;
   REP(i, n) {
      cin >> a[i] >> b[i];
   }

   REP(i, n) {
      bool ok = true;
      REP(j, n) {
         if(i == j) continue;
         if(a[i].substr(0, 3) == a[j].substr(0, 3)) ok = false;
      }
      if(!ok) {
         sol[i] = a[i].substr(0, 2) + b[i][0];
         if(bio[sol[i]]) {
            cout << "NO";
            return 0;
         }
         bio[sol[i]] = true;
         solved[i] = true;
      }
   }

   while(true) {
      bool found = false;
      REP(i, n) {
         if(!solved[i] && bio[a[i].substr(0, 3)]) {
            sol[i] = a[i].substr(0, 2) + b[i][0];
            if(bio[sol[i]]) {
               cout << "NO";
               return 0;
            }
            bio[sol[i]] = true;
            solved[i] = true;
            found = true;
            break;
         }
      }
      if(found) continue;
      REP(i, n) {
         if(!solved[i]) {
            sol[i] = a[i].substr(0, 3);
         }
      }
      break;
   }
   cout << "YES" << endl;
   REP(i, n) {
      cout << sol[i] << "\n";
   }
}