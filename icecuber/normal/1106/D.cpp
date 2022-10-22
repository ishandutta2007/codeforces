#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cerr << #x << " = " << (x) << endl;

vector<int> node[100000];
int done[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  set<int> s;
  s.insert(0);
  done[0] = 1;
  while (!s.empty()) {
    int p = *s.begin();
    s.erase(p);
    cout << p+1 << ' ';
    for (int i : node[p]) {
      if (!done[i]++) s.insert(i);
    }
  }
  cout << endl;
}