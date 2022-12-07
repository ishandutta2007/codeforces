#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;

struct point {
int x, y, z, i;
};
bool operator< (const point& a, const point& b) {
if (a.x != b.x) return a.x < b.x;
if (a.y != b.y) return a.y < b.y;
if (a.z != b.z) return a.z < b.z;
 return a.i < b.i;
}

vector<point> solve_plane(const vector<point>& v) {
    int pos = 0;
    vector<point> w;
    while (pos < SIZE(v)) {
        int dis_y = v[pos].y, old_pos = pos;
        while (pos < SIZE(v) && v[pos].y == dis_y) pos++;
        vector<point> line;
        FOR(i, old_pos, pos - 1) line.PB(v[i]);
        while(SIZE(line) >= 2) {
            cout << line.back().i << " ";
            line.pop_back();
            cout << line.back().i << "\n";
            line.pop_back();
        }
        for (auto p : line) w.PB(p);
    }

    while(SIZE(w) >= 2) {
        cout << w.back().i << " ";
        w.pop_back();
        cout << w.back().i << "\n";
        w.pop_back();
    }
    return w;
}

void jebaj() {
    int n;
    cin >> n;
    vector<point> v;
    REP(i, n) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back(point{x, y, z, i + 1});
    }
    sort(ALL(v));
    int pos = 0;
    vector<point> w;
    while (pos < SIZE(v)) {
        int dis_x = v[pos].x, old_pos = pos;
        while (pos < SIZE(v) && v[pos].x == dis_x) pos++;
        vector<point> plane;
        FOR(i, old_pos, pos - 1) plane.PB(v[i]);
        plane = solve_plane(plane);
        for (auto p : plane) w.PB(p);
    }
    while(SIZE(w) >= 2) {
        cout << w.back().i << " ";
        w.pop_back();
        cout << w.back().i << "\n";
        w.pop_back();
    }
    return;
}

#undef int

int main() {

    #define int long long
    int t = 1;
    //cin >> t;
    while (t--) {
        jebaj();
    }
    return 0;
}