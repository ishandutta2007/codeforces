#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> point;

#define gcd(a, b) __gcd(a, b)
#define all(a) (a).begin(), (a).end()
#define FOR(i, a, b) for(int i = a; i < b; ++i)

const int INF = 1e9;

vector<int> v;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int n; cin >> n;
   FOR(i, 0, n) {
      int x; cin >> x;
      v.push_back(x);
   }
   sort(all(v));
   reverse(all(v));
   int tmp = INF;
   ll sol = 0LL;
   for(int i = 0; i < n; ++i) {
      if(v[i] < tmp) {
         sol += v[i];
         tmp = v[i] - 1;
      }
      else {
         sol += tmp;
         tmp--;
      }
      if(tmp == 0)
         break;
   }
   cout << sol;
}