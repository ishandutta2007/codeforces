#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int amax = 1e4 + 10;

int cnt[amax];

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    while (n--) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    
    ll ans = 0;
    
    if (k == 0) {
        for (int i = 0; i < amax; ++i) {
            ans += ll(cnt[i]) * ll(cnt[i] - 1) / 2;
        }
        cout << ans << "\n";
        return 0;
    }
    
    for (int i = 0; i < amax; ++i) {
        for (int j = i + 1; j < amax; ++j) {
            if (__builtin_popcount(i ^ j) == k) {
                ans += ll(cnt[i]) * ll(cnt[j]);
            }
        }
    }
    
    cout << ans << "\n";
    
}