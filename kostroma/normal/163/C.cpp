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
typedef double ld;
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

#define int li
int l, v1, v2;
int n;
int a[100500];

int ras[100500];

vector <pair <int, int> > events;

bool cmp ( pair <int, int> q, pair <int, int> w )
{
    if (q.first<w.first)
        return true;
    if (q.first>w.first)
        return false;
    return q.second<w.second;
}

void solve()
{
    cin>>n>>l>>v1>>v2;
    int s=v2*l;
    l*=(v1+v2);
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
        a[i]*=(v1+v2);
    }
    for (int i=n-1; i>=0; i--)
        a[i]-=a[0];
    for (int i=0; i<n; i++)
    {
        events.pb(mp(a[i], -1));
        ld en=a[i]-s;
        if (en<0)
            en+=2*l;
        events.pb( mp(en, 1) );
    }
    sort (events.begin(), events.end(), &cmp);
    events.pb(mp(2*l, 0));
    int cur=1;
	/*cout<<s<<endl;
	for (int i=0; i<n; i++)
		cout<<a[i]<<' ';
	cout<<endl;*/
    for (int i=1; i<n; i++)
        if ( a[i]>=s)
            break;
        else
            cur++;
    //cout<<cur<<endl;
    int last=0;
    for (int i=0; i<events.size(); i++)
    {
        pair <int, int> now=events[i];
        //printf ("%.10lf %d\n", now.first, cur);
        ras[cur]+=now.first-last;
        last=now.first;
        cur+=now.second;
    }
    for (int i=0; i<=n; i++)
        printf ("%.11lf\n", (ld)ras[i]/(ld)(l*2));
}