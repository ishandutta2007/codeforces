#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <map>

using namespace std;

int a[10000],n,m,s,z,p;
int main() {
	cin>>n>>m;
	for (int i=0; i<n; i++)
		cin>>a[i];
	
	for (int i=0; i<n; i++)
	{
	s+=a[i];
	if (s>m) {z++; s=0; i--; }
	}
	if (s!=0) z++;
	cout<<z;
	return 0;
}