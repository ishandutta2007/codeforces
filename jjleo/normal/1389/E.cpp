#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
unsigned long long m, d, w;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%llu%llu%llu", &m, &d, &w);
		unsigned long long x = min(m, d);
		if((d - 1) % w == 0){
			printf("%llu\n", x * (x - 1) / 2);
			continue;
		}else{
			w /= __gcd(d - 1, w);
			printf("%llu\n", w * ((x / w) * (x / w - 1) / 2) + (x % w) * (x / w));
		}
	}
}