#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    set<int> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for(int i = 0; i < n; i++) {
        if(s.count(a[i])) cout << a[i] << ' ';
    }
}