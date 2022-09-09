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
int n, m, t;
int c[50][50];
int cc (int a, int b)
{
     if (b>a)
     return 0;
     return c[a][b];
}
void solve()
{
     cin>>n>>m>>t;
     for (int i=0; i<50; i++)
          c[i][0]=c[i][i]=1;
     for (int i=1; i<50; i++)
          for (int j=1; j<i; j++)
          {
                    c[i][j]=c[i-1][j-1]+c[i-1][j];
                    //cout<<c[i][j]<<endl;
          }
     int ans=0;
     for ( int i=4; i<=t-1; i++ )
     ans+=cc(n, i)*cc(m, t-i);
     cout<<ans;
}