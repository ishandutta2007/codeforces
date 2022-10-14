#include<iostream>

using namespace std;

const int MAXN = 10000007;

int n, a, b;
bool l[MAXN];

int main () {
	cin >> n >> a >> b;
	if (a==1 || b==1) {
		cout << "YES" << endl;
		if (a==1) cout << n << " " << 0; else cout << 0 << " " << n;
		return 0;
	}
	for (int i=0; i<MAXN; i+=a) {
		l[i]=1;
	}
	for (int i=0; i<=n; i+=b) {
		if (l[n-i]) {
			cout << "YES" << endl;
			cout << (n-i)/a << " " << i/b;
			return 0;
		}
	}
	cout << "NO";
	return 0;
}