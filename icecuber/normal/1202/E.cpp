#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct AhoCorasick {
  enum {alpha = 26, first = 'a'};
  struct Node {
    // (nmatches is optional )
    int back, next[alpha], start = -1, end = -1, nmatches = 0;
    Node(int v) { memset(next, v, sizeof(next)); }
  };
  vector<Node> N;
  vector<int> backp;
  void insert(string& s, int j) {
    assert(!s.empty());
    int n = 0;
    trav(c, s) {
      int& m = N[n].next[c - first];
      if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
      else n = m;
    }
    if (N[n].end == -1) N[n].start = j;
    backp.push_back(N[n].end);
    N[n].end = j;
    N[n].nmatches++;
  }
  AhoCorasick(vector<string>& pat) {
    N.emplace_back(-1);
    rep(i,0,sz(pat)) insert(pat[i], i);
    N[0].back = sz(N);
    N.emplace_back(0);
    queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
      int n = q.front(), prev = N[n].back;
      rep(i,0,alpha) {
	int &ed = N[n].next[i], y = N[prev].next[i];
	if (ed == -1) ed = y;
	else {
	  N[ed].back = y;
	  (N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
	    = N[y].end;
	  N[ed].nmatches += N[y].nmatches;
	  q.push(ed);
	}
      }
    }
  }
  vi find(string word) {
    int n = 0;
    vi res; // l l count = 0;
    trav(c, word) {
      n = N[n].next[c - first];
      res.push_back(N[n].end);
      // count += N[n ] . nmatches ;
    }
    return res;
  }
  vector<vi> findAll(vector<string>& pat, string word) {
    vi r = find(word);
    vector<vi> res(sz(word));
    rep(i,0,sz(word)) {
      int ind = r[i];
      while (ind != -1) {
	res[i - sz(pat[ind]) + 1].push_back(ind);
	ind = backp[ind];
      }
    }
    return res;
  }


  void solve(string word, ll*count) {
    int n = 0;
    for (int i = 0; i < word.size(); i++) {
      n = N[n].next[word[i] - first];
      count[i+1] = N[n].nmatches;
    }
  }
};

const int nax = 2e5+10;
ll endsat[nax];
ll startsat[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string t;
  cin >> t;
  int n;
  cin >> n;
  vector<string> pat(n);
  for (int i = 0; i < n; i++)
    cin >> pat[i];
  AhoCorasick A(pat);
  A.solve(t, endsat);

  for (int i = 0; i < n; i++)
    reverse(pat[i].begin(), pat[i].end());
  AhoCorasick B(pat);
  reverse(t.begin(), t.end());
  B.solve(t, startsat);

  int m = t.size();
  ll ans = 0;
  for (int i = 0; i <= m; i++) {
    ans += (ll)startsat[m-i]*endsat[i];
  }
  cout << ans << endl;
}