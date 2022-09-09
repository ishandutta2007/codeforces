#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
#include <memory.h>

using namespace std;

/*
CAUTION: IS INT REALLY INT, BUT NOT LONG LONG?
REAL SOLTION AFTER MAIN FUNCTION
*/

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <li> vli;
typedef pair <li, li> pli;

void solve();
int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    //ios_base::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

//#define int li
double eps=1e-9;
bool DoubleEqual (ld q, ld w){return fabs(q-w)<eps;}
bool DoubleLess (ld q, ld w){return q+eps<w;}
bool DoubleMore (ld q, ld w){return q>w+eps;}

template <class T>
class Point
{
public:
    T x, y;
    Point(){}
    Point (T X, T Y) {x=X; y=Y;}
    void scan(){ cin>>x>>y; }
    void print() { cout<<x<<' '<<y<<' '; }
    Point operator + (Point b) { return Point(x+b.x, y+b.y); }
    Point operator - (Point b) { return Point(x-b.x, y-b.y); }
    T operator * (Point b) { return x*b.y-y*b.x; }
    Point operator * (T b) { return Point(b*x, b*y); }
    Point operator / (T b) { return Point(x/b, y/b); }
    T operator % (Point b) { return x*b.x+y*b.y; }
    bool operator < (const Point &b) const { return x+eps<b.x || ( fabs(x-b.x)<eps && y+eps<b.y ); }
    bool operator > (const Point &b) const { return x>b.x+eps || ( fabs(x-b.x)<eps && y>b.y+eps ); }
    T dd() { return x*x+y*y; }
    double dist() { return sqrt(x*x+y*y); }
    bool operator != (Point b) { return fabs(x-b.x)>eps || fabs(y-b.y)>eps; }
    bool operator == (Point b) { return fabs(x-b.x)<eps && fabs(y-b.y)<eps; }
};

Point <double> a[100500];
Point <double> b[100500];
int n, m;

void solve()
{
    cin>>n;
    for (int i=0; i<n; i++)
        b[n-i-1].scan();
    int mn=0;
    for (int i=0; i<n; i++)
        if (b[i]<b[mn])
            mn=i;
    for (int i=0; i<n; i++)
    {
        a[i]=b[(i+mn)%n];
    }
    for (int i=1; i<n; i++)
        a[i]=a[i]-a[0];
    a[0]=a[0]-a[0];

    /*for (int i=0; i<n; i++)
        a[i].print(), cout<<endl;*/

    cin>>m;
    int u=0;
    while (m--)
    {
        Point <double> cur;
        cur.scan();
        cur=cur-b[mn];
        //cur.print(); cout<<endl;
        if (cur<a[0])
        {
            cout<<"NO";
            return;
        }
        int l=0, r=n;
        while (l+1<r)
        {
            //if (m==0) cout<<l<<' '<<r<<endl;
            int mm=l+r; mm/=2;
            if ( atan2 ( a[mm].y, a[mm].x ) < atan2 ( cur.y, cur.x ) )
                l=mm;
            else
                r=mm;
        }
        u++;
        if ( (a[r%n]-cur)*(a[l]-cur) > - eps )
        {
            //cur.print();
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
}