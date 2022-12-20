#include <bits/stdc++.h>
using namespace std;

vector <long long> v, v2, v3;

int main() {
    long long n, cl, ck, u, i, j;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin  >> j;
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    j = n - 1;
    while (j >= 0) {
        long long t = 1;
        while (t <= v[j]) t *= 2;
        t /= 2;
        vector <long long> v1;
        while (j >= 0 && v[j] >= t) {
            v1.push_back(v[j]);
            --j;
        }
        sort(v1.begin(), v1.end());
        int j1 = 0;
        v2.clear();
        for (i = 0; i < v3.size(); ++i) {
            if ((v3[i] & t) > 0 && j1 < v1.size()) {
                v2.push_back(v1[j1]);
                ++j1;
            }
            v2.push_back(v3[i]);
        }
        if (j1 == v1.size() - 1) {
            v2.push_back(v1[j1]);
            ++j1;
        }
        if (j1 != v1.size()) {
            cout << "No";
            return 0;
        }
        v3 = v2;
    }
    cout << "Yes\n";
    for (i = 0; i < v2.size(); ++i)
        cout << v3[i] << ' ';
}