#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());
vector<int> order;

int query(int a, int b) {
  assert(a != b);
  cout << "? " << order[a]+1 << ' ' << order[b]+1 << endl;
  int ans;
  cin >> ans;
  assert(ans != -1);
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    order.push_back(i);
  shuffle(order.begin(), order.end(), mrand);

  vector<int> pos(11, -1);
  while (count(pos.begin(), pos.end(), -1)) {
    int a = -1, b = -1;
    while (a == b)
      a = mrand()%n, b = mrand()%n;

    int q = query(a, b);
    for (int j = 0; j < 11; j++)
      if (!(q>>j&1))
	pos[j] = a;
  }

  //for (int j = 0; j < 11; j++)
  //  cerr << j << ' ' << pos[j] << endl;

  queue<int> todo;
  for (int i = 0; i < n; i++)
    todo.push(i);

  int curi = pos[0], nxtj = 1;
  while (nxtj < 11) {
    assert(todo.size());
    int i = todo.front();
    todo.pop();

    //cerr << curi << ' ' << i << ' ' << nxtj << endl;
    int q = (i == curi ? 0 : query(curi, i));
    if ((q&((1<<nxtj)-1)) == 0) {
      int s = (pos[nxtj] == i ? 0 : query(pos[nxtj], i));
      if (!(s>>nxtj&1)) {
	todo.push(i);
	curi = i;
	nxtj++;
      }
    }
  }

  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (i != curi)
      ans[order[i]] = query(curi, i);
  }
  cout << "!";
  for (int i = 0; i < n; i++) {
    cout << ' ' << ans[i];
  }
  cout << endl;
}