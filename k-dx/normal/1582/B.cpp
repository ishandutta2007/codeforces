#include <bits/stdc++.h>
using namespace std;

#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;

const int N = 80;

int n;

int factorial (int x) {

}

int main () {
	int ttt;
	scanf("%d", &ttt);
	while (ttt--) {
		scanf("%d", &n);

        int one = 0, zero = 0;
        for (int i = 0; i < n; i++) {
            ll x;
            scanf("%lld", &x);

            if (x == 0) zero++;
            if (x == 1) one++;
        }




		printf("%lld\n", one * (1LL << zero));
		
	}
	return 0;
}