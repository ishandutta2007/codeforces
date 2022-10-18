#include <bits/stdc++.h>
using namespace std;

struct R
{
    int x1, y1, x2, y2;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<R> rectangles(n);
    multiset<int> x1, x2, y1, y2;
    for (auto& r : rectangles) {
        cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
        x1.insert(r.x1);
        x2.insert(r.x2);
        y1.insert(r.y1);
        y2.insert(r.y2);
    }

    for (auto r : rectangles) {
        x1.erase(x1.find(r.x1));
        x2.erase(x2.find(r.x2));
        y1.erase(y1.find(r.y1));
        y2.erase(y2.find(r.y2));

        if (*x1.rbegin() <= *x2.begin() && *y1.rbegin() <= *y2.begin()) {
            cout << *x1.rbegin() << " " << *y1.rbegin() << '\n';
            return 0;
        }

        x1.insert(r.x1);
        x2.insert(r.x2);
        y1.insert(r.y1);
        y2.insert(r.y2);
    }
}