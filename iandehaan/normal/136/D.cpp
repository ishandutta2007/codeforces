#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

struct Point { 
    int x, y; 
}; 

// A utility function to find square of distance 
// from point 'p' to point 'q' 
int distSq(Point p, Point q) 
{ 
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y); 
} 
  
// This function returns true if (p1, p2, p3, p4) form a 
// square, otherwise false 
bool isSquare(Point p1, Point p2, Point p3, Point p4) 
{ 
    int d2 = distSq(p1, p2); // from p1 to p2 
    int d3 = distSq(p1, p3); // from p1 to p3 
    int d4 = distSq(p1, p4); // from p1 to p4 
  
    if (d2 == 0 || d3 == 0 || d4 == 0)     
        return false; 
  
    // If lengths if (p1, p2) and (p1, p3) are same, then 
    // following conditions must met to form a square. 
    // 1) Square of length of (p1, p4) is same as twice 
    // the square of (p1, p2) 
    // 2) Square of length of (p2, p3) is same 
    // as twice the square of (p2, p4) 
  
    if (d2 == d3 && 2 * d2 == d4 
        && 2 * distSq(p2, p4) == distSq(p2, p3)) { 
        return true; 
    } 
  
    // The below two cases are similar to above case 
    if (d3 == d4 && 2 * d3 == d2 
        && 2 * distSq(p3, p2) == distSq(p3, p4)) { 
        return true; 
    } 
    if (d2 == d4 && 2 * d2 == d3 
        && 2 * distSq(p2, p3) == distSq(p2, p4)) { 
        return true; 
    } 
  
    return false; 
} 

// tests if angle abc is a right angle
int IsOrthogonal(Point a, Point b, Point c)
{
    return (b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0;
}

int IsRectangle(Point a, Point b, Point c, Point d)
{
    return
        (IsOrthogonal(a, b, c) &&
        IsOrthogonal(b, c, d) &&
        IsOrthogonal(c, d, a)) ||
        (IsOrthogonal(a, c, b) &&
        IsOrthogonal(c, b, d) &&
        IsOrthogonal(b, d, a)) ||
        (IsOrthogonal(a, c, d)
        && IsOrthogonal(c, d, b)
        && IsOrthogonal(d, b, a)) ||
        (IsOrthogonal(a, b, d)
        && IsOrthogonal(b, d, c)
        && IsOrthogonal(d, c, a));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Point pts[8];
    for (int i = 0; i < 8; i++) cin >> pts[i].x >> pts[i].y;

    for (int mask = 0; mask < (1 << 8); mask++) {
        if (__builtin_popcount(mask) != 4) continue;
        vector<Point> rect;
        vector<Point> other;
        for (int i = 0; i < 8; i++) {
            if (mask & (1 << i)) {
                //cout << i+1 << ' ';
                rect.pb(pts[i]);
            } else {
                other.pb(pts[i]);
            }
        }
        //cout << endl;

        if (isSquare(rect[0], rect[1], rect[2], rect[3])) {
            //cout << "square" << endl;
            if (IsRectangle(other[0], other[1], other[2], other[3])) {
                cout << "YES" << endl;
                for (int i = 0; i < 8; i++) {
                    if (mask & (1 << i)) {
                        cout << i+1 << ' ';
                    }
                }
                cout << endl;
                for (int i = 0; i < 8; i++) {
                    if (!(mask & (1 << i))) {
                        cout << i+1 << ' ';
                    }
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}