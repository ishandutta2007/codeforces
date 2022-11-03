#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<ll> v;
ll n, s;

ll getans(ll ra) {
    v.clear();
    v.resize(n, 0);
    v[0] = 1;
    ll cur = n - 1;
    ll ans = 1;
    for (int i = 1; i < n; ++i) {
        v[i] = min(cur, v[i - 1] * ra);
        cur -= v[i];
        ans += (i + 1) * v[i];
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    if (s < 2 * n - 1 || s > (n * (n + 1)) / 2) {
        cout << "No" << endl;
        return 0;
    }
    ll L = 0, R = n - 1;
    while (R - L > 1) {
        ll mid = L + (R - L) / 2;
        if (getans(mid) <= s) {
            R = mid;
        }else{
            L = mid;
        }
    }
    ll razv = R;
    v[0] = 1;
    ll ans = getans(R);
    ll cur = n - 1;
    cout << "Yes" << endl;
    if (razv == 1) {
        for(int i = 1; i < n; ++i) {
            if (i > 1) cout << " ";
            cout << i;
        }
        cout << endl;
        return 0;
    }
    int ptr = n - 1;
    while (v[ptr] == 0) {
        --ptr;
    }
    ll delta = s - ans;
    int targetdep = ptr + 1;
    for (; ptr > 0 && delta > 0; ) {
        if (v[ptr] == 1) {
            --ptr;
            continue;
        }
        if (targetdep - ptr <= delta) {
            delta -= targetdep - ptr;
            --v[ptr];
            ++v[targetdep];
            ++targetdep;
        }else{
            --v[ptr]; // careful!
            ++v[ptr + delta];
            break;
        }
    }
    vector<int> offsets(n, -1);
    offsets[0] = 1;
    for (int i = 1; i < n; ++i) {
        offsets[i] = offsets[i - 1] + v[i - 1];
        for (int j = 0; j < v[i]; ++j) {
            cout << offsets[i - 1] + j / razv << " ";
        }
    }
    cout << endl;

}