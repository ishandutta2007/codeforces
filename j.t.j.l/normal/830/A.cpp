#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;

int n, m;

void prework(){

}

void read(){

}

int a[MAXN], b[MAXN];
ll f[MAXN][MAXN];

void solve(int casi){
	int p;
//	cout << "Case #" << casi << ": ";
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= m; j++){
			f[i][j] = max(f[i - 1][j - 1], 0ll + abs(a[i] - b[j]) + abs(b[j] - p));
		}
		for (int j = i + 1; j <= m; j++)
			f[i][j] = min(f[i][j], f[i][j - 1]);
	}
	printf("%lld\n", f[n][m]);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}