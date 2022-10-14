#include<cstdio>
#include<iostream>

using namespace std;

int n, m, a, b, x;
int l[200005];
int p[200005];

int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
	}
	int sad=0;
	for (int i=0; i<n; i++) {
		if (l[i]!=l[sad]) {
			for (int j=sad; j<i; j++) {
				p[j]=i;
			}
			sad=i;
		}
	}
	for (int i=sad; i<n; i++) {
		p[i]=n;
	}
	for (int i=0; i<m; i++) {
		scanf("%d%d%d", &a, &b, &x);
		a--; b--;
		if (x!=l[a]) {
			printf("%d\n", a+1);
		} else {
			if (p[a]<=b) printf("%d\n", p[a]+1); else printf("%d\n", -1);
		}
	}
	return 0;
}