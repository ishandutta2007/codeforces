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
	int n,k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int c = 1, ans = 1;
	for (int i = 1; i < n; i++){
	    if (a[i] == a[i-1]) c = 1;
	    else c ++;
	    ans = max(ans, c);
	}
	cout << ans;
    return 0;
}