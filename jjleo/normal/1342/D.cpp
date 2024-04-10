#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, k;
int a[maxn], c[maxn];
int ans;

vector<int> v[maxn];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= k;i++) scanf("%d", &c[i]);
	reverse(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++){
		ans = max(ans, (int)ceil(1.0 * i / c[a[i]]));
	}
	printf("%d\n", ans);
	for(int i = 1;i <= n;i++) v[i % ans].push_back(a[i]);
	for(int i = 0;i < ans;i++){
		printf("%d", v[i].size());
		for(int j = 0;j < v[i].size();j++){
			printf(" %d", v[i][j]);
		}
		puts("");
	}
	
}