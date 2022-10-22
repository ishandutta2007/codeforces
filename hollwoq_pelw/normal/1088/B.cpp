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
	sort(a, a + n);
	vector<int> ans;
	for (int i = 0; i < n; i++){
	    if (i == 0) ans.push_back(a[i]);
	    else if (a[i] != a[i-1]) ans.push_back(a[i]-a[i-1]);
	}
	ans.resize(k);
	for (int i = 0; i < k; i++) cout << ans[i] << endl;
    return 0;
}