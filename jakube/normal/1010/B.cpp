#include <bits/stdc++.h>
using namespace std;

int ask(int x) {
    cout << x << endl;
    cin >> x;
    if (x == 0)
        exit(0);
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<bool> lie(n);
    for (int i = 0; i < n; i++) {
        lie[i] = ask(1) < 0;
    }
    int L = 0, R = m + 1;
    int idx = 0;
    while (L < R) {
        int M = (L + R) / 2;
        int x = ask(M);
        if (lie[idx%n])
            x = -x;
        if (x > 0)
            L = M;
        else
            R = M;
        idx++;
    }
}