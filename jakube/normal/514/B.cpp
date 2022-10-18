#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;
    set<double> s;
    for (int i = 0; i < n; i++) {
        int x0, y0;
        cin >> x0 >> y0;
        if (x == x0)
            s.insert(1./0);
        else
            s.insert((double)(y0-y)/(x0-x));
    }
    cout << s.size() << '\n';
}