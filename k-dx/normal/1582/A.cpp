#include <bits/stdc++.h>
using namespace std;

#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;

const int N = 0;

int n;

int main () {
	int ttt;
	scanf("%d", &ttt);
	while (ttt--) {
        ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);

		printf("%d\n", (a + 2LL*b + 3LL*c) % 2 != 0);
		
	}
	return 0;
}