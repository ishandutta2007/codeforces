#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
  string base_name;
  char op;
  int a, b;
  bool operator==(Node o) {
    return base_name == o.base_name && op == o.op && a == o.a && b == o.b;
  }
  void dump() {
    if (base_name.size()) cout << base_name << endl;
    else cout << a << ' ' << op << ' ' << b << endl;
  }
};

vector<Node> term;

set<string> used;
string genName() {
  static int nextTry = 0;
  string s;
  do {
    s = "";
    int n = nextTry++;
    for (int i = 0; i < 4; i++) {
      s += char(n%26+'a');
      n /= 26;
    }
  } while (used.count(s));
  used.insert(s);
  return s;
}

vector<string> ans;
string done[5000];
string dfs(int p, int last = 1) {
  if (done[p].size()) return done[p];
  if (term[p].base_name.empty()) {
    string a = dfs(term[p].a, 0);
    string b = dfs(term[p].b, 0);
    string name = last ? "res" : genName();
    ans.push_back(name+'='+a+term[p].op+b);
    return done[p] = name;
  } else {
    if (last) {
      if (term[p].base_name != "res")
	ans.push_back("res="+term[p].base_name);
    }
    return done[p] = term[p].base_name;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  map<string, int> mi;
  while (t--) {
    string line;
    cin >> line;
    vector<string> v;
    v.push_back("");
    char op = 0;
    for (char c : line) {
      if (c == '=')
	v.push_back("");
      else if (c == '$' || c == '^' || c == '#' || c == '&') {
	op = c;
	v.push_back("");
      } else
	v.back() += c;
    }
    for (int i = 1; i < v.size(); i++)
      if (!mi.count(v[i])) {
	mi[v[i]] = term.size();
	term.push_back({v[i]});
      }
    for (string s : v) used.insert(s);

    /*
    cout << v[0] << " = " << v[1];
    if (op) cout << ' ' << op << ' ' << v[2];
    cout << endl;
    */
    if (!op) mi[v[0]] = mi[v[1]];
    else {
      Node new_term = {"", op, mi[v[1]], mi[v[2]]};
      int i = find(term.begin(), term.end(), new_term)-term.begin();
      if (i == term.size()) {
	mi[v[0]] = term.size();
	term.push_back({new_term});
      } else {
	mi[v[0]] = i;
      }
    }
  }
  /*for (Node t : term)
    t.dump();
    return 0;*/
  if(!mi.count("res")) {
    mi["res"] = term.size();
    term.push_back({"res"});
  }
  dfs(mi["res"]);
  cout << ans.size() << endl;
  for (string s : ans)
    cout << s << endl;
}