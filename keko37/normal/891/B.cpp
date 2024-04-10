#include<iostream>
#include<algorithm>

using namespace std;

int n;
pair <int, int> l[30];
int p[30];

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i].first;
		l[i].second=i;
	}
	sort(l, l+n);
	for (int i=0; i<n; i++) {
		p[l[i].second]=l[(i+1)%n].first;
	}
	for (int i=0; i<n; i++) {
		cout << p[i] << " ";
	}
	return 0;
}