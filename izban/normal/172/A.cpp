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

const int maxn=131072;

int n,ans;
string a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) 
		cin >> a[i];
	for (int i=0; i<a[0].length(); i++) {
		ans=i;
		bool f=false;
		for (int j=1; j<n; j++) {
			if (a[j-1][i]!=a[j][i]) {
				f=true;
				break;
			}
		}
		if (f) break;
	}
	cout << ans;
	return 0;
}