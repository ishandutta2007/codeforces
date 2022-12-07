#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

#define forn(i,n) for (int (i) = 0; (i) < (int) (n); (i)++)
string a;

int main() {
	cin >> a;
	string dot = "dot", at = "at";
	
	int fir = a.find(at,1);
	a = a.substr(0,fir) + '@' + a.substr(fir+2);
	
	while (a.find(dot,1) != -1) {
		fir = a.find(dot,1);
		if (fir + 3 == a.length()) break;
		a = a.substr(0,fir) + '.' + a.substr(fir+3);
	}		
	cout << a << endl;
	
	return 0;
}