#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
int a[maxn];
map<int, int> mp;
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n), ans = 2 * n;
		for(int i = 1;i <= n * 2;i++){
			scanf("%d", &a[i]);
			if(a[i] == 2) a[i] = -1;
		}
		mp.clear();
		mp[0] = 0;
		int x = 0;
		for(int i = 1;i <= n;i++){
			x += a[i];
			mp[x] = i;
		}
		x = 0;
		ans = min(ans, n - mp[0] + n);
		for(int i = n * 2;i > n;i--){
			x += a[i];
			if(mp.find(-x) != mp.end()) ans = min(ans, n - mp[-x] + (i - n - 1));
			//printf("%d %d--\n", i, mp[-x]);
		}
		printf("%d\n", ans);
	}
}