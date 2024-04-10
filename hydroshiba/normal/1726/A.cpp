#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int &i : a) cin >> i;

    int maxx = *max_element(a.begin(), a.end());
    int minn = *min_element(a.begin(), a.end());

    int ans = INT_MIN;

    for(int i = 0; i < n; ++i){
        int j = (i + n - 1) % n;
        if((a[i] == minn && a[j] == maxx)){
            cout << maxx - minn << '\n';
            return;
        }

        ans = max(ans, a[j] - a[i]);
    }

    cout << max(ans, max((maxx - a[0]), (a[n - 1] - minn))) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}