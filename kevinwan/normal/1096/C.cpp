#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 998244353;
const int mn = 0;
int main() {
	int n, i, j;
	scanf("%d", &n);
	int a;
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		a *= 2;
		for (j = 3; j <= 360; j++) {
			if (360 % j)continue;
			int st = 360 / j;
			if (a%st == 0 && a + st < 360) {
				printf("%d\n", j);
				break;
			}
		}
	}
}