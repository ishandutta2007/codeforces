#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define pb push_back
#define mp make_pair

map<pair<int, int>, int> memo;
int query(int l, int r) {
    if (memo.find(mp(l, r)) != memo.end()) return memo[mp(l, r)];
    int ans;
    cout << "? " << l << ' ' << r << endl;
    cin >> ans;
    return memo[mp(l, r)] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int hi = n;
    int lo = 1;
    int mxind;
    mxind = query(1, n);

    lo = 1;
    hi = mxind;
    int lftind;
    if (mxind != 1) {
    lftind = query(1, mxind);
    if (lftind == mxind) {
        if (mxind == 2) {
            cout << "! 1" << endl;
            return 0;
        }
        while (true) {
            if (hi == lo) {
                cout << "! " << lo << endl;
                return 0;
            } else if (lo == hi-1) {
                if (hi == mxind) {
                    cout << "! " << lo << endl;
                    return 0;
                }
                int thing = query(hi, mxind);
                if (thing == mxind) cout << "! " << hi << endl;
                else cout << "! " << lo << endl;
                return 0;
            }
            int mid = (lo+hi)/2;
            int newmx;
            newmx = query(mid, mxind);
            if (newmx == mxind) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
    }
    }
    // guaranteed on the right
    lo = mxind;
    hi = n;
    if (mxind == n-1) {
        cout << "! " << n << endl;
        return 0;
    }

    while (true) {
        if (hi == lo) {
            cout << "! " << lo << endl;
            return 0;
        } else if (lo == hi-1) {
            if (lo == mxind) {
                cout << "! " << hi << endl;
                return 0;
            }
            int thing = query(mxind, lo);
            if (thing == mxind) cout << "! " << lo << endl;
            else cout << "! " << hi << endl;
            return 0;
        }
        int mid = (lo+hi)/2;
        int newmx;
        newmx = query(mxind, mid);
        if (newmx == mxind) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
}