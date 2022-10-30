#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
pair<int, int> a[maxn];
bool vis[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= m;i++){
		printf("? ");
		for(int j = 1;j <= m;j++) printf("%d", i == j);
		puts(""), fflush(stdout);
		scanf("%d", &a[i].first), a[i].second = i;
	}
	sort(a + 1, a + 1 + m);
	int last = 0, ans = 0;
	for(int i = 1;i <= m;i++){
		int x = a[i].second;
		vis[x] = true;
		printf("? ");
		for(int j = 1;j <= m;j++) printf("%d", vis[j]);
		puts(""), fflush(stdout);
		int val;
		scanf("%d", &val);
		if(last + a[i].first == val) last = val, ans += a[i].first;
		else vis[x] = false;
	}
	printf("! %d\n", ans), fflush(stdout);
}