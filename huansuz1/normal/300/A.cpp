#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>


using namespace std;

int a[1234],b[1234],c[1234],arr[1234],x,y,z,m;
int n;

int main()	{
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>m;
		if (m<0 && x==0) a[x++]=m; else
			if (m<=0) c[z++]=m; else 
				b[y++]=m; 
	}

	if (y==0) {
		for (int j=0; j<z; j++)
			if (y<2 && c[j]<0){b[y++]=c[j]; c[j]=0;}
		sort(c,c+z);
		z-=2;
	}
	cout<<x<<" "<<a[0]<<endl;
	cout<<y<<" ";
	for (int i=0; i<y; i++)
		cout<<b[i]<<" ";
	cout<<endl<<z<<" ";
	for (int i=0; i<z; i++)
		cout<<c[i]<<" ";


	
	return 0;
}