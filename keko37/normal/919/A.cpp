#include<iostream>
#include<cstdio>

using namespace std;

double n, m, sol=10000000, a, b;

int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a >> b;
		sol=min(sol, a*m/b);
	}
	printf("%.8f", sol);
	return 0;
}