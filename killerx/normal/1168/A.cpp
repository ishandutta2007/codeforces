#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    auto chk = [&] (int mx) {
        int lst = 0;
        for (int i = 0; i < n; ++ i) {
            if (a[i] + mx >= lst || (a[i] + mx) % m >= lst) {
                int nw = m - 1;
                if (a[i] + mx >= lst) nw = min(nw, max(lst, a[i]));
                if ((a[i] + mx) % m >= lst && a[i] + mx >= m) nw = min(nw, lst);
                lst = nw;
            } else return 0;
        }
        return 1;
    };
    int lb = 0, rb = m - 1;
    while (lb < rb) {
        int md = (lb + rb) >> 1;
        if (chk(md)) rb = md;
        else lb = md + 1;
    }
    cout << lb << endl;
    return 0;
}