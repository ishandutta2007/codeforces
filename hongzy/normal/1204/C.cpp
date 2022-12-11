#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 110;

char Map[N][N];
int n, m, G[N][N], c, s[1000010];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%s", Map[i] + 1);
		for(int j = 1; j <= n; j ++) {
			if(Map[i][j] == '1') {
				G[i][j] = 1;
			} else G[i][j] = i == j ? 0 : (int) 1e9;
		}
	}
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	scanf("%d", &m);
	scanf("%d", &s[1]); c = 1;
	for(int i = 2, x; i <= m; i ++) {
		scanf("%d", &x);
		while(c > 1 && G[s[c - 1]][x] == G[s[c - 1]][s[c]] + G[s[c]][x]) c --;
		s[++ c] = x;
	}
	printf("%d\n", c);
	for(int i = 1; i <= c; i ++) printf("%d ", s[i]);
	return 0;
}