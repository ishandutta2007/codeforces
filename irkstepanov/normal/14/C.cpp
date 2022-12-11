#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

struct pt
{
    int x, y;
    bool operator==(const pt& other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator!=(const pt& other) const
    {
        return x != other.x || y != other.y;
    }
};

struct segment
{
    pt a, b;
};

bool bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    vector<segment> s(4);
    vector<int> p = {0, 1, 2, 3};

    for (int i = 0; i < 4; ++i) {
        cin >> s[i].a.x >> s[i].a.y >> s[i].b.x >> s[i].b.y;
        if (s[i].a == s[i].b) {
            cout << "NO\n";
            return 0;
        }
    }

    bool ok = false;

    do {
        vector<segment> ss(4);
        for (int i = 0; i < 4; ++i) {
            ss[i] = s[p[i]];
        }
        for (int mask = 0; mask < 16; ++mask) {
            vector<segment> v = ss;
            for (int i = 0; i < 4; ++i) {
                if (bit(mask, i)) {
                    swap(v[i].a, v[i].b);
                }
            }
            if (v[0].a.y != v[0].b.y) {
                continue;
            }
            if (v[1].a.x != v[1].b.x) {
                continue;
            }
            if (v[2].a.y != v[2].b.y) {
                continue;
            }
            if (v[3].a.x != v[3].b.x) {
                continue;
            }
            if (v[0].b != v[1].a) {
                continue;
            }
            if (v[1].b != v[2].a) {
                continue;
            }
            if (v[2].b != v[3].a) {
                continue;
            }
            if (v[3].b != v[0].a) {
                continue;
            }
            if (!(v[0].a.x < v[0].b.x)) {
                continue;
            }
            if (!(v[1].a.y > v[1].b.y)) {
                continue;
            }
            if (!(v[2].a.x > v[2].b.x)) {
                continue;
            }
            if (!(v[3].a.y < v[3].b.y)) {
                continue;
            }
            ok = true;
        }
    } while (next_permutation(all(p)));

    cout << (ok ? "YES\n" : "NO\n");

}