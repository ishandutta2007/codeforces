#include <bits/stdc++.h>
using namespace std;

void computePrimesLargest(int n, std::vector<int> &largest)
{
    largest.resize(n + 1);
    std::iota(largest.begin(), largest.end(), 0);

    for (int i = 2; i <= n; i++) {
        if (i == largest[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                largest[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x2;
    cin >> x2;
    vector<int> largest;
    computePrimesLargest(x2, largest);

    int l = x2 - largest[x2] + 1;
    int r = x2;

    int res = x2;
    for (int i = l; i <= r; i++) {
        if (i != largest[i])
            res = min(res, i - largest[i] + 1);
    }
    cout << res << endl;
}