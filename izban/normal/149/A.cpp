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

	cin >> k;
	for (int i=0; i<12; i++) cin >> a[i];
	sort(a,a+12);
	int x=0; bool f=k==0;
	if (k!=0) 
	for (int i=11; i>=0; i--) {
		x+=a[i];
		if (x>=k) {
			f=true;
			x=11-i+1;
			break;
		}
	}
	if (f) {
		cout << x;
	} else cout << -1;
	return 0;
}