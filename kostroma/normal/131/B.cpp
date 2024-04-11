#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair <int, int> pi;
typedef long double ld;
typedef long long li;
void solve();
int main ()
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
	solve();
	return 0;
}
#define int li
int n;
int t[100500];
int pluss[20], minuss[20], nulls;
void solve()
{
     cin>>n;
     for (int i=0; i<n; i++)
     {
          cin>>t[i];
          if (t[i]<0)
          minuss[-t[i]]++;
          if (t[i]>0)
          pluss[t[i]]++;
          if (t[i]==0)
          nulls++;
     }
     int ans=nulls*(nulls-1)/2;
     for (int i=1; i<=10; i++)
     ans+=pluss[i]*minuss[i];
     cout<<ans;
}