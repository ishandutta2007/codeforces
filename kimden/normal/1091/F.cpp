#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    string s;
    cin >> s;
    ll t = 0;
    ll wfly2 = 0;
    ll gfly2 = 0;
    bool hasg = false, hasw = false;
    for (int i = 0; i < n; ++i) {
        switch(s[i]) {
            case 'G':
                hasg = true;
                t += a[i];
                gfly2 += a[i] * 2;
                break;
            case 'W':
                hasw = true;
                t += a[i];
                wfly2 += a[i] * 2;
                break;
            case 'L':
                t += a[i];
                break;
        }
        ll energy = a[i];
        if (energy > 0 && wfly2 > 0) {
            ll delta = min(wfly2, energy);
            t += delta;
            wfly2 -= delta;
            energy -= delta;
        }
        if (energy > 0 && gfly2 > 0) {
            ll delta = min(gfly2, energy);
            t += delta * 2;
            gfly2 -= delta;
            energy -= delta;
        }
        if (energy > 0 && hasw) {
            ll delta = energy;
            t += delta * 3;
            energy -= delta;
        }
        if (energy > 0 && hasg) {
            ll delta = energy;
            t += delta * 5;
            energy -= delta;
        }
    }
    cout << t << endl;
}