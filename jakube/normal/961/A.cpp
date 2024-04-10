#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v[x-1]++;
    }
    cout << *min_element(v.begin(), v.end()) << endl;
}