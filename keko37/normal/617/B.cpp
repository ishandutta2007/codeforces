#include<iostream>
#include<vector>

using namespace std;

long long n, sol=1;
int l[105];
vector <int> v;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
		if (l[i]==1) v.push_back(i);
	}
	if (v.size()==0) {
		cout << 0;
		return 0;
	}
	for (int i=0; i<v.size()-1; i++) {
		sol*=(v[i+1]-v[i]);
	}
	cout << sol;
	return 0;
}