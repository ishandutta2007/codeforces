#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int a[MAXN], b[MAXN];
ll sb[MAXN];
ll sm;

ll query(){
	int x = lower_bound(sb, sb + (m - n) + 1, -sm) - sb;
	ll ans = 1ll << 60;
	for (int i = max(0, x - 2); i <= min(m - n, x + 2); i++)
		ans = min(ans, abs(sb[i] + sm));
	return ans;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	int q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	sm = 0;
	sb[0] = 0;
	for (int i = 1, inv = 1; i <= n; i++, inv *= -1){
		sm += a[i] * inv;
		sb[0] -= b[i] * inv;
	}
	for (int i = 1, inv = ((n & 1) ? -1 : 1); i <= m - n; i++){
		sb[i] = -(sb[i - 1] + b[i]) + inv * b[i + n];
	}
	sort(sb, sb + (m - n) + 1);
	cout << query() << endl;
	for (int i = 1; i <= q; i++){
		int x, L, R;
		cin >> L >> R >> x;
		sm += x * (R % 2);
		sm -= x * ((L - 1) % 2);
		cout << query() << endl;
	}
}

void printans(){

}


int main(){
	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}