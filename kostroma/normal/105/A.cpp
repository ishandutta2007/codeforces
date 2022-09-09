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
int n, m;
ld k;
pair <string, int> nav[100];
string newnav[100];
vector <pair <string, int> > ans;
void solve ()
{
        cin>>n>>m>>k;
        for ( int i=0; i<n; i++ )
                cin>>nav[i].first>>nav[i].second;
        for ( int i=0; i<m; i++ )
                cin>>newnav[i];
        for ( int i=0; i<n; i++)
        {
                ld cur=(ld)nav[i].second;
                cur*=k;
                int t=(int)(cur+1e-7);
                if (t>=100)
                        ans.pb ( mp(nav[i].first, t) );
        }
        for (int i=0; i<m; i++)
        {
                bool flag=false;
                for ( int j=0; j<ans.size(); j++ )
                        if (ans[j].first==newnav[i])
                        {
                                flag=true;
                                break;
                        }
                if (!flag)
                        ans.pb ( mp (newnav[i], 0) );
        }
        sort (ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for ( int i=0; i<ans.size(); i++ )
                cout<<ans[i].first<<' '<<ans[i].second<<endl;
}