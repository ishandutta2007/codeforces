#include<iostream>

using namespace std;

const int MAXN = 105;

int n;
int l[MAXN];

int main () {
	for (int i=0; i<MAXN; i++) {
		for (int j=0; j<MAXN; j++) {
			int val=i*3+j*7;
			if (val<MAXN) l[val]++;
		}
	}
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		if (l[x]) cout << "YES" << endl; else cout << "NO" << endl;
	}
	return 0;
}