#include <bits/stdc++.h>

#define f first
#define s second

#define int long long
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e5+500, base = 1e9+7,maxm= 10;

int need;
int ax,ay;

bool can(int x3,int y3) {
    if (need == 0)
    {
        if (x3 == 0 && y3 == 0)
            return 1;
        else
            return 0;
    }
    if ((ax * y3-ay * x3)%need==0 && (x3 * (-ax) - y3 * ay)%need==0)
        return 1;
    else
        return 0;

}
 main()
{
    int x, y;
    int x1,y1;
    cin >> x >> y>> x1>> y1 >> ax >> ay;

    need = (-ax) * ax + (-ay) * ay;
//    if (need == 0)
//    {
//        if ( (x + x1 == 0 && y +1 == 0) || (x1 - x == 0 && y1 - x == 0) || (-y + x1 == 0 && x + y1 == 0) || (-x + y1 == 0 && y + x1 == 0))
//            cout << "YES";
//        else
//            cout<<"NO";
//        return 0;
//    }
    if ( can(x + x1,y + y1) )
        return cout<<"YES",0;
    if ( can(y + x1,-x + y1))
        return cout<<"YES",0;
    if ( can(-y + x1,x + y1))
        return cout<<"YES",0;
    if ( can(-x + x1,-y + y1))
        return cout<<"YES",0;
    cout<<"NO";
}