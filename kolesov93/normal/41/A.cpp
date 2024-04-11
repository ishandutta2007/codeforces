#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

#define forn(i,n) for (int (i); (i) < (int) (n); (i)++)

int main() {
	string a,b;
	cin >> a; cin >> b;	
	reverse(a.begin(),a.end());
	if (a == b) puts("YES");
	else puts("NO");
	
	
	return 0;
}