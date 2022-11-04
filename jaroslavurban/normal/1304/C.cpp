#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct {
	long long t;
	long long l;
	long long h;
} customer;


int cmpCust(const void *c1, const void *c2){
	return (((customer*)c1)->t > ((customer*)c2)->t) - (((customer*)c1)->t < ((customer*)c2)->t);
}


int main(){
	int q;
	std::cin >> q;
	for (int i = 0; i < q; i++){
		long long n, m;
		std::cin >> n >> m;
		customer customers[100] = {};
		for (int j = 0; j < n; j++)
			scanf("%lld%lld%lld", &customers[j].t, &customers[j].l, &customers[j].h);
		qsort(customers, n, sizeof(customers[0]), cmpCust);
		long long mn, mx, T;
		mn = mx = m;
		T = 0;
		char can = 1;
		for (int j = 0; j < n; j++){
			customer c = customers[j];
			// printf("%lld %lld --> (%lld %lld)\n", mn, mx, c.t, mn - (c.t - T));
			mn = MAX(c.l, mn - (c.t - T));
			mx = MIN(c.h, mx + (c.t - T));
			// printf("%lld %lld\n", mn, mx);
			T = c.t;
			if (mn > c.h || mx < c.l){
				can = 0;
				break;
			}
		}
		if (can)
			printf("YES\n");
		else
			printf("NO\n");
	}
}