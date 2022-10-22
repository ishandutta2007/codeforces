#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(101);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x]++;
        }
        int tmp = 0, tmp2 = 0;
        for (int i = 0; i <= 100; i++) {
            if (a[i] && tmp == i) tmp++, a[i]--;
            if (a[i] && tmp2 == i) tmp2++, a[i]--;
        }
        cout << tmp + tmp2 << '\n';
    }
}