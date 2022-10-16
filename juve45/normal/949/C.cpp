#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

using namespace std;

const int N = 100100;
int n, k, m, h, u[N], use[N], c1, c2, b1, b2, nrc, ans, ind, cc[N];
stack <int> s;
vector <int> v[N], vt[N], c[N];

set <int> g[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

void dfs1(int k) {
  use[k]=1;
  for(auto i : v[k])
    if(!use[i])
      dfs1(i);
  s.push(k);
}
 
void dfs2(int k) {
  use[k]=1;
  for(auto i : vt[k])
    if(!use[i])
      dfs2(i);
  c[nrc].push_back(k);
  cc[k] = nrc;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> h; ans = n + 1;

	for(int i = 1; i <= n; i++)
		cin >> u[i];

	for(int i = 1; i <= m; i++) {
		cin >> b1 >> b2;

		assert(u[b1] != u[b2]);

		if(u[b1] > u[b2]) swap(b1, b2);

		if(u[b1] == 0 && u[b2] == h - 1) {
			v[b2].push_back(b1);
			vt[b1].push_back(b2);
		} 
		if(u[b1] + 1 == u[b2]) {
			v[b1].push_back(b2);
			vt[b2].push_back(b1);
		}
	}

	for(int i = 1; i <= n; i++)
		if(v[i].size() == 0)
			return cout << "1\n" << i << '\n', 0;

	// hopa, tre sa fac ctc
	for(int i = 1; i <= n; i++)
    if(!use[i])
      dfs1(i);
     
  memset(use, 0, sizeof use);
     
  while(!s.empty()) {        
    int a = s.top();
    s.pop();
    if(!use[a])
      nrc++, dfs2(a);
  }

  for(int i = 1; i <= nrc; i++)
  	for(auto j : c[i])
  		for(auto k : v[j])
  			g[i].insert(cc[k]);

  for(int i = 1; i <= nrc;i++)
  	if(ans > c[i].size() && c[i].size() > 1 && g[i].size() == 1)
  		ans = c[i].size(), ind = i;
  dbg(ind);
 	cout << c[ind];
  return 0;
}