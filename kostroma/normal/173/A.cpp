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
    ios_base::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

//#define int li

int n, m, k;
string s, q;

string a, b;

pair <int, int> answer;

int win (char c, char t)
{
    if (c==t)
        return 0;
    if (c=='R')
    {
        if (t=='S')
            return 1;
        else
            return -1;
    }
    if (c=='S')
    {
        if (t=='P')
            return 1;
        else
            return -1;
    }
    if (c=='P')
    {
        if (t=='R')
            return 1;
        else
            return -1;
    }
}

void solve()
{  
    cin>>n;
    cin>>s>>q;
    m=s.length();
    k=q.length();
    int l=m*k;
    for (int i=0; i<k; i++)
        a+=s;
    for (int j=0; j<m; j++)
        b+=q;
    for (int i=0; i<n%l; i++)
    {
        int cur=win(a[i], b[i]);
        if (cur==1)
            answer.second++;
        if (cur==-1)
            answer.first++;
    }
    n/=l;
    pair <int, int> now;
    for (int i=0; i<l; i++)
    {
        int cur=win(a[i], b[i]);
        if (cur==1)
            now.second++;
        if (cur==-1)
            now.first++;
    }
    answer.first+=n*now.first;
    answer.second+=n*now.second;
    cout<<answer.first<<' '<<answer.second;
}