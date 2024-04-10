#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    if (all_of(v.begin(), v.end(), [](int x){return x == 0;})) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    if (accumulate(v.begin(), v.end(), 0LL) != 0) {
        cout << 1 << endl;
        cout << "1 " << v.size() << endl;
        return 0;
    }

    int mid = 0;
    long long psum = 0;
    for (int i = 0; i < n; i++) {
        psum += v[i];
        if (psum != 0) {
            mid = i;
        }
    }

    cout << 2 << endl;
    cout << 1 << " " << mid + 1 << endl;
    cout << mid + 2 << " " << n << endl;


    return 0;
}