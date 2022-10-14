#include<iostream>
#include<vector>

using namespace std;

int n;
int l[1005];
vector <int> v;

int gcd (int a, int b) {
	if (b==0) return a;
	return gcd(b, a%b);
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
		if (i && gcd(l[i], l[i-1])!=1) v.push_back(1);
		v.push_back(l[i]);
	}
	cout << v.size()-n << endl;
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}