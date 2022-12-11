#include <bits/stdc++.h>
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
 
const int N = 3000 + 10;
int n, k, a[N], ni, pos[N * N], len, bel[N * N];
char s[N];
int main() {
	scanf("%d%d%s", &n, &k, s + 1);
	for(int i = 1; i <= n; i ++) {
		a[i] = s[i] == 'R';
		for(int j = 1; j < i; j ++)
			ni += a[j] > a[i];
	}
	if(k > ni) return puts("-1"), 0;
	int tmp = 0;
	while(1) {
		bool tag = 0; tmp ++;
		for(int i = 1; i < n; i ++) {
			if(a[i] && !a[i + 1]) {
				tag = 1;
				pos[++ len] = i;
				bel[len] = tmp;
			}
		}
		if(!tag) break ;
		for(int i = len; i >= 1 && bel[i] == tmp; i --)
			swap(a[pos[i]], a[pos[i] + 1]);
	}
	tmp --;
	if(k < tmp) return puts("-1"), 0;
	int op = tmp, x = -1; //printf("tmp = %d\n", tmp);
	for(int i = 1; i <= len && op < k; i ++) {
		if(bel[i + 1] == bel[i]) {
			bel[i] = -- x; op ++;
		}
	}
	for(int i = 1, j; i <= len; ) {
		for(j = i; j < len && bel[j + 1] == bel[i]; j ++) ;
		printf("%d", j - i + 1);
		for(int k = i; k <= j; k ++) printf(" %d", pos[k]);
		puts(""); i = j + 1;
	}
	return 0;
}