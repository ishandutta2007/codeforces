#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>

using namespace std;


int n,a[123456],b[123456],c[123456],x;



int main(){

cin>>n;
for (int i=0; i<n; i++) 
	cin>>a[i];
	sort(a,a+n);  
for (int i=0; i<n-1; i++)
	cin>>b[i];
	sort(b,b+n-1);
for (int i=0; i<n-2; i++)
	cin>>c[i];
	sort(c,c+n-2);
for (int i=0; i<n; i++)
	if (a[i]!=b[i]) {cout<<a[i]<<endl; break; }
for (int i=0; i<n-1; i++)
	if (c[i]!=b[i]) {cout<<b[i]; break; }
		






}