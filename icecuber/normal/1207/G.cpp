#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
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



  int getPos(string word) {
    int n = 0;
    trav(c, word) {
      n = N[n].next[c - first];
    }
    return N[n].end;
  }
};





vector<string> upatterns;

const int nax = 4e5+10;
map<char,int> trie[nax];
int ind[nax];
int len = 1;
vector<pair<int,int>> query[nax];
int ans[nax];
int matches[nax];

void dfs(int p, AhoCorasick&aho, int ahi = 0) {//, string path = "") {
  //cout << "Node: " << path << endl;
  if (1) {
    int ind = aho.N[ahi].end;
    //cout << ahi << ' ';
    while (ind != -1) {
      //cout << upatterns[ind] << ' ';
      matches[ind]++;
      ind = aho.backp[ind];
    }
    //cout << endl;
  }
  for (auto q : query[p]) {
    ans[q.first] = matches[q.second];
  }
  for (auto c : trie[p]) {
    int nahi = aho.N[ahi].next[c.first-aho.first];
    dfs(c.second, aho, nahi);//, path+c.first);
  }
  if (1) {
    int ind = aho.N[ahi].end;
    while (ind != -1) {
      matches[ind]--;
      ind = aho.backp[ind];
    }
  }
}

void print(int p, string path = "") {
  cout << path << endl;
  for (auto c : trie[p]) {
    print(c.second, path+c.first);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    int p = 0;
    char c;
    if (t == 1) {
      cin >> c;
    } else if (t == 2) {
      cin >> p >> c;
      p = ind[p-1];
    }
    if (!trie[p].count(c)) {
      trie[p][c] = len++;
    }
    ind[i] = trie[p][c];
  }

  int q;
  cin >> q;
  map<string,vector<pair<int,int>>> patterns;
  for (int i = 0; i < q; i++) {
    int p;
    string t;
    cin >> p >> t;
    patterns[t].push_back({ind[p-1],i});
  }
  for (auto p : patterns)
    upatterns.push_back(p.first);
  /*for (string s : upatterns)
    cout << "|" << s << "| ";
    cout << endl;*/
  AhoCorasick aho(upatterns);
  /*for (int i : aho.find("dada"))
    cout << i << endl;
    return 0;*/
  for (auto p : patterns) {
    int i = aho.getPos(p.first);
    //cout << upatterns[i] << ' ' << p.first << endl;
    for (auto q : p.second)
      query[q.first].push_back({q.second, i});
  }

  dfs(0, aho);
  for (int i = 0; i < q; i++)
    cout << ans[i] << '\n';
}