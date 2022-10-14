#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int n;

int pitaj (int a, int b) {
    if (a > b) swap(a, b);
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int pos = pitaj(1, n);
    if (pos == 1 || pitaj(1, pos) != pos) {
        int lo = pos + 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (pitaj(pos, mid) == pos) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << "! " << lo;
    } else {
        int lo = 1, hi = pos - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (pitaj(mid, pos) == pos) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << "! " << lo;
    }
    return 0;
}