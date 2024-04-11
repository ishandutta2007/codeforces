#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;
/*
BE CAREFUL: ISN'T INT EQUAL TO LONG LONG?

REAL SOLUTION AFTER MAIN FUNCTION
*/
#define mp make_pair
#define pb push_back
typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
void solve();

int main ()
{

#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int t=1;
    while (t--)
        solve();
    return 0;
}

//#define int li

int n;
int p[30000];

vector <int> del;

void solve ()
{
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>p[i];
    for (int i=1; i*i<=n; i++)
        if (n%i==0)
        {
            del.pb(i);
            if (i*i!=n)
                del.pb(n/i);
        }
    int ans=-(1<<30);
    for (int i=0; i<del.size(); i++)
    {
        int cur=del[i];
        if (n/cur<3)
            continue;
        for (int j=0; j<cur; j++)
        {
            int curans=0;
            int k=j;
            do
            {
                curans+=p[k];
                k+=cur; k%=n;
            }
            while(k!=j);
            ans=max(ans, curans);
        }
    }
    cout<<ans;
}