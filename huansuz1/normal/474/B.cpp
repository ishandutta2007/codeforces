#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <map>

using namespace std;

int a,b,c[1100000],i,n,m;
int main() {
	cin>>n;
	for (i=1; i<=n; i++) {
		cin>>a;

		for (int j=b+1; j<=a+b; j++) {
			c[j]=i;
		}
		b+=a;
	}
	cin>>m;
	for(i=1; i<=m; i++) {
		cin>>a;
		cout<<c[a]<<endl;
	}
	return 0;
}