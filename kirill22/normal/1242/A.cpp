#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<pair<int, int>> fact(int n)  {
    vector<pair<int, int>> ans;
    for (int i = 2; i * i <= n; i++) {
        int x = 0;
        while (n % i == 0) {
            n /= i;
            x++;
        }
        if (x > 0) {
            ans.push_back({i, x});
        }
    }
    if (n > 1) {
        ans.push_back({n, 1});
    }
    return ans;
}

signed main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    vector<pair<int, int>> a = fact(n);
    if (n % 2 == 0 && a.size() > 1) {
        cout << 1;
    }
    else if (n % 2 == 0) {
        cout << 2;
    }
    else if (a.size() > 1) {
        cout << 1;
    }
    else {
        cout << a[0].first;
    }
}