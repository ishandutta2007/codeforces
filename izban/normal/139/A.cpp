#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

int n,m,k,p,ans;
string s;

int a[200000],b[200000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=1; i<8; i++) cin >> a[i];
	int k=1;
	while (n) {
		n-=a[k];
		if (n<=0) break;
		k++;
		if (k==8) k=1;
	}
	cout << k;
	return 0;
}