#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <conio.h>
using namespace std;
int p=0;
long long a[100001],n,f=0,z=0;
void print(){
	for(int i=0;i<n;i++){
		printf("%I64d",a[i]);
		printf(" ");
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%I64d",&a[i]);
		if(a[i]%2==0)
			f=1;
		else
			z=1;
	}
	if(f&z){
		sort(a,a+n);
	}
	print();
}