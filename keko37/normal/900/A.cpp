#include<iostream>
#include<cstdio>

using namespace std;

int n, x, y, a, b;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d%d", &x, &y);
		if (x<0) a++; else b++;
	}
	if (a<=1 || b<=1) cout << "Yes"; else cout << "No";
	return 0;
}