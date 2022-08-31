/*
Melancholy - still my desire for thy precious tragedian wine...
Sweep me away, into the vale of thine!
Where sorrow's strong and so is joy.

Melancholy - still my desire, O let my heart by thee inspire...
O fill the air with thy sweet scent,
Let thy light, thy star crescent.

Wherever she dwells I will bid a farewell sigh
For she dwells with beauty - beauty that must die
And deep inside me I will wait for her return
To her enchanting, awe-inspiring flame I'll yearn

O lust and rueful thought be mine,
My soul enhanced, desires...
Melancholy.
My heart is thine.
*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define count adsgasdgasdg

using namespace std;

long n,m;
string st;
long ar[2200][2200];
set<pair<long, long> > todel;
set<pair<long, long> > ::iterator it;
pair<long, long> tp,tp1;

bool check(long a,long b)
{
 if (todel.find(make_pair(a,b))!=todel.end())return false;
 if (ar[a][b]==1)return false;
 if (ar[a-1][b]==1&&ar[a-1][b+1]==1&&ar[a][b+1]==1)
  return true;
 if (ar[a+1][b]==1&&ar[a+1][b+1]==1&&ar[a][b+1]==1)
  return true;
 if (ar[a-1][b]==1&&ar[a-1][b-1]==1&&ar[a][b-1]==1)
  return true;
 if (ar[a+1][b]==1&&ar[a+1][b-1]==1&&ar[a][b-1]==1)
  return true;
 return false;
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
getline(cin,st);

for (int i=1;i<=n;i++)
{
    getline(cin,st);
 for (int j=1;j<=m;j++)
  if (st[j-1]=='*')
   ar[i][j]=0;
   else ar[i][j]=1;
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  if (check(i,j))
   todel.insert(make_pair(i,j));
 }

while (todel.size())
{
 it=todel.begin();
 tp=(*it);
// cout<<tp.first<<" "<<tp.second<<endl;
 todel.erase(it);
 ar[tp.first][tp.second]=1;
 for (int di=-1;di<=1;di++)
  for (int dj=-1;dj<=1;dj++)
  {
   tp1.first=tp.first+di;
   tp1.second=tp.second+dj;
   if (check(tp1.first,tp1.second))
    todel.insert(tp1);
  }
}

for (int i=1;i<=n;i++)
{
 string res;
 for (int j=1;j<=m;j++)
   if (ar[i][j])
    res+=".";
 else res+="*";
 puts(res.c_str());
}

cin.get();cin.get();
return 0;}