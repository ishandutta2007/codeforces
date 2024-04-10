#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    set<int> b;
    deque<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (b.find(x) != b.end()) {
            continue;
        }
        if (a.size() < k) {
            a.push_front(x);
            b.insert(x);
        }
        else {
            int y = a.back();
            a.pop_back();
            b.erase(y);
            b.insert(x);
            a.push_front(x);
        }
    }
    cout << a.size() << endl;
    for (auto c : a) {
        cout << c << " ";
    }
}