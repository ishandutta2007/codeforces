#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int cnt = 0;
    for (int d : {100, 20, 10, 5, 1}) {
        cnt += n / d;
        n %= d;
    }
    cout << cnt << '\n';
}