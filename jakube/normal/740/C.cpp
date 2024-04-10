#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    
    int mi = n;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        mi = min(mi, b-a);
    }

    cout << mi + 1 << endl;
    for (int i = 0; i < n; ++i) {
        cout << (i % (mi + 1)) << " ";
    }

    return 0;
}