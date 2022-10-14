#include<iostream>
#include<cstdio>

using namespace std;

int n, k, sol, posa, posb;
int l[300005];
int p[300005];

int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
		p[i]=!l[i];
		if (i) p[i]+=p[i-1];
	}
	for (int i=0; i<n; i++) {
		if (!k && !l[i]) continue;
		int low=0, high=i, mid, val;
		while (low<high) {
			mid=(low+high)/2;
			if (mid==0) val=p[i]; else val=p[i]-p[mid-1];
			if (val>k) {
				low=mid+1;
			} else {
				high=mid;	
			}
		}
		if (i-low+1>sol) {
			sol=i-low+1;
			posa=low;
			posb=i;
		}
	}
	cout << sol << endl;
	if (sol) for (int i=posa; i<=posb; i++) l[i]=1;
	for (int i=0; i<n; i++) printf("%d ", l[i]);
	return 0;
}