#include <bits/stdc++.h>
using namespace std;
int n;
char a[2000000], b[2000000];
int main() {
    cin >> n;
    cin >> a >> b;
    vector<int> v1;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') c1++;
        if (b[i] == '1') c2++;
    }
    if (c1 != c2) {
        cout << -1;
        return 0;
    }
    if (c1 == 0 || c1 == n) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            v1.push_back(a[i] - '0');
        }
    }
    int mmax = 0, mmin = 2000000;
    int cnt = 0;
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] == 1)
            cnt++;
        else
            cnt--;
        mmax = max(mmax, cnt);
        mmin = min(mmin, cnt);
    }
    cout << mmax - mmin;
}