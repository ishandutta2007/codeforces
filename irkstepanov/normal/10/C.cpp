#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

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
    
    vector<ll> cnt(9);
    for (int i = 1; i <= n; ++i) {
        ++cnt[i % 9];
    }
    
    ll ans = 0;
    
    for (int a = 1; a <= n; ++a) {
        ans -= n / a;
    }
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int rem = (i * j) % 9;
            ans += cnt[i] * cnt[j] * cnt[rem];
        }
    }
    
    cout << ans << "\n";

}