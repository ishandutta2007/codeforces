#include <bits/stdc++.h>
using namespace std;

int n,m,k;

void solve(){
    cin >> n >> m >> k;
    int a[n];
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n-1; i ++){
        int t = max(0, a[i+1]-k);
        m -= t - a[i];
        if (m < 0){
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}
int main() {
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}