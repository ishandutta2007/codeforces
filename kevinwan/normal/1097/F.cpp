#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
ll mod = 1e9 + 7;
bitset<7001> die[100001];
bitset<7001> fact[7001];
bitset<7001> mulp[7001];
int main() {
	int n,q,i,j,a,b,c;
	scanf("%d%d", &n,&q);
	for (i = 1; i <= 7000; i++)for (j = 1; j <= 7000; j++)if (i%j == 0)fact[i][j] = 1;
	mulp[1][1] = 1;
	for (i = 1; i <= 7000; i++)if (mulp[1][i])for (j = i*2; j <= 7000; j += i)mulp[1].flip(j);
	for (i = 2; i <= 7000; i++)for (j = 0; j*i <= 7000; j++)mulp[i][j*i] = mulp[1][j];
	while (q--) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d%d", &a, &b);
			die[a] = fact[b];
		}
		else if (a == 2) {
			scanf("%d%d%d", &a, &b,&c);
			die[a] = die[b] ^ die[c];
		}
		else if (a == 3) {
			scanf("%d%d%d", &a, &b, &c);
			die[a] = die[b] & die[c];
		}
		else {
			scanf("%d%d", &a, &b);
			printf("%d", (die[a] & mulp[b]).count() & 1);
		}
	}

}