#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll;

ll n, m, k, ans;
int a[maxn], b[maxn], p[maxn], f[maxn];

int main(){
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= m;i++) scanf("%d", &b[i]);
	if(n > m) swap(n, m), swap(a, b);
	for(int i = 1;i <= m;i++) p[b[i]] = i, f[i] = n;
	for(int i = 1;i <= n;i++){
		if(!p[a[i]]) continue;
		int pos = p[a[i]] - i + 1;
		if(pos < 1) pos += m;
		f[pos]--;
	}
	int x = 1;
	ll sum = 0;
	while(1){
		sum += f[x];
		x += n;
		if(x > m) x -= m;
		if(x == 1) break;
	}
	k--;
	ans += k / sum * (n * m / __gcd(n, m));
	k %= sum;
	k++;
	while(1){
		if(k <= f[x]){
			for(int i = 1;;i++){
				int pos = x + i - 1;
				if(pos > m) pos -= m;
				if(a[i] ^ b[pos]) k--;
				if(k == 0) return printf("%lld", ans + i), 0;
			}
		}
		k -= f[x];
		x += n;
		if(x > m) x -= m;
		ans += n;
	}
}