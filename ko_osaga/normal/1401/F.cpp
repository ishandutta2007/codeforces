#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, q;
int kek[20];
lint a[696969];

void upd(int x, int v, int s = 0, int e = (1 << n) - 1, int d = n - 1, int p = 1){
	if(s == e){
		a[p] = v;
		return;
	}
	int m = (s+e)/2;
	if(x <= m){
		upd(x, v, s, m, d-1, 2*p+kek[d]);
	}
	else{
		upd(x, v, m+1, e, d-1, 2*p+1-kek[d]);
	}
	a[p] = a[2*p] + a[2*p+1];
}

lint query(int s, int e, int ps = 0, int pe = (1<<n) - 1, int d = n - 1, int p = 1){
	if(e < ps || pe < s) return 0;
	if(s <= ps && pe <= e) return a[p];
	int pm = (ps+pe)/2;
	return query(s, e, ps, pm, d-1, 2*p+kek[d]) + query(s, e, pm+1, pe, d-1, 2*p+1-kek[d]);
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i=0; i<(1<<n); i++){
		int x; scanf("%d",&x);
		upd(i, x);
	}
	while(q--){
		int t; scanf("%d",&t);
		if(t == 1){
			int x, v; scanf("%d %d",&x,&v);
			x--;
			upd(x, v);
		}
		if(t == 4){
			int s, e; scanf("%d %d",&s,&e);
			printf("%lld\n", query(s-1, e-1));
		}
		if(t == 2){
			int x; scanf("%d",&x);
			for(int i=0; i<x; i++) kek[i] ^= 1;
		}
		if(t == 3){
			int x; scanf("%d",&x);
			kek[x] ^= 1;
		}
	}
}