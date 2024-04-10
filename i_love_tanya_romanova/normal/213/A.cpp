/*
Again I see you standing there watching me.
Your gaze, those eyes are tantalizing openly, inviting me to get close to you,
can't help myself.
There's fascination in the air.
I try to fight this strong sensation but there's no chance to escape
from this temptation.
Feels like I've known you before, repeating phrases,
but I yearn for something more.
I know I can't stay by your side forever,
but I know I won't forget your beauty,
my Black Diamond.
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;
  
  long ps,tans,n,sz[1000],tsz[1000];
  long usd[1000],todo,needs[500][500];
  long tp[1000],q,start,ans;
  
  void goright()
  {
       if (ps==3)ps=1;
       else ps++;
       ++tans;
  }
  
  int havemove()
  {
      for (int i=1;i<=n;i++)
      if (tsz[i]==0&&usd[i]==0&&tp[i]==ps)
      return i;
      return 0;
  }
  
  void domove(long v)
  {
       usd[v]=1;
       --todo;
       ++tans;
       for (int j=1;j<=n;j++)
       {
           if (needs[v][j]==1&&usd[j]==0)
           {
            --tsz[j];
           }
       }
  }
  
int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>tp[i];

for (int i=1;i<=n;i++)
{
    cin>>sz[i];
    for (int j=1;j<=sz[i];j++)
    {
        cin>>q;needs[q][i]=1;
    }
}

ans=1000000;

for (start=1;start<=3;++start)
{
  //  cout<<endl;
    
    tans=0;
    
    for (int j=1;j<=n;j++)
    usd[j]=0;
    for (int j=1;j<=n;j++)
    tsz[j]=sz[j];
    todo=n;
    
    ps=start;
    while (todo>0)
    {
      //    cout<<ps<<" "<<tans<<" "<<todo<<endl;
          
          if (havemove()>0)
          {
                           domove(havemove());
          }
          else
          {
           goright();
          }
    }
    
    ans=min(ans,tans);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}