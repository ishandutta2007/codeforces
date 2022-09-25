#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define sqr(x) ((x)*(x))
int t;

void writ(int x) {
	for (int i=0; i<(t-(x*4+1))/2; i++) cout << ' ';
	for (int i=0; i<x; i++) cout << i << ' ';
	cout << x; if (x>0) cout << ' ';
	for (int i=x-1; i>0; i--) cout << i << ' ';
	if (x>0) cout << 0;
//	for (int i=0; i<(t-(x*4+1))/2; i++) cout << ' ';
	cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	int n,m;
	cin >> n;
	t=n*4+1;
	for (int i=0; i<n+1; i++) 
		writ(i);
	for (int i=n-1; i>=0; i--) 
		writ(i);
	return 0;
}