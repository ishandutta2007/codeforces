#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

#define forn(i,n) for (int i = 0; i < (int) (n); i++)
string a,b,c;
int aa,bb;

int main() {
	int n;
	bool ca=0,cb = 0;
	cin >> n;
	while (n--) {
		cin >> c;
		if (!ca) { 
			a = c;
			ca = 1;
		}
		if (a != c) b = c;
		if (a == c) aa++;
		else bb++;
	}
	
	if (aa > bb) cout << a << endl;
	else cout << b << endl;
	
	return 0;
}