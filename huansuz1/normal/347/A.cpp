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

int n,a[12345];

int main(){
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>a[i];
		sort(a,a+n);
		int p=a[0]; a[0]=a[n-1]; a[n-1]=p;
		for (int i=0; i<n; i++)
		cout<<a[i]<<" ";
      return 0;
}