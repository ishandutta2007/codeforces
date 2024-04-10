#include<iostream>

using namespace std;

int n, k;
string s, sol;

int main () {
	cin >> n >> k;
	for (char i='a'; i<'a'+k; i++) {
		s+=i;
	}
	for (int i=0; i<2*n/k; i++) {
		sol+=s;
	}
	for (int i=0; i<n; i++) {
		cout << sol[i];
	}
	return 0;
}