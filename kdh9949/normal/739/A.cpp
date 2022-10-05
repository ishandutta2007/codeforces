#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int s[100001], e[100001];
int ans = 1e9;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", s + i, e + i);
		ans = min(ans, e[i] - s[i] + 1);
	}
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++){
		printf("%d ", (i - 1) % ans);
	}
}