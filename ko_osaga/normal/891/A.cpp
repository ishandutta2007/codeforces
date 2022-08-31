#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 500005;
const int mod = 1e9 + 7;
typedef pair<int, int> pi;

int gcd(int x, int y){
	return y ? gcd(y, x%y) : x;
}

int n, a[2005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	if(count(a, a+n, 1) > 0){
		cout << n - count(a, a+n, 1);
		return 0;
	}
	int ans = 1e9;
	for(int i=0; i<n; i++){
		int g = a[i];
		for(int j=i; j<n; j++){
			g = gcd(g, a[j]);
			if(g == 1) ans = min(ans, j - i);
		}
	}
	if(ans > 1e8) ans = -n;
	cout << ans + n - 1;
}