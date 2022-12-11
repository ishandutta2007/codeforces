#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int cnt[1100][6];
char s[1100];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n; i++) {
		scanf ("%s", s + 1);
		for (int j = 1;j <= m; j++) cnt[j][s[j] - 'A']++;
	}
	int ans = 0;
	for (int i = 1;i <= m; i++) {
		int x;
		scanf ("%d", &x);
		int tmp = 0;
		for (int j = 0;j <= 4; j++) tmp = max(tmp, cnt[i][j]);
		ans += x * tmp;
	}
	cout << ans << endl;
	return 0;
}