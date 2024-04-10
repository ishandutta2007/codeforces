#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int  n,k=0,p=1,s,t=1;
string a[123];

int main(){
     
	cin>>n;
	a[1]="Sheldon";
	a[2]="Leonard";
	a[3]="Penny";
	a[4]="Rajesh";
	a[5]="Howard";

	for (int i=1; i<=n; i++)
		{
		 if (p>5) { p=1; k++; }
		t=1;
		for (int j=1; j<=k; j++)
		t*=2;
		s+=t;
		if (s>=n) {cout<<a[p]; exit(0);}
		p++;
		}
	return 0;
}