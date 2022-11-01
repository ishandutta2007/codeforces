#include <bits/stdc++.h>
#define maxn 10086

using namespace std;

typedef long long ll;

int n;
ll a[maxn], ans;

void solve1(){
	ll l[maxn], r[maxn];
	for(int i = 1;i <= n;i++){
		l[i] = 0;
		ll mn = 1e18;
		for(int j = i;j;j--) mn = min(mn, a[j]), l[i] = max(l[i], mn * (i - j + 1));
		r[i] = 0;
		mn = 1e18;
		for(int j = i;j <= n;j++) mn = min(mn, a[j]), r[i] = max(r[i], mn * (j - i + 1));
	}
	for(int i = 2;i <= n;i++) l[i] = max(l[i], l[i - 1]);
	for(int i = n - 1;i;i--) r[i] = max(r[i], r[i + 1]);
	for(int i = 1;i < n;i++) ans = max(ans, l[i] + r[i + 1]);
}

void solve2(){
	for(int x = 1;x <= n;x++){
		int l = x, r = x;
		while(l > 1 && a[l - 1] >= a[x]) l--;
		while(r < n && a[r + 1] >= a[x]) r++;
		ll b[maxn], mn, mx;
		b[l] = 1e18;
		for(int i = l - 1;i;i--) b[i] = min(b[i + 1], a[i]);
		int pos = 1;
		mn = a[x], mx = 0;
		for(int i = r + 1;i <= n;i++){
			mn = min(mn, a[i]);
			while(pos < l && b[pos] + mn <= a[x]) mx = max(mx, (r - pos + 1) * b[pos]), pos++; 
			ans = max(ans, mx + (i - l + 1) * mn);
			ans = max(ans, (r - pos + 1) * (a[x] - mn) + (i - l + 1) * mn);
		}
		mn = a[x], pos = l;
		for(int i = r;i <= n;i++){
			mn = min(mn, a[i]);
			while(pos > 1 && b[pos - 1] >= mn) pos--;
			ans = max(ans, (i - pos + 1) * mn + (r - l + 1) * (a[x] - mn));
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	if(n == 1) return printf("%lld", a[1]), 0;
	solve1(), solve2(), reverse(a + 1, a + 1 + n), solve2();
	printf("%lld", ans);
}