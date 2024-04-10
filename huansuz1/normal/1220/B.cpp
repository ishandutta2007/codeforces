#include <bits/stdc++.h>

#define ll long long
using namespace std;
 
const int N = int(1e3) + 228;

int n;
int m[N][N];

ll a[N] ;

ll sq(ll x){
	ll y = sqrt(x);
	while(y * y < x) y++;
	while(y * y > x) y--;
	return y;
}
 
int main() {
	scanf("%d\n", &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &m[i][j]);
		}
	}
	a[0] = sq(1ll * m[0][1] * m[0][2] / m[1][2]);

	for(int i = 0 ;i < n; i++){
		if(i == 0) printf("%lld ", a[0]);
		else printf("%lld ", m[0][i] / a[0]);
	}


	return 0;
}