#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> vs;
map<char, int> conv;
int bc[32],n;
int k(int a, int b) {
	return (a >> b) & 1;
}
bool check(int a, int b) {
	int i, j;
	bool ret = 1;
	for (i = 0; i < n; i++) {
		for (j = 1; j < n; j++) {
			if (vs[i] == vs[j])continue;
			if (vs[i][0] == vs[j][0] && (k(b, vs[i][1]) || k(b, vs[j][1])))continue;
			if (vs[i][1] == vs[j][1] && (k(a, vs[i][0]) || k(a, vs[j][0])))continue;
			if (vs[i][0] != vs[j][0] && vs[i][1] != vs[j][1] && (k(a, vs[i][0]) || k(a, vs[j][0]) || k(b, vs[i][1]) || k(b, vs[j][1])))continue;
			return 0;
		}
	}
	return 1;
}
int main() {
	int i,j;
	conv['R'] = 0, conv['G'] = 1, conv['B'] = 2, conv['Y'] = 3, conv['W'] = 4;
	string s;
	scanf("%d", &n);
	for (i = 0; i < n; i++)cin >> s, s[0] = conv[s[0]], s[1] -= '1',vs.push_back(s);
	for (i = 1; i < 32; i++)bc[i] = bc[i - (i&-i)] + 1;
	int ans = 0x3f3f3f3f;
	for (i = 0; i < 32; i++)for (j = 0; j < 32; j++)if(check(i, j))ans=min(ans,bc[i]+bc[j]);
	printf("%d", ans);
	getchar(); getchar();
}