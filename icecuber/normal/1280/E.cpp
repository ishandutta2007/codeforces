#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
  vector<int> child;
  vector<ll> weight;
  ll ret;
  char type;
};

vector<Node> node;

ll rec1(string&s, int&i) {
  Node cur;

  while (s[i] == ' ') i++;
  if (s[i] == '*') {
    i++;
    cur.type = 'O';
    node.push_back(cur);
    return 1;
  }
  assert(s[i] == '(');
  i++;

  vector<ll> a;
  char type = '?';
  while (1) {
    a.push_back(rec1(s, i));
    cur.child.push_back((int)node.size()-1);
    while (s[i] == ' ') i++;
    char t;
    if (s[i] == 'S') {
      t = 'S';
      i++;
    } else if (s[i] == 'P') {
      t = 'P';
      i++;
    } else if (s[i] == ')') {
      i++;
      break;
    } else {
      assert(0);
    }
    if (type == '?') type = t;
    else assert(type == t);
  }

  cur.type = type;

  if (type == 'S') {
    int mini = -1;
    ll mi = 8e18;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] < mi) {
	mini = i;
	mi = a[i];
      }
    }
    assert(mini != -1);

    cur.weight = a;
    for (int i = 0; i < a.size(); i++)
      cur.weight[i] = (i==mini);

    cur.ret = mi;
    node.push_back(cur);
    return mi;
  } else if (type == 'P') {
    ll sum = 0;
    for (ll v : a) sum += v;

    cur.weight = a;

    cur.ret = sum;
    node.push_back(cur);
    return sum;
  }
  assert(0);
}

vector<ll> ans;
void rec2(Node&n, ll need) {
  //cout << n.type << ' ' << n.child.size() << endl;
  if (n.type == 'O') {
    ans.push_back(need);
  } else if (n.type == 'S') {
    for (int i = 0; i < n.child.size(); i++) {
      rec2(node[n.child[i]], need*n.weight[i]);
    }
  } else if (n.type == 'P') {
    ll sum = 0;
    for (ll v : n.weight) sum += v;
    for (int i = 0; i < n.child.size(); i++) {
      rec2(node[n.child[i]], need);
    }
  } else assert(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll need;
    cin >> need;
    string line;
    getline(cin, line);
    int i = 0;
    node.clear();
    ans.clear();
    ll x = rec1(line, i);
    i = 0;
    rec2(node.back(), need*x);
    cout << "REVOLTING ";
    for (ll v : ans) cout << v << ' ';
    cout << endl;
  }
}