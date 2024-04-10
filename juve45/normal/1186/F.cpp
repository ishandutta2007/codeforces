#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << p.st << ' ' << p.nd; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 1001000;
int n, m, a, b, gr[N];
vector <int> v[N];
 
 set <pair<int,int> > edges;

void erase_edge(int a, int b)
{
  gr[a]--;
  gr[b]--;
  v[a].pop_back();
  if(a > b) swap(a, b);
  edges.insert({a, b});
}

bool used(int a, int b) {
  if(a > b) swap(a, b);
  return edges.count({a, b});
}
 
void euler(int start, vector <int> & path) {
  stack <int> s;
 
  s.push(start);
 
  while(!s.empty()) {
    int x = s.top();

    while(v[x].size() && used(x, v[x].back()))
      v[x].pop_back();

    if(v[x].size() && gr[v[x].back()] % 2 == 0) {
      s.push(v[x].back());
      erase_edge(x, v[x].back());
    } else {
      if(v[x].size()) {
        path.push_back(v[x].back());
        erase_edge(x, v[x].back());
      }
      path.push_back(x);
      s.pop();
      while(!s.empty()) {
        path.push_back(s.top());
        s.pop();
      }
      return;
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
    gr[a]++;
    gr[b]++;    
  }
  // dbg(v[6]);
  vector <pair<int, int> > ans;
  for(int i = 1; i <= n; i++) {
    if(gr[i] % 2 == 1) {
      vector <int> path;
      euler(i, path);
      // dbg(path);
      for(int i = 0; i + 1 < path.size(); i += 2)
        ans.push_back({path[i], path[i + 1]});
      if(path.size() % 2 == 1 && path.size() != 1)
        ans.push_back({path[path.size() - 1], path[path.size() - 2]});
    }
  }
  // dbg_ok;
  for(int i = 1; i <= n; i++) {
    if(gr[i]) {
      vector <int> path;
      euler(i, path);
      // dbg(path);
      for(int i = 0; i + 1 < path.size(); i += 2)
        ans.push_back({path[i], path[i + 1]});
    }
  }
  // dbg_v(gr, n  +1);
  cout << ans << '\n';
}