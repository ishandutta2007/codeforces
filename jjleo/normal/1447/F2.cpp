#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int a[maxn];
int cnt[maxn], mx;
int f[maxn * 2];
int Cnt[maxn], num[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		mx = max(mx, ++cnt[a[i]]);
	}
	int x = 0;
	for(int i = 1;i <= n;i++){
		if(cnt[i] == mx){
			if(x) return printf("%d", n), 0;
			x = i;
		} 
	}
	int ans = 0;
	for(int i = 1;i * i <= n;i++){//debugi1 i  
		int l = 1;
		num[0] = n, mx = 0;
		for(int j = 1;j <= n;j++) Cnt[j] = num[j] = 0;
		for(int j = 1;j <= n;j++){
			num[Cnt[a[j]]]--, num[++Cnt[a[j]]]++;
			mx = max(mx, Cnt[a[j]]);
			while(mx > i){
				num[Cnt[a[l]]]--, num[--Cnt[a[l]]]++;
				l++;
				if(!num[mx]) mx--;
			}
			if(num[mx] > 1) ans = max(ans, j - l + 1);
		}
	}
	for(int i = 1;i <= n;i++){
		if(i == x || 1ll * cnt[i] * cnt[i] <= n) continue;
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