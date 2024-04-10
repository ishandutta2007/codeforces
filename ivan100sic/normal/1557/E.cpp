// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct pt {
    int x, y;

    int operator* (const pt& b) const {
        return x * b.x + y * b.y;
    }

    pt operator+ (const pt& b) const {
        return {x + b.x, y + b.y};
    }

    bool operator! () const {
        return x != 0 || y != 0;
    }
};

int fit(int x) {
    return max(1, min(x, 8));
}

pt mv(pt p) {
    cout << p.x << ' ' << p.y << '\n' << flush;
    string s;
    cin >> s;
    if (s == "Down") return {1, 0};
    if (s == "Up") return {-1, 0};
    if (s == "Right") return {0, 1};
    if (s == "Left") return {0, -1};
    if (s == "Down-Right") return {1, 1};
    if (s == "Down-Left") return {1, -1};
    if (s == "Up-Right") return {-1, 1};
    if (s == "Up-Left") return {-1, -1};
    return {0, 0};
}

/**
This is the first time in years I had to read an editorial
because first of all, I've had enough of this stupid problem,
I hate chess and I hate everything today.

Thank you for your attention.
**/

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        pt q = {1, 1};
        pt d = mv(q);
        if (!!d) {
            continue;
        }

        while (!d) {
            if (d.x == -1) {
                q.y = q.y == 1 ? 2 : 1;
                d = mv(q);
            } else if (d.x == 1) {
                q.x++;
                d = mv(q);
                if (!!d) break;
                q.y = q.y == 1 ? 2 : 1;
                d = mv(q);
            } else {
                q.y++;
                if (q.y == 9) {
                    q.y = 8;
                    q.x++;
                    d = mv(q);
                    if (!!d) break;
                    q.y = q.y == 1 ? 2 : 1;
                    d = mv(q);
                } else {
                    d = mv(q);
                }
            }
        }
    }
}