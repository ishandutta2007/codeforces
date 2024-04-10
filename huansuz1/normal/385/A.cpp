#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,m,a[1234],ma;

int main(){
	cin>>n>>m;
	for (int i=0; i<n;  i++)
		cin>>a[i];
	for (int i=0; i<n-1; i++)
		if ((a[i]-a[i+1]-m)>ma && a[i]>a[i+1]) ma=(a[i]-a[i+1]-m);

	cout<<ma;
	
	return 0;
}