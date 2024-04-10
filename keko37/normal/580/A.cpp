#include<iostream>

using namespace std;

int n, dp, sol;
int l[100005];

int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> l[i];
		if (l[i-1]<=l[i]) dp++; else dp=1;
		sol=max(sol, dp);
	}
	cout << sol;
	return 0;
}