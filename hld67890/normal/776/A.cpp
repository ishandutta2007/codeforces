#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

int n;
string s1 , s2 , s , x;
void work () {
	int i;
	cin >> s1 >> s2;
	scanf ( "%d" , &n );
	cout << s1 << " " << s2 << endl;
	for ( i = 1 ; i <= n ; i++ ) {
		cin >> s >> x;
		if ( s == s1 ) s1 = x;
		else s2 = x;
		cout << s1 << " " << s2 << endl;
	}
}
int main () {
	work ();
	return 0;
}