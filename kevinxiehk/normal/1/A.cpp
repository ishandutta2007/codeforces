#include <iostream>

int main(){
	long long a,m,n;
	std::cin>>m>>n>>a;
	std::cout<<((m+a-1)/a)*((n+a-1)/a);
	return 0;
	
}