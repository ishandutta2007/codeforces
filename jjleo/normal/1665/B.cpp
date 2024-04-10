#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, x;
map<int, int> mp;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		mp.clear();
		int mx = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &x), mx = max(mx, ++mp[x]);
		int ans = n - mx;
		while(mx < n){
			ans++;
			mx <<= 1;
		}
		printf("%d\n", ans);
	}
}