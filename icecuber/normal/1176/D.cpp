#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e7;
int isprime[M], primes = 0, prime[200000];
int b[400000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i < M; i++) isprime[i] = 1;
  for (int i = 2; i < M; i++) {
    if (!isprime[i]) continue;
    if (primes < 2e5)
      prime[primes++] = i;
    for (int j = i*2; j < M; j += i)
      isprime[j] = 0;
  }

  int n;
  cin >> n;
  vector<pair<int,int>> v;
  map<int,int> in_deg, out;
  map<int,int> valc;
  for (int i = 0; i < 2*n; i++) {
    cin >> b[i];
    if (b[i] <= 2e5) {
      int c;
      if (isprime[b[i]]) {
	c = prime[b[i]-1];
      } else {
	for (int j = 0; j < primes; j++)
	  if (b[i]%prime[j] == 0) {
	    c = b[i]/prime[j];
	    break;
	  }
      }
      in_deg[c]++;
      out[b[i]] = c;
      //cout << b[i] << ' ' << c << endl;
    }
    valc[b[i]]++;
  }

  queue<int> q;
  set<int> added;
  for (int i = 0; i < 2*n; i++)
    if (!in_deg[b[i]] && !added.count(b[i])) {
      q.push(b[i]);
      added.insert(b[i]);
    }

  //for (auto p : valc) cout << p.first << ' ' << p.second << endl;
  vector<int> ans;
  while (q.size()) {
    int v = q.front();
    q.pop();
    //cout << v << " x" << valc[v] << endl;
    for (int j = 0; j < valc[v]; j++) {
      ans.push_back(v);
      assert(out.count(v));
      int o = out[v];
      --valc[o];
      if (!--in_deg[o] && valc[o]) q.push(o);

      //cout << "out: " << o << ' ' << in_deg[o] << endl;

      if (out.count(o)) {
	o = out[o];
	if (!--in_deg[o] && valc[o]) q.push(o);
      }
    }
  }
  for (int v : ans) cout << v << ' ';
  cout << endl;
}