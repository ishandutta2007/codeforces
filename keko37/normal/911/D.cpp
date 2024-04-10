#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 1505;

int n, q, sol=1;
int l[MAXN];

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
	}
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (l[i]>l[j]) sol*=-1;
		}
	}
	cin >> q;
	for (int i=0; i<q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (((r-l+1)/2) & 1) sol*=-1;
		if (sol==1) printf("even\n"); else printf("odd\n");
	}
	return 0;
}