#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> a, b;
int main() {
	cin >> n;

	if (n%2==0) {
		cout << "NO";
		return 0;
	}

	for (int i=0; i<n; i++) {
		if (i%2==0) {
			a.push_back(2*i+1);
			b.push_back(2*i+2);
		}
		else {
			a.push_back(2*i+2);
			b.push_back(2*i+1);
		}
	}

	cout << "YES\n";
	for (int i=0; i<n; i++) cout << a[i] << ' ';
	for (int i=0; i<n; i++) cout << b[i] << ' ';
}