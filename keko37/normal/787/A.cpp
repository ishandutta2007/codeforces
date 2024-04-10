#include<iostream>
#include<cmath>

using namespace std;

const int MAXN = 1000005;

int a, b, c, d;
int l[MAXN];

int main () {
	cin >> a >> b >> c >> d;
	for (int i=0; b+a*i<MAXN; i++) {
		l[b+a*i]++;
	}
	for (int i=0; d+c*i<MAXN; i++) {
		l[d+c*i]++;
	}
	for (int i=0; i<MAXN; i++) {
		if (l[i]>1) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}