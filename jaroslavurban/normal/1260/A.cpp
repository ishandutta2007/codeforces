#include <stdlib.h>
#include <iostream>
#include <math.h>


#define ll long long

int main(){
	int r;
	std::cin >> r;
	for (int i = 0; i < r; i++){
		int a, b;
		std::cin >> a >> b;
		printf("%lld\n", (b - (ll)(b/a) * a) * (ll)ceil(b/(double)a) * (ll)ceil(b/(double)a) + (a - b + (ll)(b/a) * a) * (ll)(b/a) * (ll)(b/a));
	}
}