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
    ios_base::sync_with_stdio(0);
    int t=1;
    while (t--)
        solve();
    return 0;
}

//#define int li

int n, m, x, y;
pair <int, int> a[100500];
pair <int, int> b[100500];
vector < pair <int, int> > answer;

void solve()
{
    cin>>n>>m>>x>>y;
    for (int i=0; i<n; i++)
        cin>>a[i].first, a[i].second=i;
    for (int i=0; i<m; i++)
        cin>>b[i].first, b[i].second=i;
    sort (a, a+n);
    sort (b, b+m);
    int cur=0;
    for (int i=0; i<m; i++)
    {
        while (cur<n && a[cur].first+y<b[i].first)
            cur++;
        //cout<<cur<<endl;
        if (cur==n)
            break;
        if (a[cur].first-x<=b[i].first)
            answer.pb(mp(a[cur].second, b[i].second)), cur++;
        if (cur==n)
            break;
    }
    cout<<answer.size()<<endl;
    for (int i=0; i<answer.size(); i++)
        cout<<(answer[i].first+1)<<' '<<(answer[i].second+1)<<endl;
}