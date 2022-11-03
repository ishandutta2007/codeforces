#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    n--;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    
    int ans = 1e9 + 7;
    for (int i = 0; i + l <= n; i++) {
        ans = min(ans, pref[i + l] - pref[i]);
    }
    cout << ans << '\n';
    return 0;
    
}