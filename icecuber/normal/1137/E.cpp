#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define x first
#define y second

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, q;
  cin >> n >> q;
  vector<pair<ld,ld>> train;
  train.emplace_back(0,0);
  ld add = 0, grad = 0;
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int k;
      cin >> k;
      train.clear();
      train.emplace_back(0,0);
      add = grad = 0;
      n += k;
    } else if (cmd == 2) {
      int k;
      cin >> k;
      auto c = make_pair(n,-add-grad*n);
      while (train.size() >= 2) {
	auto a = train[train.size()-2];
	auto b = train[train.size()-1];
	if ((b.x-a.x)*(c.y-b.y) >= (b.y-a.y)*(c.x-b.x)) break;
	train.pop_back();
      }
      train.push_back(c);
      n += k;
    } else if (cmd == 3) {
      int b, s;
      cin >> b >> s;
      add += b;
      grad += s;
    }
    while (train.size() >= 2) {
      auto a = train[train.size()-2];
      auto b = train[train.size()-1];
      if (b.y-a.y+(b.x-a.x)*grad < 0) break;
      train.pop_back();
    }
    //cout << endl;
    //cout << add << ' ' << grad << endl;
    //for (auto p : train) cout << p.x << ',' << p.y+add+grad*p.x << " : ";
    //cout << endl;

    cout << ll(train.back().x+1) << ' ' << ll(train.back().y+train.back().x*grad+add) << endl;
  }
}