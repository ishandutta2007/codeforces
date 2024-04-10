#include <bits/stdc++.h>
using namespace std;

int okniz(long double x) {
    if (x < 0)
        return (x - 0.999999);
    else
        return x;
}

int okverx(long double x) {
    if (x < 0)
        return x;
    else
        return x + 0.9999999;
}

int main() {
    int i, j, k, n;
    long double x;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    long double sum = 0, sumcel = 0;
    for (i = 0; i < n; ++i) {
        cin >> x;
        sum += x;
        if (abs(sum - sumcel - okverx(x)) < abs(sum - sumcel - okniz(x))) {
            sumcel += okverx(x);
            cout << okverx(x) << "\n";
        } else {
            sumcel += okniz(x);
            cout << okniz(x) << "\n";
        }
    }
}