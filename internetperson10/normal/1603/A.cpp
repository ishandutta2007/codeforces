#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> lcd;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lcd.push_back(1);
    for(ll i = 2; i < 32000; i++) {
        lcd.push_back(lcd.back()*i/(__gcd(lcd.back(), i)));
        if(lcd.back() > 1000000000) break;
    }
    int t;
    cin >> t;
    while(t--) {
        bool ok = true;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            ll x;
            cin >> x;
            if(!(x%lcd[min(i, (int)lcd.size()-1)])) ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}