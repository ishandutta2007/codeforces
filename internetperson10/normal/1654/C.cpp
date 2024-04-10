#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        multiset<ll> s1, s2;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            int k;
            cin >> k;
            s1.insert(k);
            sum += k;
        }
        s2.insert(sum);
        bool ok = true;
        while(s2.size()) {
            auto it = s2.end();
            it--;
            ll x = *it;
            auto it2 = s1.find(x);
            if(it2 != s1.end()) {
                s2.erase(it);
                s1.erase(it2);
                continue;
            }
            s2.erase(it);
            s2.insert(x/2);
            s2.insert((x+1)/2);
            if(x < *(s1.begin()) || s2.size() > s1.size()) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
        multiset<ll>().swap(s1);
        multiset<ll>().swap(s2);
    }
}