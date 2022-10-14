#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

const int MAXN = 2005;

int n, k;
int a[MAXN], x[MAXN], b[MAXN];
set <int> s, sol;

int probaj (int val) {
	s.clear();
	for (int i=0; i<n; i++) {
		s.insert(val+x[i]);
	}
	for (int i=0; i<k; i++) {
		if (s.find(b[i])==s.end()) {
			return 0;
		}
	}
	return 1;
}

int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (i==0) {
			x[i]=a[i];
		} else {
			x[i]=a[i]+x[i-1];
		}
	}
	for (int i=0; i<k; i++) {
		cin >> b[i];
	}
	sort(x, x+n);
	sort(b, b+k);
	for (int i=0; i<n; i++) {
		int val=b[0]-x[i];
		if (probaj(val)) sol.insert(val);
	}
	cout << sol.size();
	return 0;
}