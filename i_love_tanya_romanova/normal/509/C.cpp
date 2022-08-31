/*
On the dunes of bad taste
I surf beneath the burning moon
The heat peels off my skin
but I won't hide like the other fools

Beyond hypnosis
Beyond the norm
Beyond the hypocrites
Melt the cerebrae

I'm a man of low morals, and everything
I touch ends up crushed into dust

On the shores of brain attack
I bathe above the lava core
The fumes keep away the ordinary
With a smile I plunge and dive

I'm a man of low morals, and everything
I touch ends up crushed into dust
Satisfaction, downfall
My teeth kissed concrete once again
Flesh dripping grin
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
#define MAG 10000

using namespace std;

long n,s[1<<10];
vector<long> v[1<<10];
long spre,slim,found;
long trem,tail;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>s[i];
 for (int j=0;j<666;j++)
  v[i].push_back(0);
}

for (int j=0;j<666;j++)
v[0].push_back(0);

for (int i=1;i<=n;i++)
{
 v[i]=v[i-1];
 spre=s[i-1];
 slim=0;
 found=0;
 
 for (int j=665;j>=0;--j)
 {
  if (found)break;
  spre-=v[i][j];
  for (int q=v[i][j]+1;q<=9&&found==0;q++)
  {
   trem=spre+q;
   tail=s[i]-trem;
   if (tail>=0&&tail<=slim)
   {
    v[i][j]=q;
    for (int t=665;t>j;t--)
    {
     if (tail>9)
     {
      v[i][t]=9;
      tail-=9;
     }       
     else
     {
      v[i][t]=tail;
      tail=0;
     }         
    }
    found=1;
    v[i][j]=q;
   }
  }
  slim+=9;
 }
}

for (int i=1;i<=n;i++)
{
 reverse(v[i].begin(),v[i].end());
 while (v[i].size()>1&&v[i].back()==0)
  v[i].pop_back();
 reverse(v[i].begin(),v[i].end());
 for (int j=0;j<v[i].size();j++)
 {
  cout<<v[i][j];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}