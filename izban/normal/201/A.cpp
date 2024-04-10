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

const int maxn=100100;

int n,x;
int a[100][100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> x;
	//for (x=1; x<=100; x++) {
	if (x==3) {
		cout << 5;
		return 0;
	}
	for (int i=1; i<=100; i++) {
		for (int j=0; j<100; j++) for (int k=0; k<100; k++) a[j][k]=0;
		for (int j=0; j<i; j++) {
			int l=(j&1), r=i-(j&1)-1;
			while (r-l>=2 || l==r) {
				a[j][l]=1;
				a[j][r]=1;
				l+=2; r-=2;
			}
		}
		int sum=0;
		for (int j=0; j<100; j++) for (int k=0; k<100; k++) sum+=a[j][k];
		int cx=x;
		if ((cx&1) && (i&1)) cx--;
		if ((cx%4==2) && (i&1) && (i>=3)) cx-=2;
		if (sum>=x && cx%4==0) {
			cout << i << endl;
			break;
		}
	}
	//}
	return 0;
}