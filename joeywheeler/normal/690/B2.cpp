#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

#include <bits/stdc++.h>
 
#define INF 1000000010
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;
 
struct point {
    ll x, y;
    int id;
    point (){};
    point (ll _x, ll _y, int _id) : x(_x), y(_y), id(_id) {};
};
 
struct vect {
    ll x, y;
    vect (){};
    vect (ll _x, ll _y) : x(_x), y(_y) {};
    vect (point a, point b) : x(b.x-a.x), y(b.y-a.y) {};
};
 
//Returns the signed norm of a x b
ll crossProductNorm (vect a, vect b) {
    return a.x*b.y-b.x*a.y;
}
 
//Returns true if b is ccw of a
bool isCCW (vect a, vect b) {
    return crossProductNorm (a,b) < 0;
}

ll dst(point a, point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
 
point refPoint;
//Returns true if a is clockwise of b with reference to refPoint
bool compCW (point a, point b) {
    vect aVect (refPoint, a);
    vect bVect (refPoint, b);
    return isCCW (aVect,bVect) || (
            crossProductNorm(aVect,bVect) == 0 && dst(refPoint,a) <
            dst(refPoint,b)
            );
}
 
// Also sorts it wrt lowest point:
vector <point> constructConvexHull (vector <point> &pts) {
    if (pts.empty()) {
        vector <point> v;
        return v;
    }
    int minY = pts[0].y, minX = pts[0].x;
    int minYP = 0;
    FO (i,1,pts.size()) if (pts[i].y < minY || (pts[i].y == minY && pts[i].x < minX)) minY = pts[i].y, minX = pts[i].x, minYP = i;
    refPoint = pts[minYP];
    pts.erase (pts.begin()+minYP);
    sort (pts.begin(),pts.end(),compCW);
    pts.insert (pts.begin(), refPoint);
    //printf ("Outputting sorted pts:\n");
    //FO (i,0,pts.size()) printf ("%d: %lld %lld\n", pts[i].id, pts[i].x, pts[i].y);
 
    vector <point> myCH;
    myCH.push_back (pts[0]);
    FO (i,1,pts.size()) {
        while (myCH.size() >= 2) {
            vect v1(myCH[myCH.size()-1],pts[i]);
            vect v2(myCH[myCH.size()-2],myCH[myCH.size()-1]);
            if (!isCCW (v2, v1)) myCH.pop_back();
            else break;
        }
        myCH.push_back (pts[i]);
    }
    while (myCH.size() > 2) {
        vect v1(myCH[myCH.size()-1],pts[0]);
        vect v2(myCH[myCH.size()-2],myCH[myCH.size()-1]);
        if (!isCCW (v2, v1)) myCH.pop_back();
        else break;
    }

    return myCH;
}

char g[505][505];
 
int main() {
    while (1) {
        int n; scanf("%d", &n);
        if (n == 0) return 0;
        FO(y,0,n) scanf(" %s", g[n-y-1]);
        vector<point> vp;
        FO(y,1,n) FO(x,1,n) {
            bool allg = true;
            FO(dy,-1,1) FO(dx,-1,1) {
                allg = allg && g[y+dy][x+dx] > '0';
            }
            if (allg) {
                vp.emplace_back(x,y,0);
            }
        }
        vector<point> ch = constructConvexHull(vp);
        int m = sz(ch);
        int mp = 0;
        FO(i,1,m) if (ch[i].x < ch[mp].x || (ch[i].x == ch[mp].x &&
                ch[i].y < ch[mp].y)) mp = i;
        printf("%d\n", m);
        FO(i,0,m) printf("%lld %lld\n", ch[(mp+i)%m].x, ch[(mp+i)%m].y);
    }
}