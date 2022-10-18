#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < 1'001; i++) {
        s.insert(i * i);
    }

    int ma = std::numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
         int x;
         cin >> x;
         if (!s.count(x))
            ma = max(ma, x);
    }
    cout << ma << endl;
}