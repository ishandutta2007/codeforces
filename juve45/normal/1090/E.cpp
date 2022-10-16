#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define dbg(x) cerr<<#x": "<<(x)<<endl
#define dbg_p(x) cerr<<#x": "<<(x).first<<' '<<(x).second<<endl
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<endl;}
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define INF 2000000010
#define MOD 1000000007
#define ST_SIZE 1048600
#define QMAX 
#define NMAX 

template<typename T1, typename T2>
ostream& operator <<(ostream &out, const pair<T1, T2> &item) {
	out << '(' << item.first << ", " << item.second << ')';
	return out;
}

template<typename T>
ostream& operator <<(ostream &out, const vector<T> &v) {
	for(const auto &item : v) out << item << ' ';
	return out;
}

int x[100], y[100];
int used[10][10];
pii pred[10][10];
vector<string> ans;

int dl[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dc[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

string get(pii a, pii b) {
	string s;
	s += 'a' + a.se;
	s += '1' + a.fi;
	s += '-';
	s += 'a' + b.se;
	s += '1' + b.fi;
	return s;
}

void move(pii a, pii init) {
	if(a == init) return;
	
	auto b = pred[a.fi][a.se];
	
	if(b.fi < 0 || b.se < 0) while(1);
	if(used[b.fi][b.se] == 1) exit(-1);
	
	if(used[b.fi][b.se]) {
		move(b, init);
		ans.push_back(get(a, b));
		
		used[a.fi][a.se] = 0;
		used[b.fi][b.se] = -1;
	} else {
		ans.push_back(get(a, b));
		used[a.fi][a.se] = 0;
		used[b.fi][b.se] = 1;
		
		move(b, init);
	}	
}

pii bfs(pii p) {
	if(used[p.fi][p.se]) return p;
	
	memset(pred, -1, sizeof pred);
	queue<pii> q;
	
	pred[p.fi][p.se] = { -2, -2 };
	for(q.push(p); !q.empty(); q.pop()) {
		p = q.front();
		
		for(int i = 0; i < 8; ++i) {
			pii nxt = { p.fi + dl[i], p.se + dc[i] };
			
			if(nxt.fi < 0 || nxt.fi > 7 || nxt.se < 0 || nxt.se > 7) continue;
			
			if(pred[nxt.fi][nxt.se] == make_pair(-1, -1)) {
				pred[nxt.fi][nxt.se] = p;
				if(used[nxt.fi][nxt.se] == 1) return nxt;
				
				q.push(nxt);
			}
		}
	}
	
	return { -1, -1 };
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int i, j, nr, n;
	string str;
	
	// for(char ch = 'a'; ch <= 'h'; ++ch)
	// 	for(i = 1; i <= 8; ++i) cout << ch << i << '\n';
	// 	return 0;
	
	cin >> n;
	for(i = 0; i < n; ++i) {
		cin >> str;
		y[i] = str[0] - 'a';
		x[i] = str[1] - '1';
		used[x[i]][y[i]] = 1;
	}
	
	for(i = j = 0, nr = 1; nr <= n; ++nr) {
		pii init = { i, j };
		auto p = bfs(init);
		// dbg(p);
		
		move(p, init);
		used[i][j] = -1;
		
		if(++j == 8) ++i, j = 0;
	}
	
	cout << ans.size() << '\n';
	for(const auto &str : ans) cout << str << '\n';
	
	return 0;
}