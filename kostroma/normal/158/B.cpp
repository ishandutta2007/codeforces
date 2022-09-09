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

#ifdef _DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int t=1;
    while (t--)
                solve();
    return 0;
}

#define int li

#define MAXN 1000500

int a[10];

void solve ()
{
       int n;
       cin>>n;
       for (int i=0; i<n; i++)
       {
           int q;
           cin>>q;
           a[q]++;
       }
       int ans=0;
       while (a[1]>0 || a[2]>0 || a[3]>0 || a[4]>0)
       {
           if (a[4])
           {
               ans++;
               a[4]--;
               continue;
           }
           if (a[1]>0 && a[3]>0)
           {
               a[1]--;
               a[3]--;
               ans++;
               continue;
           }
           if (a[2]>1)
           {
               a[2]-=2;
               ans++;
               continue;
           }
           if (a[2]>0)
           {
               a[1]--;
               a[1]--;
               a[2]--;
               ans++;
               continue;
           }
           if (a[3]>0)
           {
               ans++;
               a[3]--;
               continue;
           }
           if (a[1]>0)
           {
               a[1]-=4;
               ans++;
               continue;
           }
       }
    cout<<ans;
}