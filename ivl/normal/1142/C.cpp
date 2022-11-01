#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define next nextmrs
#define prev prevmrs

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

typedef pair<ll, ll> Point;

int n;
Point pts[100005];

ll ccw(Point a, Point b, Point c){
  return
    a.x*(b.y-c.y) + 
    b.x*(c.y-a.y) + 
    c.x*(a.y-b.y);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n){
    cin >> pts[i].x >> pts[i].y;
    pts[i].y -= pts[i].x*pts[i].x;
  }

  sort(pts, pts+n);
  vector<Point> hull;
  REP(i,n){
    Point pt = pts[i];
    while (hull.size() >= 2 && ccw(hull[hull.size()-2], hull[hull.size()-1], pt) >= 0) hull.pop_back();
    if (hull.size() == 1 && hull.back().x == pt.x) hull.pop_back();
    hull.pb(pt);
  }

  cout << hull.size()-1 << endl;
  
  return 0;
}