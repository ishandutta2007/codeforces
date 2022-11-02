#include<iostream>
int a[10]={2,7,2,3,3,4,2,5,1,2},m=1,x;
int main()
{
	std::cin>>x;
	m*=a[x%10]*a[x/10];
	std::cout<<m;
}