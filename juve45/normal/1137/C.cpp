// #define _FORTIFY_SOURCE 0
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("avx")

#pragma comment(linker, "/STACK:36777216")
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 100010;
const int D = 50;

int n, k, m, nrc, d, a, b, dp[N * D], ans[N * D], cc[N * D], anss;
int use[N * D], dbg;
char buffer[D];
string open[N];
vector <int> v[N], c[N * D], vt[N], gt[N * D];
stack <int> s;
int nr = 0;


void dfs1(int k) {
	// dbg(k);
	nr++;
	if(k > N*D) {
		cout << "k is " << k << '\n';
		exit(0);
	}
	// if(dbg && nr > 10000) exit(0);
  use[k]=1;
  int day = (k % d + 1) % d;
  for(auto i : v[k / d])
    if(!use[i * d + day])
      dfs1(i * d + day);
	// dbg(k);
  s.push(k);
}
 
void dfs2(int k) {
  use[k]=1;
  int day = (d + k % d - 1) % d;
  for(auto i : vt[k / d])
    if(!use[i * d + day])
      dfs2(i * d + day);
  c[nrc].push_back(k);
  cc[k] = nrc;
}

int get_ans(int ind) {
	int ret = 0;
	for(auto i : c[ind])
		if(dp[i / d] != ind && open[i / d][i % d] == '1')
			dp[i / d] = ind, ret++;
	return ret;
}

void ctc() {
	for(int i = d;i <= n * d + d - 1; i++)
    if(!use[i])
      dfs1(i);
  // dfs1(d);
  // dbg_v(use, 20);	
  memset(use, 0, sizeof use);

  while(!s.empty()) {    
    int a = s.top();
    s.pop();
    if(!use[a])
      nrc++, dfs2(a);
  }
}

inline int get_dp(int node) {
	if(use[node]) return dp[node];
	use[node] = 1;

	for(auto i : gt[node])
		dp[node] = max(dp[node], ans[node] + get_dp(i));
	return dp[node];
}


int main() {
	// cin >> n >> m >> d;
	scanf("%d %d %d", &n, &m, &d);

	if(n == 99998 && m == 99999) {
		dbg = 1;
	}

	for(int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		vt[b].push_back(a);
	}

	for(int i = 1; i <= n; i++){
		scanf("%s", buffer);
		open[i] = buffer;
	}

	ctc();


  for(int i = 1; i <= nrc; i++)
  	ans[i] = get_ans(i);
  memset(dp, 0, sizeof dp);

  for(int i = 1; i <= nrc; i++) {
  	for(auto j : c[i])
  		for(auto k : v[j / d]) {
  			int day = (j % d + 1) % d;
  			int to = k * d + day;

  			if(i != cc[to] && dp[cc[to]] != i)
  				gt[cc[to]].push_back(i), dp[cc[to]] = i;
  		}
  }

  for(int i = 1; i <= n; i++)
  	v[i].clear(), vt[i].clear();

  int start = cc[1 * d];
  memset(dp, 0, sizeof dp);
  memset(use, 0, sizeof use);

  for(int i = 1; i <= nrc; i++)
  	dp[i] = -1e9;
  
  use[start] = 1;
  dp[start] = ans[start];

  for(int i = 1; i <= nrc; i++)
  	anss = max(anss, get_dp(i));

	printf("%d\n", anss);
}