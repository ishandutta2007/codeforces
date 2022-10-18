#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<bool> v(101, false);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v[val] = true;
    }
    int cnt = 0;
    for (int i = 0; i < x; i++)
        cnt += !v[i];
    cnt += v[x];
    cout << cnt << endl;
}