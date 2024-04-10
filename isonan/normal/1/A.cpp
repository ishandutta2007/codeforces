#include <iostream>

long long n,m,a;
int main(){
	std::cin >> n >> m >> a;
	std::cout << ((n+a-1)/a)*((m+a-1)/a);
	return 0;
}