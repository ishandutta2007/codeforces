#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector< pair<int, int> > p(n, make_pair(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = make_pair(a[i] + i, -i);
    }

    sort(p.begin(), p.end());
    vector<int> result(n, 0);
    for (int i = 0; i < n; i++) {
        int v = -p[i].second;
        result[i] = a[v] + v - i;
        if (result[i] < 0 || i >= 1 && result[i] < result[i - 1]) {
            cout << ":(" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;

}