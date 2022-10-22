#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  ll Alice = 0, first = 0, second = 0;
  /*for (int a = 1; a <= m; a++) {
    for (int b = 1; b <= m; b++) {
      int ok = 0, doubles = 0;
      for (int i = 0; i < n; i++) {
	int w = v[i]%(a+b);
	if (a <= w && w < b) ok = 1;
	if (a*2 <= w) doubles++;
      }
      if (doubles >= 2) ok = 1;1
      Alice += ok;
    }
    }*/
  for (int s = 2; s <= m*2; s++) {
    int Aa_max = 0;
    int a_min = max(1,s-m);
    vector<int> doubles;
    vector<pair<int,int>> p;
    for (int i = 0; i < n; i++) {
      int w = v[i]%s;
      Aa_max = max(Aa_max, min(w, s-w-1));
      doubles.push_back(w/2);
      p.emplace_back(w,1);
    }

    sort(doubles.rbegin(), doubles.rend());
    int doubles_a = doubles[0], doubles_b = doubles[0];
    if (n > 1) {
      Aa_max = max(Aa_max, doubles[1]);
      doubles_a = doubles[1];
    }
    Alice += max(0, Aa_max+1-a_min);

    p.emplace_back(doubles_a, 0);
    p.emplace_back(doubles_b, 0);
    p.emplace_back(s/2,0);
    sort(p.begin(), p.end());

    /*cout << "X: ";
    for (int i : p) cout << i << ' ';
    cout << endl;*/
    int pref = 0, last = 0;
    for (auto pair : p) {
      int i = pair.first;
      last = max(last, max(Aa_max+1, a_min)-1);
      if (i > last) {
	//cout << i << ' ' << pref << endl;
	int v = 2*(i-last)-(i*2==s);
	if (pref%2 != n%2) {
	  first += v;
	} else {
	  if (i >= doubles_a && i <= doubles_b)
	    Alice += v/2;
	  else
	    second += v;
	}
      }
      if (i == s/2) break;
      last = i;
      pref += pair.second;
    }
    /*{
    vector<int> x(s,0);
    for (int i : p) x[i]++;
    int pref = 0;
    for (int i = 0; i*2 <= s; i++) {
      if (i > Aa_max && i >= a_min) {
	cout << i << ' ' << pref << endl;
	(pref%2!=n%2 ? first : second) += 1+(i*2 < s);
      }
      pref += x[i];
    }
    }*/
  }
  cout << Alice << ' ' << Alice << ' ' << first << ' ' << second << endl;
}