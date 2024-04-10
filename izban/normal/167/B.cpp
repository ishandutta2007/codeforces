#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const long double eps=1e-9;

int n,l1,k;
int p[500],a[500];

long double d[210][210][500];
long double ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> l1 >> k;
	for (int i=0; i<n; i++) 
		cin >> p[i];
	for (int i=0; i<n; i++)
		cin >> a[i];


	d[0][0][250-k]=1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int l=0; l<500; l++) {
				d[i+1][j][l]+=d[i][j][l]*((double)(100.0-p[i])/100.0);
				d[i+1][j+1][max(l-a[i],0)]+=d[i][j][l]*((double)p[i]/100.0);
			}
		}
	}
	for (int j=0; j<=n; j++) 
		for (int l=0; l<500; l++)
			if (j>=l1 && l<=250 && d[n][j][l]>eps) 
				ans+=d[n][j][l];
	printf("%.10lf",ans);
	return 0;
}