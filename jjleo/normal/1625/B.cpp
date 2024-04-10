#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];
vector<int> v[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), v[a[i]].push_back(i);
		int ans = -1;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j < v[a[i]].size();j++){
				int x = v[a[i]][j - 1], y = v[a[i]][j];
				ans = max(ans, x - 1 + n - y + 1);
			}
			v[a[i]].clear();
		}
		printf("%d\n", ans);
	} 
}