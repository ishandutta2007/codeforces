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

int n,m;
char a[1234];

int main() {
	cin>>n>>m;
	for (int i=0; i<n; i++)
		cin>>a[i];
	for (int j=0; j<m; j++) {
		for (int i=1; i<n; i++)
			if (a[i]=='G' && a[i-1]=='B') { a[i]='b'; a[i-1]='G'; }
		for (int i=0; i<n; i++)
			if (a[i]=='b') a[i]='B';
	}
	for (int i=0; i<n; i++)
		cout<<a[i];	

	return 0;
}