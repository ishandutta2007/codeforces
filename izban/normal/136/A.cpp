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

int n,m,k,p,ans=0;
string s;

int a[1000],b[1000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		b[a[i]]=i+1;
	}
	for (int i=1; i<=n; i++) cout << b[i] << ' ';
	return 0;
}