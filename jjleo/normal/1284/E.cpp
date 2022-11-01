#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

#define double long double

const double pi = acos((double)-1);

int n;
int x[maxn], y[maxn];
double a[maxn];

ll cal(int n){
	if(n < 0) return 0;
	ll ans = 1;
	for(int i = 1;i <= 3;i++) ans = ans * (n - i + 1) / i;
	return ans;
}

int main(){
	scanf("%d", &n);
	ll ans = 5;
	for(int i = 1;i <= 5;i++) ans = ans * (n - i + 1) / i;
	for(int i = 1;i <= n;i++) scanf("%d%d", &x[i], &y[i]);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(j < i) a[j] = atan2((double)(y[j] - y[i]), (double)(x[j] - x[i]));
			else if(j > i) a[j - 1] = atan2((double)(y[j] - y[i]), (double)(x[j] - x[i]));
		}
		int m = n - 1;
		sort(a + 1, a + m + 1);
		for(int j = m + 1;j <= m * 2;j++) a[j] = a[j - m] + pi * 2;
		int x = 1;
		for(int j = 1;j <= m;j++){
			while(x + 1 < j + m && a[x + 1] - a[j] < pi) x++;
			ans -= cal(x - j);
		}
	}
	printf("%lld", ans);
}