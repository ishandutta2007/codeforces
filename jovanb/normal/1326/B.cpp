#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll a[200005];
ll b[200005];
ll x[200005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
        cin >> b[i];
	}
	a[1] = b[1];
	ll mx = a[1];
	for(int i=2; i<=n; i++){
        a[i] = b[i] + mx;
        mx = max(mx, a[i]);
	}
	for(int i=1; i<=n; i++){
        cout << a[i] << " ";
	}
    return 0;
}