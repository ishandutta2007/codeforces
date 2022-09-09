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
#define int li
int n;
vector < int > e[100500];
int be[100500];
int is (int s)
{
    while (s>0)
    {
        int r=s%10;
        if (r!=4 && r!=7)
            return 0;
        s/=10;
    }
    return 1;
}
void dfs (int v, int num)
{
    be[v]=num;
    for (int i=0; i<e[v].size(); i++)
        if ( be[e[v][i]]==0 )
        {
       // cout<<"!";
            dfs (e[v][i], num);
        }
}
int comp[100500];
void solve ()
{
    cin>>n;
    for (int i=0; i<n-1; i++)
    {
        int a=0, b=0, r=0;
        scanf ("%I64d%I64d%I64d", &a, &b, &r);
        a--; b--;
        if (!is(r))
        {
            e[a].pb (b);
            e[b].pb (a);
        }
    }
    int u=1;
    for (int i=0; i<n; i++)
        if (be[i]==0)
        {
            dfs (i, u++);
        }
    for (int i=0; i<n; i++)
        comp[be[i]]++;
    int ans=0;
    for (int i=1; i<u; i++)
    {
        int cur=comp[i];
        ans+=cur*(n-cur)*(n-cur-1);
    }
    cout<<ans;
}