#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main()
{

    int n;
    cin >> n;
    
    ll ans = 0;
    ll sum = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a));
    
    ans = sum;
    for (int i = 0; i < n - 1; ++i) {
        ans += sum;
        sum -= a[i];
    }
    
    cout << ans << "\n";

}