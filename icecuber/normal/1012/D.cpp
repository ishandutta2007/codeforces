#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> f(string s) {
  char last = ' ';
  vector<int> ans;
  for (int i = 0; i < (int)s.size(); i++) {
    char c = s[i];
    if (c != last) ans.push_back(i);
    last = c;
  }
  return ans;
}

map<pair<int,int>, int> mem;
int brutecost(int a, int b) {
  if (a > b) swap(a, b);
  if (a == 1 && b == 1) return 0;
  if (!mem.count({a,b})) {
    int ans = a+b;
    for (int u = 0; u < a; u++) {
      for (int v = 0; v < b; v++) {
	int na = a-u+v, nb = b-v+u;
	if ((a-u)%2 == (b-v)%2) {
	  if (v) na--;
	  if (u) nb--;
	}
	if (abs(nb-na) < abs(a-b) || na+nb < a+b)
	  ans = min(ans, brutecost(na, nb)+1);
      }
    }
    mem[{a,b}] = ans;
  }
  return mem[{a,b}];
}

int cost(int a, int b) {
  if (a > b) swap(a, b);
  if (a == 1 && b == 1) return 0;
  if (a == b) return a-1;

  if ((b-a)%4 == 2) {
    return cost((a+b)/2, (a+b)/2)+1;
  } else if ((b-a)%4 == 0) {
    if (a > 1) {
      return cost((a+b)/2-1, (a+b)/2-1)+1;
    } else {
      return cost((a+b-1)/2, (a+b)/2)+1;
    }
  } else if ((b-a)%4 == 1) {
    return cost((a+b)/2, (a+b)/2)+1;
  } else {
    assert((b-a)%4 == 3);
    if (a > 1) {
      return cost((a+b)/2-1, (a+b+1)/2-1)+1;
    } else {
      return cost((a+b)/2, (a+b+1)/2)+1;
    }
  }
}

vector<pair<int,int>> ans;
void solve(string a, string b) {
  vector<int> va = f(a);
  vector<int> vb = f(b);
  int fa = va.size(), fb = vb.size();
  //cout << a << ' ' << b << endl;
  //cout << fa << ' ' << fb << endl;

  int ans0 = ans.size();
  int swapped = 0;
  if (fa > fb) {
    swap(a, b);
    swap(va, vb);
    swap(fa, fb);
    swapped = 1;
  }

  if (fa == fb) {
    int as = a.size(), bs = b.size();
    for (int i = fa-1; i; i--) {
      ans.emplace_back(as-va[i], bs-vb[i]);
      as += ans.back().second-ans.back().first;
      bs -= ans.back().second-ans.back().first;

      /*{
	auto [x, y] = ans.back();
	string ea = a.substr(x, b.size()-x);
	a.resize(x);
	string eb = b.substr(y, b.size()-y);
	b.resize(y);
	a += eb;
	b += ea;
	}*/
    }
    //assert(a.count('b')%a.size() == 0);
    //assert(b.count('b')%b.size() == 0);
  } else {
    int x = -1, y = -1;

    int d = abs(fb-fa);
    if (d%4 == 2) {
      x = 0;
      y = d/2;
    } else if (d%4 == 0) {
      if (fa == 1) {
	x = 0;
	y = d/2;
      } else {
	x = 1;
	y = d/2+1;
      }
    } else if (d%4 == 1) {
      x = 0;
      y = d/2+1;
    } else {
      assert(d%4 == 3);
      if (fa == 1) {
	x = 0;
	y = d/2;
      } else {
	x = 1;
	y = d/2+1;
      }
    }

    va.push_back(a.size());
    vb.push_back(b.size());
    x = va[fa-x];
    y = vb[fb-y];

    //cout << a << ' ' << b << endl;
    //cout << x << ' ' << y << endl;

    ans.emplace_back(a.size()-x, b.size()-y);

    string ea = a.substr(x, a.size()-x);
    a.resize(x);
    string eb = b.substr(y, b.size()-y);
    b.resize(y);
    a += eb;
    b += ea;

    solve(a, b);
  }

  if (swapped)
    for (int i = ans0; i < (int)ans.size(); i++)
      ans[i] = {ans[i].second, ans[i].first};
}

int main() {
  /*for (int i = 1; i < 100; i++)
    for (int j = 1; j < 100; j++)
      if (cost(i,j) != brutecost(i,j)) {
	cout << i << ' ' << j << endl;
	cout << cost(i,j) << endl;
	cout << brutecost(i,j) << endl;
	exit(0);
      }
      return 0;*/
  ios::sync_with_stdio(0); cin.tie(0);
  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int fa = f(a).size(), fb = f(b).size();
  int need;
  if (a[0] == b[0]) {
    need = min(cost(fa+1, fb), cost(fa, fb+1));
    if (cost(fa+1, fb) <= cost(fa, fb+1)) {
      a.insert(a.begin(), a[0]^'a'^'b');
    } else {
      b.insert(b.begin(), b[0]^'a'^'b');
    }
  }
  else {
    need = cost(fa, fb);
  }
  solve(a, b);
  cout << ans.size() << endl;
  for (auto [x,y] : ans) cout << x << ' ' << y << '\n';
  assert((int)ans.size() == need);
}