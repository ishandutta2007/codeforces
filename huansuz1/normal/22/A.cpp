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

int  a[12345],n,m=-1,mi;

int main(){
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>a[i];
	sort(a,a+n);
	for (int i=0; i<n; i++) 
		if (a[i]!=a[0]) {m=i; break;}
	if (m==-1) cout<<"NO"; else cout<<a[m];
	return 0;
}