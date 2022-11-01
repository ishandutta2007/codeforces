#include <bits/stdc++.h>
#define maxn 2000086

using namespace std;

typedef long long ll;

int t, n, m;
char s[maxn];
ll a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &m, s + 1);
		for(int i = 0;i <= n * m;i++) a[i] = b[i] = 0;
		int sum = 0;
		for(int i = 1;i <= n * m;i++){
			sum += s[i] - '0';
			if(i - m > 0) sum -= s[i - m] - '0';
			if(sum == 0) a[i]++;
		}
		for(int i = m + 1;i <= n * m;i++) a[i] += a[i - m];
		for(int j = 1;j <= m;j++){
			int sum = 0;
			for(int i = 1;i <= n;i++){
				sum += s[(i - 1) * m + j] - '0';
				if(sum == 0) b[(i - 1) * m + j]++, b[i * m + j]--;
			}
		}
		for(int i = 1;i <= n * m;i++) b[i] += b[i - 1];
		for(int i = 1;i <= n * m;i++){
			ll ans = n + m - a[i] - b[i];
			ans -= n - (i - 1) / m - 1;
			if(i < m) ans -= m - i;
			printf("%lld ", ans);
		}
		puts("");
	}
}