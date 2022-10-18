#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto& x : b)
        cin >> x;
    
    int l = 0;
    auto a_it = a.begin();
    auto b_it = b.begin();

    while (a_it != a.end() || b_it != b.end()) {
        if (a_it == a.end()) {
            cout << -1 << '\n';
            return 0;
        }

        int cur = *(a_it++);
        l++;
        do {
            if (a_it != a.end() && cur < 0)
                cur += *(a_it++);
            else if (b_it != b.end() && cur > 0)
                cur -= *(b_it++);
            else
                break;
        } while (cur);

        if (cur != 0) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << l << '\n';
}