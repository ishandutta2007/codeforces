#include<iostream>
using namespace std;
int zarb(int n){
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=i*(n-i+1);
	return sum;}
int main(){
	int n;
	cin>>n;
	cout<<zarb(n)-(n*(n-1)/2);
}