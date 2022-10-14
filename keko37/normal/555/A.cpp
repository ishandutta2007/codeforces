#include<iostream>
#include<vector>

using namespace std;

int n, k;
vector <int> v[100005];
int jedan;

int main () {
	cin >> n >> k;
	for (int i=0; i<k; i++) {
		int a, b;
		cin >> a;
		for (int j=0; j<a; j++) {
			cin >> b;
			v[i].push_back(b);
		}
		if (v[i] [0]==1) jedan=i;
	}
	int ct=0;
	for (int j=0; j<v[jedan].size(); j++) {
		if (v[jedan] [j]==j+1) ct++; else break;
	}
	cout << (n-ct)*2-k+1;
	return 0;
}