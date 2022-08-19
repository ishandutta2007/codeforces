#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m, mn, mx;
int a[111];

int main(){
	cin >> n >> m >> mn >> mx;
	for(int i=0; i<m; i++) cin >> a[i];
	sort(a, a+m);
	if(a[0] != mn && m < n) a[m++] = mn;
	sort(a, a+m);
	if(a[m-1] != mx && m < n) a[m++] = mx;
	sort(a, a+m);
	if(a[0] != mn || a[m-1] != mx) puts("Incorrect");
	else puts("Correct");
}