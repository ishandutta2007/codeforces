/*
Turn the wheel of torture
Spin the rack of pain
Now many souls will suffer
To satisfy your game
The smell of death surrounds you
How can you hide your shame
Can we stop this nightmare
Before it starts again

How can you sleep at night
Can you hear their voices in your head
We wrote this song for you
This is your song of evil
Song of evil

Stop this reign of terror
Are we all insane
Crush the voice of freedom
How many will remain
The devil walks beside you
Your souls will burn in hell
Your final retribution
When Satan rings the bell

How can you sleep at night
Can you hear their voices in your head
We wrote this song for you
This is your song of evil
Song of evil
Can you hear their voices in your head
This is your song of evil

Turn the screws of torment
Drop the blade of fear
Hear the screams of anguish
There's no mercy here
The smell of death surrounds you
Your souls will burn in hell
Can we stop this nightmare
When Satan rings the bell

How can you sleep at night
Can you hear their voices in your head
We wrote this song for you
This is your song of evil

How can you sleep at night
Can you hear their voices in your head
We wrote this song for you
This is your song of evil
Evil, evil, evil, evil
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,mx,reg,pw[2000],deg[2000];
long qhp,dmg,bst,bp;
long used[2000];
vector<pair<long, long> > ans;

void gg1()
{
     cout<<"NO"<<endl;
     return;
}

long iter;
void gg()
{
 cout<<"YES"<<endl;
 cout<<iter<<" "<<ans.size()<<endl;
 for (int i=0;i<ans.size();i++)
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
void solve()
{
     qhp=mx;
     dmg=0;
     
     while (true)
     {
//      cout<<qhp<<" "<<dmg<<" "<<reg<<endl;
      qhp-=dmg;
 //     ++iter;
      qhp+=reg;
      if (qhp>mx)qhp=mx;
      if (qhp<=0){gg();return;}
      bst=-1;
      bp=0;
      for (int i=1;i<=n;i++)
      if (used[i]==0&&pw[i]/100.0>=qhp*1.0/mx&&deg[i]>=bst)
      {
       bst=deg[i];
       bp=i;
      }
//      cout<<bst<<endl;
      if (bst<0)
      {
       ++iter;
       if (dmg<=reg){gg1();return;}
       else continue;
      }
      else{
      dmg+=deg[bp];
      ans.push_back(make_pair(iter,bp));
      used[bp]=1;
      ++iter;
     }}
}

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>mx>>reg;
for (int i=1;i<=n;i++)
{
    cin>>pw[i]>>deg[i];
}
solve();

cin.get();cin.get();
return 0;}