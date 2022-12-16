#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int hi = n;
    int lo = 1;
    while (true) {
        if (lo == hi) {
            cout << "! " << lo << endl;
            return 0;
        } else if (lo == hi-1) {
            int blah;
            cout << "? " << lo << ' ' << hi << endl;
            cin >> blah;
            if (blah == lo) cout << "! " << hi << endl;
            else cout << "! " << lo << endl;
            return 0;
        }
        int mxind;
        cout << "? " << lo << ' ' << hi << endl;
        cin >> mxind;
        int mid = (hi+lo)/2;
        if (mxind > mid) {
            if (hi == mid+1) {
                hi = mid;
                continue;
            }
            cout << "? " << mid+1 << ' ' << hi << endl;
            int newmx;
            cin >> newmx;
            if (newmx == mxind) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        } else {
            if (lo == mid) {
                lo = mid+1;
                continue;
            }
            cout << "? " << lo <<  ' ' << mid << endl;
            int newmx;
            cin >> newmx;
            if (newmx == mxind) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
    }
}