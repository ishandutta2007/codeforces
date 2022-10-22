#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int pos[200000];
int x[400000], y[400000];
int a[400000];
int ans[100000];
vector<pair<int,int>> query[400000];

const int m = 500000;
int data[m];
void add(int i, int v) {
  for (i += 10; i < m; i += i&-i) data[i] += v;
}
int sum(int i) {
  int r = 0;
  for (i += 10; i; i -= i&-i) r += data[i];
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<pair<int,int>, int> last;
  int ind = 1;
  for (int i = 0; i < n; i++) {
    pos[i] = ind;
    int k;
    cin >> k;
    for (int j = 0; j < k; j++)
      cin >> x[j] >> y[j];
    for (int j = 0; j < k; j++) {
      pair<int,int> p(x[(j+1)%k]-x[j], y[(j+1)%k]-y[j]);
      int g = __gcd(abs(p.first), abs(p.second));
      p.first /= g;
      p.second /= g;
      a[ind] = last[p];
      last[p] = ind++;
    }
  }
  pos[n] = ind++;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    ans[i] = pos[r]-pos[l];
    query[pos[r]].push_back({pos[l],i});
  }
  for (int i = 0; i < ind; i++) {
    for (auto q : query[i]) {
      int l = q.first, qi = q.second;
      ans[qi] -= sum(i)-sum(l-1);
    }
    add(a[i],1);
  }
  for (int i = 0; i < q; i++)
    cout << ans[i] << endl;
}