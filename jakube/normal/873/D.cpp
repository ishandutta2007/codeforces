#include <bits/stdc++.h>
using namespace std;

int n, k;

void f(vector<int> &v, int l, int r) {
    int m = (l + r) >> 1;
    if (k != 0 && l + 1 < r) {
        rotate(v.begin() + l, v.begin() + (l + r - m), v.begin() + r); 
        k -= 2;
        f(v, l, m);
        f(v, m, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    k--;
    f(v, 0, n);

    if (k != 0) {
        cout << -1 << endl;
    } else {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

}