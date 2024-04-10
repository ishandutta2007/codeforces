#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, m, a[N];

int pick(int c, int l, int r){
	if(r < c) return N;
	return max(l, c);
}

int f(int x){
	int c = a[0];
	if(a[0] + x >= m) c = 0;
	for(int i = 1; i < n; i++){
		if(a[i] + x >= m){
			int c1 = pick(c, a[i], m - 1);
			int c2 = pick(c, 0, (a[i] + x) % m);
			if(c1 == N && c2 == N) return 0;
			c = min(c1, c2);
		}
		else{
			c = pick(c, a[i], a[i] + x);
			if(c == N) return 0;
		}
	}
	return 1;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	int l = 0, r = m - 1;
	while(l <= r){
		int mi = (l + r) / 2;
		if(f(mi)) r = mi - 1;
		else l = mi + 1;
	}
	printf("%d\n", l);
}