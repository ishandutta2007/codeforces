#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

struct pt
{
    int x, y;
    pt() {}
    pt(int x, int y) : x(x), y(y) {}
    pt operator-(const pt& other) const
    {
        return {x - other.x, y - other.y};
    }
};

int cross(const pt& p, const pt& q)
{
    return p.x * q.y - p.y * q.x;
}

int dot(const pt& p, const pt& q)
{
    return p.x * q.x + p.y * q.y;
}

bool right(const pt& a, const pt& b, const pt& c)
{
    if (cross(b - a, c - a) == 0) {
        return false;
    }
    if (dot(b - a, c - a) == 0) {
        return true;
    }
    if (dot(a - b, c - b) == 0) {
        return true;
    }
    if (dot(a - c, b - c) == 0) {
        return true;
    }
    return false;
}

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pt p[3];
    for (int i = 0; i < 3; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    if (right(p[0], p[1], p[2])) {
        cout << "RIGHT\n";
        return 0;
    }

    pt q[3];

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            q[i].x += dx[j];
            q[i].y += dy[j];
            if (right(q[0], q[1], q[2])) {
                cout << "ALMOST\n";
                return 0;
            }
        }
    }

    cout << "NEITHER\n";

}