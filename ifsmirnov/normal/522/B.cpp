#include <bits/stdc++.h>

using namespace std;

#define long long long

const int M = 200200;

long n, w[M], h[M], sum = 0, mx1, mx2;

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> h[i];
}

void kill() {
    mx1 = 0;
    mx2 = 1;
    if (h[mx2] > h[mx1])
        swap(mx1, mx2);

    for (int i = 2; i < n; ++i)
        if (h[mx1] <= h[i]) {
            mx2 = mx1;
            mx1 = i;
        } else if (h[mx2] <= h[i]) {
            mx2 = i;
        }

    for (int i = 0; i < n; ++i) {
        sum += w[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i != mx1)
            cout << (sum - w[i]) * h[mx1] << " ";
        else
            cout << (sum - w[i]) * h[mx2] << " ";
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    kill();
    return 0;
}