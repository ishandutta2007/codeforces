#include <bits/stdc++.h>
using namespace std;

const int N = 1E4 + 5;

int n, a[N];

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int ret; cin >> ret; return ret;
}

int main() {
    cin >> n;
    int cur = 1;
    for (int i = 2; i <= n; i++) {
        int le = ask(cur, i), ri = ask(i, cur);
        if (le < ri) {
            a[i] = ri;
        } else {
            a[cur] = le;
            cur = i;
        }
    }
    a[cur] = n;
    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
}