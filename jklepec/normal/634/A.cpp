#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep1(i, n) for(int i = 1; i < n; ++i)
#define _ << " " <<

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

const int MAXN = 2e5 + 5, M = 1e9 + 7, p1 = 105023, p2 = 15486277, p3 = 179425033;

int a[MAXN];

vector<int> nov, o;
vector<int> org;

int main() {
   //ios_base::sync_with_stdio(false); cin.tie(nullptr);

   int n; cin >> n;

   int first;
   bool found = false;

   rep(i, n) {
      int x; cin >> x;
      if(!found && x != 0) {
         first = x;
         found = true;
      }
      if(x)
         org.push_back(x);
   }

   bool found2 = false;

   rep(i, n) {
      int x; cin >> x;
      if(x == 0)
         continue;
      if(!found2 && x == first)
         found2 = true;
      if(found2)
         nov.push_back(x);
      else
         o.push_back(x);
   }

   bool can = true;

   rep(i, n - 1) {
      if(i >= nov.size())
         if(org[i] != o[i - nov.size()])
            can = false;
      if(i < nov.size())
         if(org[i] != nov[i])
            can = false;
   }

   if(can)
      cout << "YES";
   else
      cout << "NO";

}