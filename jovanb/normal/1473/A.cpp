#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back

int a[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        if(a[n] <= k || a[1]+a[2] <= k) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}