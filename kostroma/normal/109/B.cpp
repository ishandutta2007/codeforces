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
int p1, p2, v1, v2, k;
int happy[5000];
int t=0;
int pere (pi e, pi r)
{
    if (e>r)
        swap (e, r);
    if (e.second<r.first)
        return 0;
    return min (r.second, e.second)-max(r.first, e.first)+1;
}
vector <pair < pi, int > > q, w;
void solve ()
{
    cin>>p1>>p2>>v1>>v2>>k;
    int p=p2-p1+1;
    int v=v2-v1+1;
    happy[t++]=0;
    for (int i=1; i<=9; i++)
    {
        for (int mask=0; mask<(1<<i); mask++)
        {
            int newnum=0;
            for ( int j=0; j<i; j++ )
                if ( mask & (1<<j) )
                    newnum=newnum*10+7;
                else 
                    newnum=newnum*10+4;
            happy[t++]=newnum;
        }
    }
    happy[t++]=1000000001;
    sort (happy, happy+t);
    int ind=0;
    int ans=0;
    for (int i=0; i<t-1; i++)
        if ( happy[i]<p1 && happy[i+1]>=p1 )
        {
            ind=i;
            break;
        }
    for ( int i=ind; i+k<t-1 && happy[i]<=p2; i++ )
    {
        int cur=pere ( mp ( happy[i+k], happy[i+k+1]-1 ), mp (v1, v2) );
       // cout<<"cur=  "<<cur<<endl;
        int z=pere ( mp ( happy[i]+1, happy[i+1]), mp (p1, p2) );
       // cout<<"z= "<<z<<endl;
        ans+=z*cur;
    }
    ind=0;
    for (int i=0; i<t-1; i++)
        if ( happy[i]<v1 && happy[i+1]>=v1 )
        {
            ind=i;
            break;
        }
    for ( int i=ind; i+k<t-1 && happy[i]<=v2; i++ )
    {
        int cur=pere ( mp ( happy[i+k], happy[i+k+1]-1 ), mp (p1, p2) );
        int z=pere ( mp ( happy[i]+1, happy[i+1]), mp (v1, v2) );
        ans+=z*cur;
    }
    if (k==1)
    {
        for (int i=0; i<t; i++)
        {
            int cur=happy[i];
            if (cur>=p1 && cur<=p2 && cur<=v2 && cur>=v1)
                ans--;
        }
    }
    printf ( "%.10Lf", (ld)ans/p/v );
}