#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>

using namespace std;

int n,x,a[12345],s,i,z1,z2,z3;

int main(){
	cin>>n;
	for (int i=0; i<7; i++)
		cin>>a[i];
	while(s<n){
		s+=a[i];
		i++;
		if (i==7) i=0;
	}
	if (i==0) i=7;
		cout<<i;

	return 0;
}