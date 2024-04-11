#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

bool has(const set<int>& q, int x) {
    return q.find(x) != q.end();
}

int main() {
    int n, l, x, y;
    scanf("%d%d%d%d", &n, &l, &x, &y);

    set<int> q;
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        q.insert(a);
    }

    typedef set<int>::iterator sit;
    bool wasX = false, wasY = false;
    for (sit it = q.begin(); it != q.end(); ++it) {
        int who = *it;
        if (q.find(who - x) != q.end()) wasX = true;
        if (q.find(who - y) != q.end()) wasY = true;
    }

    if (wasX && wasY) {
        puts("0");
        return 0;
    }

    if (wasX) {
        cout << "1\n" << y << endl;
        return 0;
    }
    if (wasY) {
        cout << "1\n" << x << endl;
        return 0;
    }

    for (set<int>::iterator it = q.begin(); it != q.end(); ++it) {
        int who = *it;

        if (who + x <= l && has(q, who + x + y)) {
            cout << 1 << endl;
            cout << who + x << endl;
            return 0;
        }
        if (who + x <= l && has(q, who + x - y)) {
            cout << 1 << endl;
            cout << who + x << endl;
            return 0;
        }
        if (who - x > 0 && has(q, who - x + y)) {
            cout << 1 << endl;
            cout << who - x << endl;
            return 0;
        }
    }

    cout << 2 << endl;
    cout << x << " " << y << endl;

    return 0;
}