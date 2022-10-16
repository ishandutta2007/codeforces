#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) {for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 100100;
int n, cnt, b[N], c[N], nr[2 * N];

vector <int> v[2 * N], res;
map <int, int> val;

void norm(int value) {
	if(!val.count(value)) {
		val[value] = ++cnt;
		nr[cnt] = value;
	}
}

void erase_edge(int a, int b) {
    v[a].erase(v[a].begin());
    for(int i=0;i<v[b].size();i++)
    if(v[b][i]==a) {
            v[b].erase(v[b].begin()+i);
            return;
    }
}
 
void euler(int start) {
  stack <int> s;

  s.push(start);

  while(!s.empty()) {

    int x=s.top(); 
    
    if(v[x].size()){
      s.push(v[x][0]);
      erase_edge(x, v[x][0]);
    }
    else{
      if(s.size()!=1)
      res.push_back(nr[x]);//cout << nr[x] <<" ";
      s.pop();
    }

  }
  res.push_back(nr[start]);
  // cout<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;
	for(int i = 1; i < n; i++) cin >> b[i], norm(b[i]);
	for(int i = 1; i < n; i++) cin >> c[i], norm(c[i]);

	for(int i = 1; i < n; i++) {
		if(b[i] > c[i]) {
			cout << "-1\n";
			return 0;
		}
		b[i] = val[b[i]], c[i] = val[c[i]];
	}

	for(int i = 1; i < n; i++) {
		v[b[i]].push_back(c[i]);
		v[c[i]].push_back(b[i]);
	}

	vector <int> p;
	for(int i = 1; i <= cnt; i++)
		if(v[i].size() % 2 == 1)
			p.push_back(i);
	
	// dbg(p);

	if(p.size() == 0 || p.size() == 2) {
		int start = 1;
		if(p.size() == 2) start = p[0];
		euler(start);
		if(res.size() == n) cout << res << '\n';
		else cout << "-1\n";
	} else cout << "-1\n";
}