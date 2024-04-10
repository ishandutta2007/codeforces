#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

vector<int> todelete;
vector<int> tocheck;

const int MAXN = 1e6 + 5;

int nxt[MAXN], pre[MAXN];
bool bio[MAXN];

string s;
int n;

void Empty() {

  sort(todelete.begin(), todelete.end());

  tocheck.clear();
  for(auto x: todelete) {
    bio[x] = true;

    nxt[pre[x]] = nxt[x];
    pre[nxt[x]] = pre[x];

    tocheck.push_back(nxt[x]);
    tocheck.push_back(pre[x]);
  }

  todelete.clear();

  for(auto x: tocheck) {
    if(x <= 0 || x >= n + 1)
      continue;
    if(bio[x])
      continue;

    int l = pre[x];
    int r = nxt[x];

    if((s[x] != s[l] && l > 0 && l < n + 1) || (s[x] != s[r] && r < n + 1 && r > 0)) {
      todelete.push_back(x);
      bio[x] = true;
    }
  }
}

int main() {
  cin >> s;
  n = s.size();

  s = '$' + s;

  REP(i, n + 2) {
    nxt[i] = i + 1;
    pre[i] = i - 1;
  }

  FOR(i, 1, n + 1) {
    if((s[i] != s[i - 1] && i != 1) || (s[i] != s[i + 1] && i != n)) {
      todelete.push_back(i);
    }
  }

  int k = 0;

  while(todelete.size()) {
    Empty();
    k ++;
  }

  cout << k;
}