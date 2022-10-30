#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n, k, l;
char s[maxn];
bool a[maxn];

struct Data{
	int x;
	int y;
	
	Data(int a = 0, int b = 0){
		x = a, y = b;
	}
}f[maxn];

inline Data operator + (Data a, Data b){
	return Data(a.x + b.x, a.y + b.y);
}

inline bool operator < (Data a, Data b){
	return a.x ^ b.x ? a.x < b.x : a.y < b.y;
}

inline Data check(int x){
	for(int i = 1;i <= n;i++){
		f[i] = f[i - 1] + Data(a[i], 0);
		if(i >= l) f[i] = max(f[i], f[i - l] + Data(l - x, 1));
		else f[i] = max(f[i], Data(i - x, 1));
	}
	return f[n];
}

int ans = maxn;

inline void solve(){
	int l = 0, r = n, mid;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(check(mid).y < k) r = mid - 1;
		else l = mid;
	}
	ans = min(ans, n - (check(l).x + k * l));
}

int main(){
	scanf("%d%d%d%s", &n, &k, &l, s + 1);
	for(int i = 1;i <= n;i++) a[i] = s[i] >= 'a' && s[i] <= 'z';
	solve();
	for(int i = 1;i <= n;i++) a[i] ^= 1;
	solve();
	printf("%d", ans);
}