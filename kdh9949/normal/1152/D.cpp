#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2005;
const ll M = ll(1e9) + 7;

int n;
ll d[N][N][2];

ll f(int x, int y, int z){
	ll &r = d[x][y][z];
	if(~r) return r;
	r = 0;
	if(x == 2 * n) return r;
	if(!z){
		if(y > 0) r += f(x + 1, y - 1, 1);
		if(y < 2 * n - x) r += f(x + 1, y + 1, 1);
		return r %= M;
	}
	if(y == 0) return r = (f(x + 1, y + 1, 0) + 1) % M;
	if(y == 2 * n - x) return r = (f(x + 1, y - 1, 0) + 1) % M;
	return r = (f(x + 1, y + 1, 0) + 1 + f(x + 1, y - 1, 1)) % M;
}

int main(){
	scanf("%d", &n);
	memset(d, -1, sizeof(d));
	printf("%lld\n", f(0, 0, 1) % M);
}