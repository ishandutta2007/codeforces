#include<iostream>
#include<cmath>

using namespace std;

int n, sol=1000000;
int l[1000];

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
		l[i+n]=l[i];
	}
	for (int i=0; i<n; i++) {
		int sum=0;
		for (int j=0; j<n; j++) {
			sum+=l[i+j];
			sol=min(sol, (int)abs(360-sum-sum));
		}
	}
	cout << sol;
	return 0;
}