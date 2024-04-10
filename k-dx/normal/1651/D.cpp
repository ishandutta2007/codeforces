#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 200'005;
const int GPS[][2] = {
    { 0, 1 }, // gora
    { 1, 0 }, // prawo
    { 0, -1 }, // dol
    { -1, 0 } // lewo
};

struct Pt {
    int x, y;

    // bool operator < (Pt const &a) {
    //     return x != a.x ? x < a.x : y < a.y;
    // }
};

Pt make_Pt (int x, int y) {
    Pt res;
    res.x = x;
    res.y = y;
    return res;
}

inline bool operator<(const Pt &a, const Pt &b) {
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}
inline bool operator==(const Pt &a, const Pt &b) {
    return a.x == b.x and a.y == b.y;
}


int n;
Pt ans[N];
vector<Pt> pts;
set<Pt> is_on_queue;
map<Pt, int> id;

int main () {
    scanf("%d", &n);
    pts.resize(n+1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        pts[i] = { x, y };
        id[{ x, y }] = i;
    }

    // current, origin
    queue<pair<Pt,Pt>> Q;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            int x = pts[i].x + GPS[j][0];
            int y = pts[i].y + GPS[j][1];
            if (id[{ x, y }] == 0 and is_on_queue.count(make_Pt(x, y)) == 0) {
                Q.push({ { x, y }, { x, y } });
                is_on_queue.insert({ x, y });
            }
        }
    }

    while (Q.size()) {
        auto f = Q.front();
        Q.pop();

        for (int j = 0; j < 4; j++) {
            int x = f.first.x + GPS[j][0];
            int y = f.first.y + GPS[j][1];

            if (id[{ x, y }] != 0 and ans[id[{ x, y }]] == make_Pt(0, 0)) {
                ans[id[{ x, y }]] = { f.second.x, f.second.y };
                Q.push({ { x, y }, { f.second.x, f.second.y } });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", ans[i].x, ans[i].y);
    }

    return 0;
}