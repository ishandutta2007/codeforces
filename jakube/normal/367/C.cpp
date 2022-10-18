#include <bits/stdc++.h>
using namespace std;

long long needed(long long n) {
    long long res = n * (n - 1) / 2;
    if (n % 2 == 0)
        res += n / 2 - 1;
    return res;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    vector<int> w(m);
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp >> w[i];
    }

    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    
    long long psum = 0;
    for (int i = 0; i < m; i++) {
        if (needed(i+1) + 1 <= n) {
            psum += w[i];
        } else {
            break;
        }
    }

    cout << psum << endl;

    return 0;
}