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
#define all(a) a.begin(), a.end()

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
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

//#define int li

int n, m;
int a[1000500], b[1000500];

int pos1[1000500];
int pos[1000500];

void solve()
{  
    cin>>n>>m;
    for (int i=0; i<n; i++)
        cin>>a[i];
    memset (pos1, -1, sizeof pos1);
    for (int i=0; i<m; i++)
    {
        cin>>b[i];
        pos1[b[i]]=i;
    }
    for (int i=0; i<n; i++)
        pos[i]=pos1[a[i]];
    
    int ans=0;
    queue <int> q;
    int last=-1;
    for (int i=0; i<2*n; i++)
    {
        int cur=pos[i%n];
        if (cur==-1)
        {
            last=-1;
            while (!q.empty())
                q.pop();
            continue;
        }
        if (last>cur)
        {
            while (!q.empty())
            {
                int now=q.front();
                if ( now>last || now<=cur)
                    q.pop();
                else
                    break;
            }
            q.push(cur);
            ans=max(ans, (int)q.size());
        }
        else
        {
            while (!q.empty())
            {
                int now=q.front();
                if (now>last && now<=cur)
                    q.pop();
                else
                    break;
            }
            q.push(cur);
            ans=max(ans, (int)q.size());
        }
        last=cur;
    }
    if (ans>n)
        ans=n;
    cout<<ans;
}