#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 1000005;

int main(){
	lint n, m, k;
	cin >> n >> m >> k;
	if((2 * n * m) % k != 0){
		puts("NO");
		return 0;
	}
	int g1 = gcd(n, 2 * m * n / k);
	int g2 = 2 * m * n / (k * g1);
	if(g2 > m){
		g2 = gcd(m, 2 * m * n / k);
		g1 = 2 * m * n / (k * g2);
	}
	printf("YES\n0 0\n%d 0\n0 %d\n", g1, g2);
}