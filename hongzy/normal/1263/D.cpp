#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 1e6 + 10;
int f[27];
bool use[27];
int find(int u) {
	return f[u] == u ? u : f[u] = find(f[u]);
}
void merge(int u, int v) {
	u = find(u); v = find(v); f[u] = v;
}
int main() {
	int n; scanf("%d", &n);
	static char s[N];
	for(int i = 1; i <= 26; i ++) f[i] = i;
	for(int i = 0; i < n; i ++) {
		scanf("%s", s + 1);
		int m = strlen(s + 1);
		int st = 0, rt = s[1] - 'a' + 1;
		for(int j = 1; j <= m; j ++) st |= 1 << (s[j] - 'a'), use[s[j] - 'a' + 1] = 1;
		for(int j = 0; j < 26; j ++) if(st >> j & 1) {
			merge(rt, j + 1);
		}
	}
	int cnt = 0;
	for(int i = 1; i <= 26; i ++) if(use[i] && find(i) == i) cnt ++;
	printf("%d\n", cnt);
	return 0;
}