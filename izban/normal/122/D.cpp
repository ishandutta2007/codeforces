#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))

int n,k;
string a;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);       
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> k >> a;
	int pos=0;
	for (int i=0; i<k; i++) {
		while (pos<n-1 && (pos<0 || a[pos]!='4' || a[pos+1]!='7')) pos++;
		if (pos==n-1) break;
		if (pos>0 && pos%2 && a[pos]=='4' && a[pos+1]=='7' && a[pos-1]=='4') {
			a[pos]=((k-i)%2)?'7':'4';
			break;
		}
		if (a[pos]=='4' && a[pos+1]=='7') {
			a[pos]=a[pos+1]=pos%2?'7':'4';
			pos--;
		}
	}
	cout << a;
	return 0;
}