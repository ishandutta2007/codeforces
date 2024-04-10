#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

int a[N+5];
int b[N+5];

bool check(int n, int k){
    vector <int> v1, v2;
    for(int i=1; i<=n; i++) v1.push_back(a[i]);
    for(int i=1; i<=k; i++) v1.push_back(100);
    for(int i=1; i<=n; i++) v2.push_back(b[i]);
    for(int i=1; i<=k; i++) v2.push_back(0);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    ll sum = 0;
    int g = n+k;
    g = g - g/4;
    for(int i=0; i<g; i++) sum += v1[i];
    for(int i=0; i<g; i++) sum -= v2[i];
    return sum >= 0;
}

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    int l = 0, r = 2*n, res = 2*n+1;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(n, mid)){
            r = mid-1;
            res = mid;
        }
        else l = mid+1;
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}