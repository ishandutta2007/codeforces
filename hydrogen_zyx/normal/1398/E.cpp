#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    multiset<ll> s1, s2, s3, s4;
    ll sum = 0;
    ll sum2 = 0;
    ll k = 0;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (a == 0) {
            if (b > 0) {
                s1.insert(b);
            } else {
                s1.erase(-b);
            }

        } else {
            if (b > 0) {
                s2.insert(b);
                k++;
            } else {
                s2.erase(-b);
                k--;
            }
        }
        sum += b;
        if (b > 0) {
            if (s3.empty() || b > *s3.rbegin()) {
                sum2 += b;
                s4.insert(b);
            } else {
                s3.insert(b);
            }
        } else {
            if (s3.empty() || -b > *s3.rbegin()) {
                sum2 += b;
                s4.erase(-b);
            } else {
                s3.erase(-b);
            }
        }
        while (s4.size() < k) {
            ll v = *s3.rbegin();
            sum2 += v;
            s3.erase(v);
            s4.insert(v);
        }
        while (s4.size() > k) {
            ll v = *s4.begin();
            sum2 -= v;
            s4.erase(v);
            s3.insert(v);
        }
        ll k1 = s1.empty() ? 0 : *s1.rbegin();
        ll k2 = s2.empty() ? 0 : *s2.begin();
        cout << (k1 < k2 ? sum + sum2 - k2 + k1 : sum + sum2) << endl;
    }
}