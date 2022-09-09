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

string s;

string is;

int num[300];

void solve()
{  
    cin>>s;
    is=s;
    for (int i=0; i<s.length(); i++)
        num[s[i]]++;
    sort(all(is));
    is.resize( unique(all(is)) - is.begin() );
    string ans;
    reverse (all(is));
    int now=0;
    for (int i=0; i<s.length(); i++)
    {
        num[s[i]]--;
        if (is[now]==s[i])
            ans+=is[now];
        while (num[is[now]]==0)
            ++now;
        if (now==is.length())
            break;
    }
    cout<<ans;
}