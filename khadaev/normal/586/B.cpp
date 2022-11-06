#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, up[50], down[50], cross[50], upsum[50], downsum[50], result[50];
    cin >> n;
    for (int i = 0; i < n - 1; ++i) cin >> up[i];
    for (int i = 0; i < n - 1; ++i) cin >> down[i];
    for (int i = 0; i < n; ++i) cin >> cross[i];
    int s = 0;
    for (int i = 0; i < n; ++i) {
        upsum[i] = s;
        s += up[i];
    }
    s = 0;
    for (int i = n - 1; i >= 0; --i) {
        downsum[i] = s;
        s += down[i - 1];
    }
    /*for (int i = 0; i < n; ++i) {
        cout << upsum[i] << " " << downsum[i] << " " << cross[i] << endl;
    }*/
    for (int i = 0; i < n; ++i)
        result[i] = upsum[i] + downsum[i] + cross[i];
    sort(result, result + n);
    cout << result[0] + result[1] << endl;
}