#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int mo = 998244353;
const int N = 3010;

int g, x, y, z, n, m, a, b, st[N][N];
deque<int> q[N], qe;
ll ans;

int val(int j) {
	return st[q[j].front()][j];
}

int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	scanf("%d%d%d%d", &g, &x, &y, &z);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			st[i][j] = g; //printf("-%d-\n", g);
			g = (g * 1ll * x % z + y) % z;
		}
	}
	for(int j = 1; j <= m; j ++) {
		for(int i = 1; i <= a; i ++) {
			while(q[j].size() && st[q[j].back()][j] >= st[i][j]) q[j].pop_back();
			q[j].push_back(i);
		}
	}
	for(int i = 1; i <= n - a + 1; i ++) {
		qe.clear();
		for(int j = 1; j <= b; j ++) {
			while(qe.size() && val(qe.back()) >= val(j)) qe.pop_back();
			qe.push_back(j);
		}
		for(int j = 1; j <= m - b + 1; j ++) {
			ans += val(qe.front());
//			printf("[%lld]\n", val(qe.front()));
			if(j == m - b + 1) break ;
			int x = j + b;
			while(qe.size() && qe.front() <= j) qe.pop_front();
			while(qe.size() && val(qe.back()) >= val(x)) qe.pop_back();
			qe.push_back(x);
		}
		if(i == n - a + 1) break ;
		for(int j = 1; j <= m; j ++) {
			while(q[j].size() && q[j].front() <= i) q[j].pop_front();
			int x = i + a;
			while(q[j].size() && st[q[j].back()][j] >= st[x][j]) q[j].pop_back();
			q[j].push_back(x);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}