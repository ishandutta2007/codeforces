#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1<<19;

int l[nax], r[nax];
ll d[nax];

ll mi[nax*2], ma[nax*2];
void tree_set(int i, ll v) {
  i += nax;
  mi[i] = ma[i] = v;
  for (i /= 2; i; i /= 2) {
    mi[i] = min(mi[i*2], mi[i*2+1]);
    ma[i] = max(ma[i*2], ma[i*2+1]);
  }
}
pair<ll,ll> tree_min_max(int l, int r) {
  l += nax, r += nax;
  ll qmi = mi[l], qma = ma[l], f = 0;
  for (; r>l; ++l /= 2, r /= 2)
    for (int i : {l,r-1})
      if (i%2 == ++f%2) {
	qmi = min(qmi, mi[i]);
	qma = max(qma, ma[i]);
      }
  return make_pair(qmi, qma);
}

int main() {
  int n, A;
  cin >> n >> A;
  int last;
  ll sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int D, C;
    cin >> D >> C;
    d[i] = ll(D-last)*(D-last);
    last = D;
    sum += A-C;
    tree_set(i+1, sum);
    ans = max(ans, ll(A-C));
  }
  for (int i = 1; i < n; i++)
    for (l[i] = i-1; l[i] > 0 && d[l[i]] <= d[i]; l[i] = l[l[i]]);
  for (int i = n-1; i; i--)
    for (r[i] = i+1; r[i] < n && d[r[i]] <= d[i]; r[i] = r[r[i]]);
  for (int i = 1; i < n; i++)
    ans = max(ans, tree_min_max(i+1, r[i]+1).second-tree_min_max(l[i], i).first-d[i]);
  cout << ans << endl;
}