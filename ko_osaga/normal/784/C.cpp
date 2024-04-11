#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, a[111];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	cout << ((*max_element(a, a+n)) ^ a[n-1]);
}