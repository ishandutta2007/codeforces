/*
Adonai, elohim, el shaddai...
Thou hast become the father of lies,
And I serve thee, henceforth... no more

Becoming thus the essence of sedition;
The steadfast gleam of the unsheated rapier,
The falchion's forceful thrust
At the heart of thy empire... the adam kadmon
To impart the knowledge - the cognizance - of thine

For this I slither in aspect through eden's gleanings
For this I bid cain slayeth his brother
For this I rend the weakest salient of thy diadem,
As I, its jewel and very metal shall reflect no more
Your light - the light of enslavement;
The essence of constancy and misaligned justice
To a multitude that knows no freedom...
Ignorant of how subtle the fetter tightens

They shall raise me a saviour - and crown thee a liar
For this I strike with balanced blade,
And spit upon the throes of thine angels' desire

I will not serve... henceforth
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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

long n,k,ans,ar[200][200],s,m;
long v1,v2,t1,t2;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  cin>>ar[i][j];

ans=k+1;

if (m<=10)
{
 for (int mask=0;mask<(1<<m);mask++)
 {
  s=0;
  for (int j=0;j<m;j++)
   {if (ar[1][j+1]>0&&((mask&(1<<j))==0))++s;
   if (ar[1][j+1]==0&&((mask&(1<<j))>0))++s;}
  for (int i=2;i<=n;i++){t1=t2=0;
   for (int j=1;j<=m;j++)
   {
    v1=(mask&(1<<(j-1)));
    v2=ar[i][j];
    if (v1>1)v1=1;
    if (v1!=v2)++t1;else ++t2;
   }s+=min(t1,t2);}
   ans=min(ans,s);
 }
}
else
{
 for (int i=1;i<=n;i++)
 {
   s=0;
   for (int j=1;j<=n;j++)
    {t1=t2=0;
    for (int q=1;q<=m;q++)
    {
     if (ar[j][q]!=ar[i][q])++t1;else ++t2;
    }
    s+=min(t1,t2);
    }
   ans=min(ans,s);
 }
}
//cout<<ans<<endl;
if (ans>k)ans=-1;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}