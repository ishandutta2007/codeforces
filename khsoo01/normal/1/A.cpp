#include<iostream>
int n,m,a;
int main(){
	std::cin>>n>>m>>a;
	std::cout<<(long long)((n+a-1)/a)*((m+a-1)/a);
}