#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    
    set<pair<int, int>> s;
    s.insert({bx + cx - ax, by + cy - ay});
    s.insert({bx + ax - cx, by + ay - cy});
    s.insert({ax + cx - bx, ay + cy - by});
    s.insert({ax + bx - cx, ay + by - cy});
    s.insert({cx + ax - bx, cy + ay - by});
    s.insert({cx + bx - ax, cy + by - ay});

    cout << s.size() << endl;
    for (auto p : s)
        cout << p.first << " " << p.second << endl;

    return 0;
}