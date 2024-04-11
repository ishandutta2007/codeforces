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
int n, m, k;
string matrix[600];
int a[600][600];
int stolb[600][600], str[600][600];
int pref[600][600];
int cnt (pi q, pi w)
{
     q.first--; q.second--;
     int ans=pref[w.first][w.second];
     if (q.first==-1 && q.second==-1)
          return ans;
     if (q.first==-1)
          return ans-pref[w.first][q.second];
     if (q.second==-1)
          return ans-pref[q.first][w.second];
     return pref[w.first][w.second]-pref[w.first][q.second]-pref[q.first][w.second]+pref[q.first][q.second];
}
void solve()
{
     cin>>n>>m>>k;
     for (int i=0; i<n; i++)
          cin>>matrix[i];
     for (int i=1; i<n-1; i++)
          for (int j=1; j<m-1; j++)
               if ( matrix[i][j]=='1' && matrix[i-1][j]=='1' && matrix[i+1][j]=='1' && matrix[i][j-1]=='1' && matrix[i][j+1]=='1' )
                    a[i][j]=1;

     for (int i=0; i<n; i++)
     {
          str[i][0]=a[i][0];
          for (int j=1; j<m; j++)
          str[i][j]=str[i][j-1]+a[i][j];
     }

     for ( int i=0; i<m; i++ )
     {
          pref[0][i]=str[0][i];
          for (int j=1; j<n; j++)
               pref[j][i]=pref[j-1][i]+str[j][i];
     }
     int ans=0;
     for ( int i=0; i<n; i++ )
          for (int j=0; j<m-2; j++)
          {
               int stroka=n-1, stolbec=j+2;
               for ( ;  stroka>i+1; stroka-- )
               {
               while (stolbec<m && cnt( mp (i+1, j+1), mp (stroka-1, stolbec-1) )<k )
                    stolbec++;
               ans+=m-stolbec;

               }
          }
     cout<<ans;
}