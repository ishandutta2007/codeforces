#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mi = *min_element(v.begin(), v.end());
    int last = -999'999'999;
    int res = 999'999'999;
    for (int i = 0; i < n; i++) {
        if (v[i] == mi){
            res = min(i - last, res);
            last = i;
        }
    }
    cout << res << endl;
}