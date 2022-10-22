#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef pair<int, int> point;

const int SQRT = 1e6;

bool bio[SQRT];

vector<int> v;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int n, m;
   cin >> n >> m;
   rep(i, n) {
      int x; cin >> x;
      if(x < SQRT) bio[x] = true;
   }

   rep(i, SQRT - 1) {
      if(!bio[i + 1] && m > i) {
         m -= i + 1;
         v.push_back(i + 1);
      }
   }

   cout << v.size() << '\n';
   rep(i, v.size())
      cout << v[i] << ' ';
}