#include<iostream>
#include<set>

using namespace std;

int n, m;
string a, b;
set <string> s;

int main () {
	cin >> a >> b;
	n=a.size(); m=b.size();
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			s.insert(a.substr(0, i)+b.substr(0, j));
		}
	}
	cout << *s.begin();
	return 0;
}