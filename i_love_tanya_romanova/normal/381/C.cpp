/*
Black clouds on the horizon
Great thunder and burning rain
His chariot pounding,
I heard the heavens scream his name

I watched as he shouted
To the giants that died that day
He hehd up his hammer high
And called to odin for a sign

Thor the mighty, Thor the brave
Crush the infidels in your way
By your hammer let none be saved
Live to die on that final day
Gods, monsters and men
Well die together in the end

God of thunder, God of rain
Earth shaker who feels no pain
The powerhead of the universe
Now send your never ending curse

Swing your hammer to crack the sky
Lift your cape so that you might fly
Back to Odin and the gods on high
And leave this mortal world
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,m,a[300000],b[300000],tp[300000],ans[300000],test[300000],quer;
long long qp,ad,qsize;
vector<long long> v;
long long w;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>m;
for (int i=1;i<=m;i++)
{
 cin>>tp[i];
 cin>>a[i];
 if (tp[i]==2)cin>>b[i];
}
cin>>quer;
for(int i=1;i<=quer;i++)
{
 cin>>test[i];
}
test[quer+1]=1e18;

qp=1;

for (int i=1;i<=m;i++)
{
    if (tp[i]==1)ad=1;
    else ad=a[i]*b[i];
    while (test[qp]<=qsize+ad)
    {
     if (test[qp]<=v.size())ans[qp]=v[test[qp]-1];
     else
     {
      if (tp[i]==1)ans[qp]=a[i];
      else 
           {
            w=test[qp]-qsize;
            --w;
            w%=a[i];
            ans[qp]=v[w];
           }
     }
     ++qp;
    }
   if (tp[i]==1)v.push_back(a[i]);
   else
   {
    for (int j=1;j<=b[i];j++)
     {
      for (int q=1;q<=a[i];q++)
      {
          v.push_back(v[q-1]);
          if (v.size()>101000)break;
      }
      if (v.size()>101000)break;
     }
   }
   qsize+=ad;
}

for (int i=1;i<=quer;i++)
{
 if (i-1)cout<<" ";
 cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}