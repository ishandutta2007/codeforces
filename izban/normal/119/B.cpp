#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

#define sqr(x) ((x)*(x))
struct predmet {
	int a, p;
	bool operator<(const predmet & p) const {
		return a < p.a;
	}
} a[100];
int t;
//int a[100],p[100];
int b[100][100];
bool v[100];



void qsort(int l, int r)  {
	int i=l, j=r, x=a[l+rand()%(r-l)].a;
	do {
		while (a[i].a<x) i+=1;
		while (a[j].a>x) j-=1;
		if (i<=j) {
			swap(a[i],a[j]);
			i++; j--;
		}
	} while (i<=j);
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
}
bool mycmp(predmet a,predmet b){
	return a.p<b.p;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	int n,m,k,q,h=0;
	double mi=1000000,ma=0,sum=0;
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> a[i].a;
	cin >> q;
	for (int i=0; i<q; i++) {
		sum=0;
		for (int j=0; j<(n/k); j++) { 
			cin >> b[i][j];
			sum+=a[b[i][j]-1].a;
			v[b[i][j]-1]=true;
		}
		sort(b[i],b[i]+(n/k));
		sum/=(n/k);
		mi=min(mi,sum);
		ma=max(ma,sum); bool f=false;
		for (int j=0; j<i; j++) {
			for (int o=0; o<(n/k); o++) {
				if (b[j][o]!=b[i][o]) break;
				if (o==n/k-1) {
					h++; f=true;
				}
			}
			if (f) break;
		}
	}
	for (int i=0; i<n; i++) a[i].p=i;
	if (k-q+h>0) {
		sort(a,a+n);
		sum=0;
		int y=0;
		for (int i=0; y<(n/k);i++) {
			if (!v[a[i].p]){
				sum+=a[i].a;
				y++;
			}
		}
		sum/=(n/k);
		mi=min(mi,sum);
		sum=0; y=0;
		for (int i=n-1; y<(n/k); i--) {
			if (!v[a[i].p]){
				sum+=a[i].a;
				y++;
			}
		}
		sum/=(n/k);
		ma=max(ma,sum);
	}
	printf("%07f %07f",mi,ma);
	return 0;
}