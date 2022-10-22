#include<iostream>
using namespace std;
int main()
{
	long long n,k,m,x,max1=0,max2=0,sum=0;
	cin>>n>>k>>m;
	for(long long i=0;i<n;i++){
		cin>>x;
		if(x<=max1 && x>max2)max2=x;
		if(x>max1){
			max2=max(max1,max2);
			max1=x;}}
	sum+=(k/(m+1))*(max1*m+max2);
	sum+=(k%(m+1))*max1;
	cout<<sum;
}