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

int n,m,a[1234],b[123],s,z,ss;

int main() {
	cin>>n;
		for (int i=0; i<n; i++) {
			cin>>m;
			if (m%2==0) s+=m; else { a[z++]=m;  ss+=m;}        
		}
		if (z==0) {cout<<0; exit(0); }
		sort(a,a+z);
		if (ss%2==1)cout<<s+ss; else cout<<s+ss-a[0];
	return 0;
}