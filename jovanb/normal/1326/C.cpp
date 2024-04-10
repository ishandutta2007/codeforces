#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll a[200005];

const int MOD = 998244353;

ll sum;
ll res = 1;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
        cin >> a[i];
	}
	int pos = 0;
	for(int i=1; i<=n; i++){
        if(a[i] >= n-k+1){
            sum += a[i];
            if(pos) res = (res*(i-pos))%MOD;
            pos = i;
        }
	}
	cout << sum << " " << res << "\n";
    return 0;
}