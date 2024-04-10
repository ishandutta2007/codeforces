#include<iostream>
#include<algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 1005;

llint n, k, sol;
llint l[MAXN];

int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	sort(l, l+n);
	for (int i=0; i<n; i++) {
		if (k*2>=l[i]) {
			k=max(k, l[i]);
		} else {
			while (k*2<l[i]) {
				k*=2;
				sol++;
			}
			k=max(k, l[i]);
		}
	}
	cout << sol;
	return 0;
}