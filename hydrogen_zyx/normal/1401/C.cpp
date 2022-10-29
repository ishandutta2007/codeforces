#include <bits/stdc++.h>
using namespace std;
int a[200000];
vector<pair<int, int> > v1, v2;
vector<int> num;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        v1.clear();
        v2.clear();
        num.clear();
        cin >> n;
        int mmin = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mmin = min(mmin, a[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] % mmin)
                v1.push_back(pair<int, int>(a[i], i));
            else {
                v2.push_back(pair<int, int>(a[i], i));
                num.push_back(i);
            }
        }
        bool f = 0;
        for (int i = 1; i < v1.size(); i++)
            if (v1[i] < v1[i - 1]) f = 1;
        if (f) {
            cout << "NO" << endl;
            continue;
        }
        sort(v2.begin(), v2.end());
        sort(num.begin(), num.end());
        int p1 = 0, p2 = 0;
        int mmax = 0;
        while (p1 < v1.size() && p2 < v2.size()) {
            if (v1[p1].second < num[p2]) {
                if (v1[p1].first < mmax) f = 1;
                mmax = v1[p1].first;
                p1++;
            } else {
                if (v2[p2].first < mmax) f = 1;
                mmax = v2[p2].first;
                p2++;
            }
        }
        while (p1 < v1.size()) {
            if (v1[p1].first < mmax) f = 1;
            mmax = v1[p1].first;
            p1++;
        }
        while (p2 < v2.size()) {
            if (v2[p2].first < mmax) f = 1;
            mmax = v2[p2].first;
            p2++;
        }
        if (f) {
            cout << "NO" << endl;
            continue;
        } else {
            cout << "YES" << endl;
        }
    }
}