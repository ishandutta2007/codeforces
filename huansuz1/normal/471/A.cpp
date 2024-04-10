#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,a[123],z,b[123],m,s,k=1;
 
int main(){
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
	sort(a,a+6);
	if ((a[0]==a[3] && a[3]<a[4] && a[4]==a[5]) || (a[0]==a[1] && a[1]<a[2] && a[2]==a[5]) || (a[0]==a[5])) cout<<"Elephant"; else
	if ((a[0]<a[1] && a[1]<a[2] && a[2]==a[5]) || (a[4]<a[5] && a[3]<a[4] && a[0]==a[3]) || (a[0]<=a[1] && a[1]==a[4] && a[4]<=a[5])) cout<<"Bear"; else
	cout<<"Alien";
	
	return 0;
}