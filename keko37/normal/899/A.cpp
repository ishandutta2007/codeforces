#include<iostream>
#include<cstdio>

using namespace std;

int n, a, b, x;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		if (x==1) a++; else b++;
	}
	cout << min(a, b)+max(a-b, 0)/3;
	return 0;
}