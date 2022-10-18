#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    using pii = pair<long long, long long>;
    pii last = {0, 0};
    for (int x : a) {
        pii cur = last;
        while (x >= 2 && cur.second) {
            cur.second--;
            cur.first++;
            x -= 2;
        }
        cur.first += x / 3;
        cur.second += x % 3;
        last = cur;
    }
    cout << last.first << endl;
}