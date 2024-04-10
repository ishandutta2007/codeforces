#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
vector <int> v;

int pitaj (int len, int ind) {
    cout << "? " << len << " " << 1 << endl;
    for (int j = 1; j <= len; j++) cout << j << " "; cout << endl;
    cout << ind << endl;
    int res;
    cin >> res;
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int pos = -1;
        for (int i = 2; i <= n; i++) {
            if (pitaj(i - 1, i) != 0) {
                pos = i;
                break;
            }
        }
        int lo = 1, hi = pos - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (pitaj(mid, pos) == 0) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        v.clear();
        for (int i = 1; i < pos; i++) {
            if (i != lo) v.push_back(i);
        }
        for (int i = pos + 1; i <= n; i++) {
            cout << "? " << 1 << " " << 1 << endl;
            cout << i << endl;
            cout << pos << endl;
            int res;
            cin >> res;
            if (res == 0) v.push_back(i);
        }
        cout << "! " << v.size() << " ";
        for (auto x : v) cout << x << " "; cout << endl;
    }
    return 0;
}