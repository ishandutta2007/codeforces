#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

struct pt
{
    ll x, y, z;
    bool operator<(const pt& other) const
    {
        if (x != other.x) {
            return x < other.x;
        }
        if (y != other.y) {
            return y < other.y;
        }
        if (z != other.z) {
            return z < other.z;
        }
        return false;
    }
};

pt operator+(const pt& a, const pt& b)
{
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

pt operator-(const pt& a, const pt& b)
{
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

bool eq(vector<pt>& a, vector<pt> &b)
{
    sort(all(a));
    sort(all(b));
    for (int i = 0; i < 4; ++i) {
        if (a[i].x != b[i].x || a[i].y != b[i].y || a[i].z != b[i].z) {
            return false;
        }
    }
    return true;
}

pt perm(const pt& a, int p)
{
    if (p == 0) {
        return {a.x, a.y, a.z};
    }
    if (p == 1) {
        return {a.x, a.z, a.y};
    }
    if (p == 2) {
        return {a.y, a.x, a.z};
    }
    if (p == 3) {
        return {a.y, a.z, a.x};
    }
    if (p == 4) {
        return {a.z, a.x, a.y};
    }
    if (p == 5) {
        return {a.z, a.y, a.x};
    }
}

ll dist(const pt& a, const pt& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

bool orto(const pt& a, const pt& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z == 0;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");
    //freopen("mine.txt", "w", stdout);

    vector<pt> v(8);
    for (int i = 0; i < 8; ++i) {
        cin >> v[i].x >> v[i].y >> v[i].z;
    }

    vector<vector<pt> > per(8, vector<pt>(6));
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 6; ++j) {
            per[i][j] = perm(v[i], j);
        }
    }

    int i[8];

    for (i[0] = 0; i[0] < 6; ++i[0]) {
        for (i[1] = 0; i[1] < 6; ++i[1]) {
            for (i[2] = 0; i[2] < 6; ++i[2]) {
                for (i[3] = 0; i[3] < 6; ++i[3]) {
                    for (i[4] = 0; i[4] < 6; ++i[4]) {
                        for (i[5] = 0; i[5] < 6; ++i[5]) for (i[6] = 0; i[6] < 6; ++i[6]) for (i[7] = 0; i[7] < 6; ++i[7]) {
                            vector<pt> p(8);
                            for (int j = 0; j < 8; ++j) {
                                p[j] = per[j][i[j]];
                            }
                            for (int j1 = 1; j1 < 6; ++j1) {
                                ll a = dist(p[0], p[j1]);
                                if (!a) {
                                    continue;
                                }
                                pt v1 = p[j1] - p[0];
                                for (int j2 = j1 + 1; j2 < 7; ++j2) {
                                    pt v2 = p[j2] - p[0];
                                    if (dist(p[j2], p[0]) != a || !orto(v1, v2)) {
                                        continue;
                                    }
                                    for (int j3 = j2 + 1; j3 < 8; ++j3) {
                                        pt v3 = p[j3] - p[0];
                                        if (dist(p[j3], p[0]) != a || !orto(v1, v3) || !orto(v2, v3)) {
                                            continue;
                                        }
                                        vector<pt> real(4);
                                        int pos = 0;
                                        real[pos++] = {p[0] + v1 + v2};
                                        real[pos++] = {p[0] + v2 + v3};
                                        real[pos++] = {p[0] + v1 + v3};
                                        real[pos++] = {p[0] + v1 + v2 + v3};
                                        bool okailo = true;
                                        for (int pos = 0; pos < 4; ++pos) {
                                            bool found = false;
                                        for (int j = 1; j < 8; ++j) {
                                            if (j != j1 && j != j2 && j != j3) {
                                                if (p[j].x == real[pos].x && p[j].y == real[pos].y && p[j].z == real[pos].z) {
                                                    found = true;
                                                    break;
                                                }
                                            }
                                        }
                                        if (!found) {
                                            okailo = false;
                                            break;
                                        }
                                        }
                                        if (okailo) {
                                            cout << "YES\n";
                                            for (int j = 0; j < 8; ++j) {
                                                cout << p[j].x << " " << p[j].y << " " << p[j].z << "\n";
                                            }
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "NO\n";

}