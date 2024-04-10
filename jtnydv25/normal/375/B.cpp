#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &(x))
const int N = 5005;
int n, m;
char s[N][N];
int nxt[N][N];

int arr[N];
int getMax(int l){
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		arr[++cnt] = nxt[i][l] - l;

	sort(arr + 1, arr + n + 1);

	int ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, arr[i] * (n - i + 1));
	return ans;
}

int main(){
	sd(n); sd(m);
	for(int i = 1; i <= n; i++){
		scanf("%s", s[i] + 1);
		nxt[i][m + 1] = m + 1;
		for(int j = m; j >= 1; j--) nxt[i][j] = (s[i][j] == '0') ? j : nxt[i][j + 1];
	}
	int ans = 0;
	for(int l = 1; l <= m; l++) ans = max(ans, getMax(l));
	printf("%d\n", ans);
}