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

int a[12345],n,k,t,p,m;

int main() {
	cin>>n>>k>>t;
	p=(n*k*t)/100;
	for (int i=0; i<n; i++){
		if (k>=p) {a[i]=p; break;}
			else 
				if (p>k) {a[i]=k; p-=k;}
	}

	for (int i=0; i<n; i++)
		cout<<a[i]<<" ";

	return 0;
}