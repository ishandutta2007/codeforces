#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<double>> v;
int a[100000];
int main() {
	ll n,s=1,a,b;
	scanf("%lld", &n);
	while (1) {
		if (n * 2 >= s * 10)s *= 10;
		else break;
	}
	a = n / s, b = n % s;
	if (s == 1)printf("%lld", n*(n-1)/2);
	else if (b < s/2) {
		printf("%lld", b*(a + 1)*a + (s/2 - b)*a*a);
	}
	else if(b<s-1){
		printf("%lld", (b - s / 2 + 1)*(a + 1)*(a + 1) + (s - 2 - b)*(a + 1)*a + a * a);
	}
	else printf("%lld", (s / 2 - 1)*(a + 1)*(a + 1) + a * (a + 1));
}