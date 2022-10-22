#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rnd(n) fixed << setprecision(n)

const int mod = 998244353, mod2 = 1e+7;

int main(){
    IOS;
	int n; cin >> n;
	ll a[n], b;
	for (int i = 0; i < n/2; i++){
	    cin >> b;
	    if (i == 0){
	        a[0] = 0, a[n-1] = b;
	    }else{
	        a[i] = a[i-1];
	        a[n-i-1] = a[n-i];
	        ll p = b - (a[n-i]+a[i-1]);
	        if (p > 0) a[i] += p;
	        else a[n-i-1] += p;
	    }
	}
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;
}