#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200000];
int b[200000];
vector<int> v;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = 1;
    }
    int p1 = 0, p2 = 0;
    bool f = 0;
    for (int i = 1; i <= n; i++) {
        while (b[p1] == 2) p1++;
        if (p1 != a[i]) {
            v.push_back(p1);
            b[p1] = 2;
            while (b[p1] == 2) p1++;
            if (p1 != a[i]) {
                f = 1;
                break;
            }
        } else {
            while (b[p2] != 0) p2++;
            b[p2] = 2;
            v.push_back(p2++);
        }
    }
    if (f)
        cout << -1;
    else {
        for (auto x : v) cout << x << ' ';
    }
}