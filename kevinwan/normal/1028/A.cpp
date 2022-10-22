#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[115];
pair<int, int> big, small;
int main() {
	int n, m,i,j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)cin >> s[i];
	small = make_pair(0x3f3f3f3f, 0x3f3f3f3f);
	for (i = 0; i < n; i++)for (j = 0; j < m; j++)if (s[i][j] == 'B')big = max(big, make_pair(i, j)), small = min(small, make_pair(i, j));
	printf("%d %d", (big.first + small.first) / 2 + 1, (big.second + small.second) / 2 + 1);
	getchar(); getchar();
}