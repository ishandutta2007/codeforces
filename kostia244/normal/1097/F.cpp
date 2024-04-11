#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int maxn = 1<<17, maxa = 7070;
using bt = bitset<maxa>;
int n, q, sqf[maxa];
bt a[maxn];
bt v[maxa], m[maxa];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 1; i < maxa; i++) {
		int ti = i;
		sqf[i] = 1;
		for(int j = 2; j < maxa; j++) {
			int t = 0;
			while(ti%j == 0) ti /= j, t++;
			sqf[i] &= t < 2;
		}
	}
	for(int d = 1; d < maxa; d++) {
		for(int i = 1; i*d < maxa; i++) {
			v[i*d][d] = 1;
			m[d][d*i] = sqf[i];
		}
	}
	cin >> n >> q;
	for(int t, x, y, z; q--;) {
		cin >> t >> x >> y;
		if(t == 1) a[x] = v[y];
		if(t == 2) {
			cin >> z;
			a[x] = a[y]^a[z];
		}
		if(t == 3) {
			cin >> z;
			a[x] = a[y]&a[z];
		}
		if(t == 4) {
			cout << (a[x]&m[y]).count()%2;
		}
	}
}