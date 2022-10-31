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

int n,m,a[12345],p;

int main(){
	cin>>n>>m;
	for (int i=1; i<=m; i++)
		cin>>a[i];
	sort(a+1, a+m+1);
	for (int i=1; i<=m-1; i++)
		if ((a[i+1]-a[i]==1 && a[i+2]-a[i]==2)) {cout<<"NO"; return 0;}
    if (a[m]!=n&&a[1]!=1) cout<<"YES";	 else cout<<"NO";

	return 0;
}