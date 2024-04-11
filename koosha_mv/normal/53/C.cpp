#include<iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		if(i%2==0)
			printf("%d",n-(i/2));
		else
			printf("%d",i/2+1);
		printf(" ");
	}
}