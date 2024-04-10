#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=10;

int n;
int a[maxn];
int sx[3], sy[3], sd[3];

int f(int x) {
	if (x==0 || x==1) return 1;
	return x*f(x-1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i=0; i<n*n; i++)
		cin >> a[i];
	for (int oo=0; oo<f(n*n); oo++) {
		int s1=0;
		for (int i=0; i<3; i++) sx[i]=sy[i]=sd[i]=0;

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				sx[i]+=a[i+n*j];
				sy[i]+=a[j+n*i];
			}
		}
		if (n==1) {
			sd[0]=sd[1]=a[0];
		} else if (n==2) {
			sd[0]=a[0]+a[3];
			sd[1]=a[1]+a[2];
		} else {
			sd[0]=a[0]+a[4]+a[8];
			sd[1]=a[2]+a[4]+a[6];
		}
		bool f=true;
		for (int i=0; i<n; i++)
			f=f && sx[0]==sx[i] && sx[0]==sy[i];
		f=f && sx[0]==sd[1] && sx[0]==sd[0];
		//if (a[0]+a[3]+a[6]==a[1]+a[4]+a[7] && a[0]+a[3]+a[6]==a[2]+a[5]+a[8] && a[0]+a[3]+a[6]==a[0]+a[1]+a[2] && a[0]+a[3]+a[6]==a[3]+a[4]+a[5] 
		//&& a[0]+a[3]+a[6]==a[6]+a[7]+a[8] && a[0]+a[3]+a[6]==a[0]+a[4]+a[8] && a[0]+a[3]+a[6]==a[2]+a[4]+a[6]) {
		if (f) {
			cout << sx[0] << endl;
			for (int i=0; i<n*n; i++) {
				cout << a[i] << ' ';
				if ((i+1)%n==0) cout << endl;
			}
			return 0;
		}
		next_permutation(a,a+9);
	}

	return 0;
}