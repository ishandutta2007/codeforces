#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
pair<int, int> a[maxn];
int b[maxn], c[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &m, &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i].first), a[i].second = -i;
		sort(a + 1, a + 1 + n);
		int ans = 0;
		for(int i = 1;i <= n;i++) b[-a[i].second] = i, c[i] = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= b[i];j++) ans += c[j];
			c[b[i]] = 1;
		}
		printf("%d\n", ans); 
	}
}