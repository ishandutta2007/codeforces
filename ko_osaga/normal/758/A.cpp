#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, a[111];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	int ret = 0;
	for(int i=0; i<n; i++) ret += a[n-1] - a[i];
	cout << ret;
}