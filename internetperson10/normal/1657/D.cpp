#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

// h / D > H / d
// h * d > H * D

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector<ll> damage(c+1);
    for(int i = 0; i < n; i++) {
        ll cost, d, h;
        cin >> cost >> d >> h;
        damage[cost] = max(damage[cost], d * h);
    }
    for(int i = 1; i <= c; i++) {
        int x = 2;
        for(int j = 2 * i; j <= c; j += i) {
            damage[j] = max(damage[j], damage[i] * (x++));
        }
        damage[i] = max(damage[i], damage[i-1]);
    }
    int q;
    cin >> q;
    while(q--) {
        ll d, h;
        cin >> d >> h;
        ll val = d * h;
        if(damage[c] <= val) {
            cout << "-1 ";
            continue;
        }
        int l = 0, r = c;
        while(l != r - 1) {
            int mid = (l + r + 1) / 2;
            if(damage[mid] > val) r = mid;
            else l = mid;
        }
        cout << r << ' ';
    }
}