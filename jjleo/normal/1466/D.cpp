#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n;
int deg[maxn];
int x, y;
int a[maxn];
long long ans;
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) deg[i] = 0;
		ans = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), ans += a[i];
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			deg[x]++, deg[y]++;
		} 
		v.clear();
		for(int i = 1;i <= n;i++){
			for(int j = 1;j < deg[i];j++) v.push_back(a[i]);
		}
		sort(v.begin(), v.end(), greater<int>());
		printf("%lld ", ans);
		for(int i = 1;i <= n - 2;i++){
			if(i <= v.size()) ans += v[i - 1];
			printf("%lld ", ans);
		}
		puts("");
	}
}