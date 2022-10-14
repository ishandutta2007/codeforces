#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 100005;

int n, sol, ind, x, y, ofs;
int l[MAXN], p[MAXN];

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
	}
	for (int i=0; i<n; i++) {
		if (x<l[i]) {
			ofs++;
			p[l[i]]--;
		} else if (y<l[i]) {
			p[x]++;
		}
		y=max(y, l[i]);
		if (x<y) swap(x, y);
	}
	ind=n+1;
	for (int i=1; i<=n; i++) {
		if (p[i]+ofs==sol) {
			ind=min(ind, i);
		} else if (p[i]+ofs>sol) {
			sol=p[i]+ofs;
			ind=i;
		}
	}
	cout << ind;
	return 0;
}