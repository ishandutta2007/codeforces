// Hydro submission #6229ec3d5c5b5375ac2da45e@1646914622048
#include <bits/stdc++.h>

#define N 1000010
#define M 1000
#define INF 1000010
#define ll long long
using namespace std;
inline ll rd();
ll n, k, b[N], c[N], f[N], dp[N];
ll mx = 1;

inline ll rd(){
	char c;
	bool flag = 0;
	while((c = getchar()) < '0' || c > '9')
	    if(c == '-') flag = 1;
	ll res = c - '0';
	while((c = getchar()) >= '0' && c <= '9')
	    res = (res << 3) + (res << 1) + c - '0';
	return flag ? -res : res;
}

void init(){
	for(int i = 1 ; i <= M ; i++)
		f[i] = INF;
	f[1] = 0;
	for(int i = 1 ; i <= M ; i++)
		for(int j = 1 ; j <= i ; j++)
			f[i + i / j] = min(f[i + i / j], f[i] + 1),
			mx = max(mx, f[i + i / j]);
}
void Solve(){
	n = rd(), k = rd();
	for(int i = 1 ; i <= n ; i++)
		b[i] = rd();
	ll sum = 0;
	for(int i = 1 ; i <= n ; i++)
		c[i] = rd(), sum += c[i];
	if(k >= mx * n){
		printf("%lld\n", sum);
		return;
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 1 ; i <= n ; i++)
		for(int j = k ; j >= f[b[i]] ; j--)
			dp[j] = max(dp[j - f[b[i]]] + c[i], dp[j]);
	printf("%lld\n", dp[k]);
}
int main(){
	init();
	int T = rd();
	while(T--)
		Solve();
	return 0;
}