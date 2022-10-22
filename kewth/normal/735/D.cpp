#if 0
2019.06.01


 1 
 n  1 
 n  4  
n  2 
n  n - 1  1 n - 1  3 
 n  n - 2  2  n - 2  2 
#endif
#include <cstdio>

bool is_prime(int n) {
	for(int x = 2; x * x <= n; x ++)
		if(not (n % x))
			return false;
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	if(is_prime(n)) puts("1");
	else if(not (n & 1)) puts("2");
	else if(is_prime(n - 2)) puts("2");
	else puts("3");
}