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
    freopen ("out.txt", "w", stdout);
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
string s[60];

bool been[60][60];

void dfs (int x, int y)
{
    if (been[x][y])
        return;
    been[x][y]=true;
    if (x>0 && s[x-1][y]=='#')
        dfs(x-1, y);
    if (x<n-1 && s[x+1][y]=='#')
        dfs(x+1, y);
    if (y>0 && s[x][y-1]=='#')
        dfs(x, y-1);
    if (y<m-1 && s[x][y+1]=='#')
        dfs(x, y+1);
}

void solve()
{  
    cin>>n>>m;
    for (int i=0; i<n; i++)
        cin>>s[i];
    int cnt=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (s[i][j]=='#')
                cnt++;
    if (cnt<3)
    {
        cout<<"-1";
        return;
    }
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (s[i][j]=='#')
            {
                s[i][j]='.';
                memset (been, false, sizeof been);
                for (int w=0; w<n; w++)
                {
                    bool flag=true;
                    for (int k=0; k<m; k++)
                                if (s[w][k]=='#')
                                {
                                    dfs(w, k);
                                    flag=false;
                                    break;
                                }
                    if (!flag)
                        break;
                }
                bool f=true;
                for (int w=0; w<n; w++)
                    for (int k=0; k<m; k++)
                        if (s[w][k]=='#' && !been[w][k])
                        {
                            f=false;
                            break;
                        }
                if (!f)
                {
                    cout<<"1";
                    return;
                }                
                s[i][j]='#';
            }
    cout<<"2";
}