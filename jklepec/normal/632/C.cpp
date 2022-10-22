#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep1(i, n) for(int i = 1; i < n; ++i)
#define _ << " " <<

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

const int MAXN = 2e5 + 5, M = 1e9 + 7, p1 = 105023, p2 = 15486277, p3 = 179425033;

string sol;

bool comp(const string &a, const string &b) {
   return a + b < b + a;
}

vector<string> v;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   int n; cin >> n;

   rep(i, n) {
      string s;
      cin >> s;
      v.push_back(s);
   }

   sort(v.begin(), v.end(), comp);

   rep(i, n)
      cout << v[i];

}