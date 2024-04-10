#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n-1);
    for (auto& x : v)
        cin >> x;
   
    vector<int> res;
    int cur = n;
    res.push_back(cur);
    while (cur != 1) {
        cur = v[cur - 2];
        res.push_back(cur);
    }
    reverse(res.begin(), res.end());
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}