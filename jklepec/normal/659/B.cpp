#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e4 + 5;

vector<pair<int, string> > v[MAXN];

bool cmp(const pair<int, string> &A, const pair<int, string> &B) {
   return A.first < B.first;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   int n, m; cin >> n >> m;
   rep(i, n) {
      string s; int r, res;
      cin >> s >> r >> res;
      v[--r].push_back({-res, s});
   }

   rep(i, m) {
      sort(v[i].begin(), v[i].end(), cmp);
      if(v[i].size() > 2 && v[i][1].first == v[i][2].first)
         cout << "?" << endl;
      else
         cout << v[i][0].second << " " << v[i][1].second << endl;
   }
}