#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int k;
    cin >> k;
    int w = k*2+1;
    vector<string> a[2];
    int ei, ej;
    for (int i = 0; i < 2; i++) {
      a[i].resize(w);
      for (int j = 0; j < w; j++) {
	cin >> a[i][j];
	if (a[i][j] == "E") ei = i, ej = j;
      }
    }

    string ans;
    while (a[1][k] != "E") {
      if (ej > k) {
	ans += 'l';
	swap(a[ei][ej], a[ei][ej-1]);
	ej--;
      } else if (ej < k) {
	ans += 'r';
	swap(a[ei][ej], a[ei][ej+1]);
	ej++;
      } else if (ei == 0) {
	ans += 'd';
	swap(a[ei][ej], a[ei+1][ej]);
	ei++;
      } else assert(0);
    }

    map<string, pair<int,int>> lookup;
    lookup[to_string(k+1)] = {-1,-1};
    for (int i = 0; i < k; i++) {
      lookup[to_string(k-i)] = {0,i+1};
      lookup[to_string(k+2+i)] = {1,i+1};
    }
    for (int i = 0; i < k; i++) {
      lookup[to_string(w+1+i)] = {0,k+1+i};
      lookup[to_string(k*4+1-i)] = {1,k+i+1};
    }

    auto find = [&](string s) {
      assert(lookup.count(s));
      return lookup[s];
    };

    vector<pair<int,int>> l(w), r(w);
    for (int j = 0; j < k; j++) {
      l[j+k+1] = find(a[1][j]);
      r[j+k+1] = find(a[1][k*2-j]);
    }
    for (int j = 0; j <= k; j++) {
      l[j] = find(a[0][k-j]);
      r[j] = find(a[0][k+j]);
    }

    auto L = [&](int t) {
      t = (t%w+w)%w;
      for (int i = 0; i < t; i++)
	ans += 'L';
      auto nl = l;
      for (int i = 0; i < w; i++)
	nl[i] = l[(i+t)%w];
      swap(l,nl);
      r[0] = l[0];
    };
    auto R = [&](int t) {
      t = (t%w+w)%w;
      for (int i = 0; i < t; i++)
	ans += 'R';
      auto nr = r;
      for (int i = 0; i < w; i++)
	nr[i] = r[(i+t)%w];
      swap(r,nr);
      l[0] = r[0];
    };

    auto locate = [&](int s, int v) {
      for (int i = 0; i < w; i++) if (l[i] == make_pair(s,v)) return make_pair(0,i);
      for (int i = 0; i < w; i++) if (r[i] == make_pair(s,v)) return make_pair(1,i);
      assert(0);
      return make_pair(-2,-2);
    };

    auto reset = [&]() {
      auto [s,p] = locate(-1,-1);
      if (s) R(p);
      else L(p);
    };

    reset();
    L(1);
    while (1) {
      while (l[0].first == 0) L(1);
      if (l[0].first == -1) break;
      while (r[0].first == 1) R(1);
    }

    for (int i = 1; i < w; i++) {
      assert(l[i].first == 0);
      assert(r[i].first == 1);
    }

    {
      int flip = 1, stored = -1;
      for (int i = 1; i < w; i++) {
	/*cout << i << endl;
	for (auto [s,p] : r) cout << s << ',' << p << "  ";
	cout << endl;*/
	if (stored != i) {
	  auto [s,p] = locate(1,i);
	  assert(s == 1);
	  R(p);
	  assert(l[0].second == i);
	  L(flip);
	  R(-p);
	  flip *= -1;
	  stored = i;
	} else {
	  assert(locate(1,i).first == 0);
	}
	R(i);
	stored = l[0].first == 1 ? l[0].second : -1;
	L(flip);
	R(-i);
	flip *= -1;
      }
    }

    for (int i = 1; i < w; i++) {
      assert(r[i].first == 1 && r[i].second == i);
    }

    int ok = 1;
    {
      int flip = 1, stored = -1;
      for (int i = 1; i < w; i++) {
	if (stored != i) {
	  auto [s,p] = locate(0,i);
	  assert(s == 0);
	  L(p);
	  assert(r[0].second == i);
	  R(flip);
	  L(-p);
	  flip *= -1;
	  stored = i;
	}
	L(i);
	stored = r[0].first == 0 ? r[0].second : -1;
	R(flip);
	L(-i);
	flip *= -1;
      }
      if (flip == -1) {
	ok = 0;
      }
    }

    if (!ok) {
      cout << "SURGERY FAILED" << endl;
      continue;
    }

    for (int i = 1; i < w; i++) {
      assert(l[i].first == 0 && l[i].second == i);
      assert(r[i].first == 1 && r[i].second == i);
    }
    assert(l[0] == make_pair(-1,-1));
    assert(r[0] == make_pair(-1,-1));

    while (ej < 2*k) {
      ans += 'r';
      swap(a[ei][ej], a[ei][ej+1]);
      ej++;
    }

    cout << "SURGERY COMPLETE" << endl;
    cout << ans << endl;

    cout << "L ";
    cout << 'u';
    for (int i = 0; i < k; i++) cout << 'l';
    cout << 'd';
    for (int i = 0; i < k; i++) cout << 'r';
    cout << endl;

    cout << "R ";
    cout << 'u';
    for (int i = 0; i < k; i++) cout << 'r';
    cout << 'd';
    for (int i = 0; i < k; i++) cout << 'l';
    cout << endl;

    cout << "DONE" << endl;

    /*for (int i = 0; i < 2; i++) {
      for (int j = 0; j < w; j++) {
	assert(a[ei][ej] == i == 1 && j == 2*k ? "E" : to_string(i*w+j+1));
      }
      }*/
  }
}