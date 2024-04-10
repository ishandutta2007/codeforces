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

struct Pt {
    int x, y;

    bool operator== (const Pt &other_pt) {
        return x == other_pt.x and y == other_pt.y;
    }
};

// iloczyn wektorowy, wektory a i b zaczynaja sie w punkcie root
// jezeli cross < 0 to a lezy po lewej od b
// jezeli cross = 0 to a jest rownolegle z b
// jezeli cross > 0 to a lezy po prawej od b
ll cross (Pt root, Pt a, Pt b) {
    return (ll)(a.x - root.x) * (ll)(b.y - root.y) 
           - (ll)(a.y - root.y) * (ll)(b.x - root.x);
}

// mowi, czy punkt c lezy na odcinku ab (konce si NIE licz)
bool isOnSegmentOpen (Pt a, Pt b, Pt c) {
    if (cross(a, b, c) != 0LL) return false;

    int minx = min(a.x, b.x);
    int maxx = max(a.x, b.x);
    int miny = min(a.y, b.y);
    int maxy = max(a.y, b.y);
    int x = c.x;
    int y = c.y;
    return (minx < x and x < maxx) and (miny < y and y < maxy);
}

// !!!!!!
// UWAGA: punkty w polygon musz by podane w kolejnoci
// zgodnej z ruchem wskazwek zegara
//
// zoono: O(log n), gdzie n jest liczb bokw wielokta
//
// zakadamy, e punkt lecy na boku lub wierzchoku wielokta
// do niego NIE naley
// zakadamy, e wierzchoki wielokta speniaj x, y <= 10^9
//
// idea: dzielimy wielokt na trjkty i binsearchujemy, w ktrym trjkcie
// moe lee punkt, na koniec sprawdzamy czy ley w tym trjkcie
bool pointInConvexPolygon (Pt pt, vector<Pt> &polygon) {
    if (cross(polygon[0], pt, polygon[1]) <= 0LL) return false;
    if (cross(polygon[0], pt, polygon.back()) >= 0LL) return false;

    int beg = 1, mid, end = polygon.size()-1;
    while (beg + 1 != end) {
        mid = (beg + end) / 2;
        
        // przypadek, gdy punkt lezy na prostej 
        if (mid != -1 
            and mid != polygon.size()-1 
            and isOnSegmentOpen(polygon[0], polygon[mid], pt)) {
            return true;
        }

        ll crs = cross(polygon[0], pt, polygon[mid]);
        if (crs < 0LL) {
            end = mid;
        }
        else {
            beg = mid;
        }
    }

    // sprawdz, czy punkt ley w wybinsearchowanym trjkcie
    return cross(polygon[beg], pt, polygon[end]) > 0LL;
}

int main () {
    // Pt pt;
    // scanf("%d %d", &pt.x, &pt.y);

    // int n;
    // scanf("%d", &n);
    // vector<Pt> polygon;
    // polygon.resize(n);
    // for (int i = 0; i < n; i++) {
    //     scanf("%d %d", &polygon[i].x, &polygon[i].y);
    // }

    // if (pointInConvexPolygon(pt, polygon)) printf("TAK\n");
    // else printf("NIE\n");

    // kod poniej do:
    // https://codeforces.com/problemset/problem/166/B
    int n;
    scanf("%d", &n);
    vector<Pt> outside_polygon;
    outside_polygon.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &outside_polygon[i].x, &outside_polygon[i].y);
    }

    bool res = true;
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        Pt pt;
        scanf("%d %d", &pt.x, &pt.y);
        if (!pointInConvexPolygon(pt, outside_polygon)) res = false;
    }

    if (res) printf("YES\n");
    else printf("NO\n");

    return 0;
}