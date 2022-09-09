#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef pair <li, li> pli;
typedef vector <int> vi;
typedef vector <li> vli;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
        freopen ("in.txt", "r", stdin);
#endif
        int t=1;
        while (t--)
                solve ();
        return 0;
}
//caution: is int really int?
//#define int li
int n;
pi a[100500];
pi sorted[100500];
int good (int u)
{
        while ( u>0 )
        {
                int r=u%10;
                if (r!=4 && r!=7)
                        return 0;
                u/=10;
        }
        return 1;
}
map <pi, int> m;
vector <pi> ans;
void solve ()
{
        cin>>n;
        int g=-1;
        for (int i=0; i<n; i++)
        {
                cin>>a[i].first;
                a[i].second=i;
                if ( good (a[i].first) )
                        g=i;
                sorted[i]=a[i];
                m[sorted[i]]=i;
        }
        sort (sorted, sorted+n);
	bool f=true;
	for ( int i=0; i<n; i++ )
		if ( a[i].first!=sorted[i].first )
			{
				f=false;
				break;
			}
	if (f)
	{
		cout<<"0"; return;
	}
        if (g==-1)
        {
                cout<<"-1";
                return;
        }
        for (int i=0; i<n; i++)
        {
                pi cur=sorted[i];
                int ind=m[cur];
                if (ind==g)
                        continue;
                if (i==ind)
                        continue;
                if ( i==g )
                {
                        swap (a[i], a[ind]);
                        m[a[ind]]=ind;
                        m[a[i]]=i;
                        ans.pb (mp(i, ind));
                        g=ind;
                }
                else 
                {
                        swap (a[i], a[g]);
                        swap (a[i], a[ind]);
                        m[a[i]]=i; m[a[g]]=g; m[a[ind]]=ind;
                        ans.pb ( mp (i, g) );
                        ans.pb (mp (i, ind));
                        g=ind;
                }
        }
        cout<<ans.size()<<endl;
        for (int i=0; i<ans.size(); i++)
                cout<<ans[i].first+1<<' '<<ans[i].second+1<<endl;
}