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

int n, k;
int a[100];
void solve ()
{
      cin>>n>>k;
      for (int i=0; i<n; i++)
          cin>>a[i];
      sort (a, a+n);
      reverse (a, a+n);
      int ans=0;
      int u=-1;
      for (int i=0; i<n && a[i]>0; i++)
      {
          u=i;
      }
      k=min(k, u+1);
      for (int i=0; i<=u; i++)
          if (a[i]>=a[k-1])
              ans++;
      cout<<ans;
          
      
}