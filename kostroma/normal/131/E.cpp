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
//#define int li
int n, m;
vector <int> str[100500], stolb[100500];
vector <int> dim[200500], dip[200500];
map < pair <int, int>, int > mm;
int p[10];
void solve()
{
     cin>>n>>m;
     for (int i=0; i<m; i++)
     {
          int q, w;
          cin>>q>>w;
          str[q].pb(w);
          stolb[w].pb(q);
          dim[w-q+n].pb(w);
          dip[w+q].pb(w);
     }
     for (int i=1; i<=n; i++)
     {
     sort (str[i].begin(), str[i].end()), sort (stolb[i].begin(), stolb[i].end());
     if (str[i].size()>1)
     {
          mm[mp(i, str[i][0])]++;
          mm[mp(i, str[i][str[i].size()-1])]++;
          for (int j=1; j<str[i].size()-1; j++)
          mm[mp (i, str[i][j])]+=2;
     }
     if (stolb[i].size()>1)
     {
          mm[mp(stolb[i][0], i)]++;
          mm[mp(stolb[i][stolb[i].size()-1], i)]++;
          for (int j=1; j<stolb[i].size()-1; j++)
          mm[mp (stolb[i][j], i)]+=2;
     }
     }
     for ( int i=1; i<=2*n; i++ )
     {
     sort (dim[i].begin(), dim[i].end()), sort (dip[i].begin(), dip[i].end());
     if (dim[i].size()>1)
     {
          mm[mp (dim[i][0]+n-i, dim[i][0])]++;
          mm[mp (dim[i][dim[i].size()-1]+n-i, dim[i][dim[i].size()-1])]++;
          for (int j=1; j<dim[i].size()-1; j++)
          mm[mp (dim[i][j]+n-i, dim[i][j])]+=2;
     }
     if (dip[i].size()>1)
     {
          mm[mp (i-dip[i][0], dip[i][0])]++;
          mm[mp (i-dip[i][dip[i].size()-1], dip[i][dip[i].size()-1])]++;
          for (int j=1; j<dip[i].size()-1; j++)
          mm[mp (i-dip[i][j], dip[i][j])]+=2;
     }
     }


     for (map < pair <int, int>, int >::iterator i=mm.begin(); i!=mm.end(); i++)
          p[i->second]++;
     int sum=0;
     for (int i=1; i<=8; i++)
          sum+=p[i];
     p[0]=m-sum;
     for (int i=0; i<=8; i++)
          cout<<p[i]<<' ';
}