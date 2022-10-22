#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e6;
int data[M];
void add(int i, int v) {
  for (i += 10; i < M; i += i&-i) data[i] += v;
}
int sum(int i) {
  int r = 0;
  for (i += 10; i; i -= i&-i) r += data[i];
  return r;
}

int a[200000];
int ans[200000];

struct Query {
  int v, l, r, k, t;
};
bool operator<(Query a, Query b) {
  if (a.v != b.v) return a.v < b.v;
  return a.t < b.t;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,int> mi;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mi[a[i]];
  }
  int c = 0;
  for (auto&p : mi) p.second = c++;

  vector<Query> query;
  for (int i = 0; i < n; i++) {
    query.push_back( { mi[a[i]], i, 0, 0, 1 } );
    for (int k = 1; i*k+1 < n && k < n; k++) {
      //for (int j = 1; j <= k && i*k+j < n; j++)
      //ans[k] += a[i] > a[i*k+j];
      query.push_back( { mi[a[i]], i*k+1, min(i*k+k+1,n), k, 0 } );
    }
  }

  sort(query.begin(), query.end());
  for (Query q : query) {
    if (q.t == 1) {
      add(q.l, 1);
    } else {
      ans[q.k] += sum(q.r-1)-sum(q.l-1);
    }
  }
  for (int i = 1; i < n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}