#include<iostream>

using namespace std;

const int MAXN = 1000005;

int n, sol;
int bio[MAXN];
string a, b;

int main () {
	std::ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	for (int i=0; i<n; i++) {
		if (a[i] == b[i]) continue;
		sol++;
		if (i > 0 && bio[i-1] == 0 && a[i-1] != b[i-1] && a[i] != a[i-1]) {
			bio[i] = 1;
			sol--;
		}
	}
	cout << sol;
	return 0;
}