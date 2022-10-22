#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> ask(vector<pair<int,int>> q) {
  if (q.empty()) return vector<int>();
  cout << "Q " << q.size();
  for (auto p : q)
    cout << ' ' << p.first+1 << ' ' << p.second+1;
  cout << endl;
  string s;
  cin >> s;
  if (s == "-1") exit(0);
  vector<int> r;
  for (char c : s)
    r.push_back(c-'0');
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> eq(n-1), par(n);

    vector<pair<int,int>> q0, q1, q2, q3;
    for (int i = 0; i+1 < n; i += 2)
      q0.emplace_back(i,i+1);
    vector<int> a0 = ask(q0);
    for (int i = 0; i+1 < n; i += 2) eq[i] = a0[i/2];

    for (int i = 1; i+1 < n; i += 2)
      q1.emplace_back(i,i+1);
    vector<int> a1 = ask(q1);
    for (int i = 1; i+1 < n; i += 2) eq[i] = a1[i/2];

    /*cerr << "eq: ";
    for (int i : eq) cerr << i << ' ';
    cerr << endl;*/

    vector<int> v;
    int last;
    for (int i = 0; i < n; i++) {
      if (!i || !eq[i-1]) {
	v.push_back(i);
	last = i;
      }
      par[i] = v.size()-1;
    }
    int m = v.size();
    for (int i = 0; i < m-2; i++)
      (i%4 < 2 ? q2 : q3).emplace_back(v[i], v[i+2]);

    vector<int> a2 = ask(q2), eq2(m);
    int iter = 0;
    for (int i = 0; i < m-2; i++)
      if (i%4 < 2) eq2[i] = a2[iter++];

    vector<int> a3 = ask(q3);
    iter = 0;
    for (int i = 0; i < m-2; i++)
      if (i%4 >= 2) eq2[i] = a3[iter++];


    cerr << "eq2: ";
    for (int i : eq2) cerr << i << ' ';
    cerr << endl;

    vector<int> ans(m);
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 0; i < m-2; i++)
      ans[i+2] = eq2[i] ? ans[i] : (3-ans[i]-ans[i+1])%3;
    /*for (int i = 0; i < m; i++)
      cerr << ans[i] << ' ';
    cerr << endl;
    for (int i = 0; i < n; i++)
      cerr << ans[par[i]] << ' ';
      cerr << endl;*/
    vector<int> col[3];
    for (int i = 0; i < n; i++)
      col[ans[par[i]]].push_back(i+1);
    cout << "A";
    for (int i = 0; i < 3; i++)
      cout << ' ' << col[i].size();
    cout << endl;
    for (int i = 0; i < 3; i++) {
      for (int j : col[i])
	cout << j << ' ';
      cout << endl;
    }
  }
}