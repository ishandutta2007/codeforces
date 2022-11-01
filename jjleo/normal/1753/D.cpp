#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

int n, m;
string s[maxn];
typedef tuple<ll, int, int> t;
priority_queue<t, vector<t>, greater<t> > q;
int a, b;
vector<vector<ll> > d(n, vector<ll>(m, 1e18));
vector<vector<bool> > vis(n, vector<bool>(m, false));

char get(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < m) return s[x][y];
	return 0;
}

void tran(int x, int y, int xx, int yy, int z){
	if(d[xx][yy] > d[x][y] + z){
		d[xx][yy] = d[x][y] + z;
		q.push(make_tuple(d[xx][yy], xx, yy));
	}
}

int main(){
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for(int i = 0;i < n;i++) cin >> s[i];
//	vector<vector<ll> > d(n, vector<ll>(m, 1e18));
//	vector<vector<bool> > vis(n, vector<bool>(m, false));
	d = vector<vector<ll>>(n, vector<ll>(m, 1e18));
	vis = vector<vector<bool>>(n, vector<bool>(m, false));
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++){
		if(s[i][j] == '.'){
			d[i][j] = 0;
			q.push(make_tuple(0, i, j));
		}
	}
	while(!q.empty()){
		int x = get<1>(q.top()), y = get<2>(q.top());q.pop();
		if(vis[x][y]) continue;
		vis[x][y] = true;
		if(get(x - 1, y) == 'D' && get(x - 2, y) == 'U'){
			tran(x, y, x - 2, y, b);
		}
		if(get(x + 1, y) == 'U' && get(x + 2, y) == 'D'){
			tran(x, y, x + 2, y, b);
		}
		if(get(x, y - 1) == 'R' && get(x, y - 2) == 'L'){
			tran(x, y, x, y - 2, b);
		}
		if(get(x, y + 1) == 'L' && get(x, y + 2) == 'R'){
			tran(x, y, x, y + 2, b);
		}
		if(get(x - 1, y) == 'R' && get(x - 1, y - 1) == 'L'){
			tran(x, y, x - 1, y - 1, a);
		}
		if(get(x - 1, y) == 'L' && get(x - 1, y + 1) == 'R'){
			tran(x, y, x - 1, y + 1, a);
		}
		if(get(x + 1, y) == 'R' && get(x + 1, y - 1) == 'L'){
			tran(x, y, x + 1, y - 1, a);
		}
		if(get(x + 1, y) == 'L' && get(x + 1, y + 1) == 'R'){
			tran(x, y, x + 1, y + 1, a);
		}
		if(get(x, y - 1) == 'D' && get(x - 1, y - 1) == 'U'){
			tran(x, y, x - 1, y - 1, a);
		}
		if(get(x, y - 1) == 'U' && get(x + 1, y - 1) == 'D'){
			tran(x, y, x + 1, y - 1, a);
		}
		if(get(x, y + 1) == 'D' && get(x - 1, y + 1) == 'U'){
			tran(x, y, x - 1, y + 1, a);
		}
		if(get(x, y + 1) == 'U' && get(x + 1, y + 1) == 'D'){
			tran(x, y, x + 1, y + 1, a);
		}
	}
	ll ans = 1e18;
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++){
		if(i - 1 >= 0) ans = min(ans, d[i][j] + d[i - 1][j]);
		if(j - 1 >= 0) ans = min(ans, d[i][j] + d[i][j - 1]);
	}	
	printf("%lld\n", ans == 1e18 ? -1 : ans);
}