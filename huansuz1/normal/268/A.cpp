#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

int n,a[1234],b[1234],z;

int main() {
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>a[i]>>b[i];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (i!=j && a[i]==b[j]) z++;
	cout<<z;
     
     return 0;
}