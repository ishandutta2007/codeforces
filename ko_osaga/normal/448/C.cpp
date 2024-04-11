#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, a[5005];

int f(int s, int e, int h){
	if(s > e) return 0;
	int v = min_element(a+s, a+e+1) - a;
	return min(e-s+1, f(s, v-1, a[v]) + f(v+1, e, a[v]) + (a[v] - h));
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	cout << f(0, n-1, 0);
}