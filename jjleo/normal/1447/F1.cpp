#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int a[maxn];
int cnt[maxn], mx;
int f[maxn * 2];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		mx = max(mx, ++cnt[a[i]]);
	}
	int x = 0;
	for(int i = 1;i <= 100;i++){
		if(cnt[i] == mx){
			if(x) return printf("%d", n), 0;
			x = i;
		} 
	}
	int ans = 0;
	for(int i = 1;i <= 100;i++){
		if(i == x) continue;
		for(int j = 0;j <= 2 * n;j++) f[j] = 1e9;
		f[0 + n] = 0;
		int sum = 0;
		for(int j = 1;j <= n;j++){
			if(a[j] == x) sum++;
			else if(a[j] == i) sum--;
			ans = max(ans, j - f[sum + n]);
			f[sum + n] = min(f[sum + n], j);
		}
	}
	printf("%d", ans);
}