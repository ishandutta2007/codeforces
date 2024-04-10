#include<iostream>

using namespace std;

int x;

int main () {
	cin >> x;
	if (x%5==0) cout << x/5; else cout << x/5+1;
	return 0;
}