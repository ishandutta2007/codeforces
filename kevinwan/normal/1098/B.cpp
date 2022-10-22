#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
const int mn = 3e5 + 10;
int n, m,bes;
string s[mn],c[mn];
char k[2][2];
bool dir;
bool pr;
void idk(char a[2][2]) {
	int th = 0,i,j;
	for (i = 0; i < n; i++) {
		int k1=0, k2=0;
		for (j = 0; j < m; j++)if (s[i][j] != a[i & 1][j & 1])k1++;
		for (j = 0; j < m; j++)if (s[i][j] != a[i & 1][j & 1^1])k2++;
		if (k1 < k2)for (j = 0; j < m; j++)c[i][j] = a[i & 1][j & 1];
		else for (j = 0; j < m; j++)c[i][j] = a[i & 1][j & 1^1];
		th += min(k1, k2);
	}
	if (th < bes)bes = th, memcpy(k, a, sizeof(a)),dir=0;
	if (pr)for (i = 0; i < n; i++)cout << c[i] << '\n';
}
void idk1(char a[2][2]) {
	int th = 0,i,j;
	for (i = 0; i < m; i++) {
		int k1 = 0, k2 = 0;
		for (j = 0; j < n; j++)if (s[j][i] != a[i & 1][j & 1])k1++;
		for (j = 0; j < n; j++)if (s[j][i] != a[i & 1][j & 1^1])k2++;
		if (k1 < k2)for (j = 0; j < n; j++)c[j][i] = a[i & 1][j & 1];
		else for (j = 0; j < n; j++)c[j][i] = a[i & 1][j & 1 ^ 1];
		th += min(k1, k2);
	}
	if (th < bes)bes = th, memcpy(k, a, sizeof(a)), dir = 1;
	if (pr)for (i = 0; i < n; i++)printf("%s\n", c[i].c_str());
}
char die[2][2];
char ddd[] = "AGCT";
void dk(int a,int b,int c,int d) {
	die[0][0] = ddd[a];
	die[0][1] = ddd[b];
	die[1][0] = ddd[c];
	die[1][1] = ddd[d];
	idk(die);
	idk1(die);
}
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)cin >> s[i],c[i].resize(m);
	bes = 0x3f3f3f3f;
	dk(0, 1, 2, 3);
	dk(0, 2, 1, 3);
	dk(0, 3, 1, 2);
	dk(1, 2, 0, 3);
	dk(1, 3, 0, 2);
	dk(2, 3, 0, 1);
	pr = 1;
	if (dir)idk1(k);
	else idk(k);
}