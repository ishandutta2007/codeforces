
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

int n,a[123],b[123],z,s,k;

int main(){
	cin>>n>>k;
	for (int i=0; i<n; i++)
		cin>>a[i]>>b[i];

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
				if (a[i]>a[j]) {int p=a[i]; a[i]=a[j]; a[j]=p;
									p=b[i]; b[i]=b[j]; b[j]=p; } else
		        if (a[i]==a[j] && b[i]<b[j]) {int p=a[i]; a[i]=a[j]; a[j]=p;
									p=b[i]; b[i]=b[j]; b[j]=p; }
	k--;								                               
	for (int i=0; i<n; i++)
		if (a[i]==a[k] && b[k]==b[i]) z++;
	cout<<z;
	return 0;
}