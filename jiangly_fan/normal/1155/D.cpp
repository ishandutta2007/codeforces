//author: Hexun
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 360000;
LL a[maxn], p[maxn], h[maxn], s[maxn], ans, x;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n >> x;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= n; i += 1) s[i] = s[i - 1] + a[i];
	LL sum = 0;
	for(int i = 1; i <= n; i += 1){
		sum += a[i];
		if(sum > 0) ans = max(ans, p[i] = sum);
		if(sum < 0) sum = 0;
	}
	sum = 0;
	for(int i = n; i >= 1; i -= 1){
		sum += a[i];
		if(sum > 0) h[i] = sum;
		if(sum < 0) sum = 0;
	}
	//(s[r] - s[l]) * x + h[r + 1] + p[l];
	sum = 0;
	for(int i = 1; i <= n; i += 1){
		ans = max(ans, s[i] * x + h[i + 1] + sum);
		sum = max(sum, - s[i] * x + p[i]);
	}
	cout << ans;
	return 0;
}