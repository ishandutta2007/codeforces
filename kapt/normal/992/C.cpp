#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e9 + 7;

int pow2(int a, int n) {
	if (n == 0){
		return 1;
	}
	if (n % 2 == 1){
		return (pow2 (a, n - 1) * a) % inf;
	}
	else{
		int b = pow2 (a, n / 2);
		return (b * b) % inf;
	}
}

main(){
    int x, k;
    cin >> x >> k;
    if (x == 0){
        cout << 0;
        return 0;
    }
    x %= inf;
    int k2 = pow2(2, k);
    int x2 = (x * 2) % inf;
    int ans = (k2 * ((x2 - 1 + inf) % inf) + 1) % inf;
    cout << ans;
    return 0;
}