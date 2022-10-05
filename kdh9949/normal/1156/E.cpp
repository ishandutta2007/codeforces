#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200005, SZ = 262144;

int n, a[N], p[N];

struct Seg{
	int d[2 * SZ];
	void i(){
		iota(d + SZ, d + 2 * SZ, 0);
		for(int i = SZ - 1; i; i--){
			if(a[d[2 * i]] > a[d[2 * i + 1]]) d[i] = d[2 * i];
			else d[i] = d[2 * i + 1];
		}
	}
	int g(int s, int e){
		int r = s;
		for(s += SZ, e += SZ; s <= e; s >>= 1, e >>= 1){
			if( s & 1){
				if(a[r] < a[d[s]]) r = d[s];
				s++;
			}
			if(~e & 1){
				if(a[r] < a[d[e]]) r = d[e];
				e--;
			}
		}
		return r;
	}
} S;

ll f(int s, int e){
	if(s >= e) return 0;
	int x = S.g(s, e);
	ll r = 0;
	if(x - s < e - x){
		for(int i = s; i < x; i++){
			int t = p[a[x] - a[i]];
			r += (x < t && t <= e);
		}
	}
	else{
		for(int i = e; i > x; i--){
			int t = p[a[x] - a[i]];
			r += (s <= t && t < x);
		}
	}
	r += f(s, x - 1);
	r += f(x + 1, e);
	return r;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) p[a[i]] = i;
	S.i();
	printf("%lld\n", f(1, n));
}