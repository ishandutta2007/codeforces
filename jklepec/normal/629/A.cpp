#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

#define FOR(i, a, b) for(int i = a; i < b; ++i)

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

const int MAXN = 1e5 + 5;

int col[MAXN], row[MAXN];

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);

   int n;
   cin >> n;

   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
         char x; cin >> x;

         if(x == 'C') {
            row[i]++;
            col[j]++;
         }
      }
   }

   ll sol = 0;

   for(int i = 0; i < n; ++i) {
      sol += row[i] * (row[i] - 1) / 2;
      sol += col[i] * (col[i] - 1) / 2;
   }

   cout << sol;
}