/*
This incontent industry cashing in on your misery
Selling products that decry, channeled into a consuming lie
Our own abilities have been displaced, projected onto items we're forced to own

Bloodsucking industries will get you all
Bloodsucking industries will cut your throats
Bloodsucking industries will crush you down
Bloodsucking companies will get you all

Choke us down

Caught in this wheel from birth there's no way out
This treadmill is our curse. Choke us down!
Keeping it until death is here. Choke us down!
Dignified by constricted fear. Choke us down!
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long L,l[1<<20],ps[1<<20],active[1<<20],b,f,tests,ans[1<<20];
long tp;
set<long> nice;
set<long>::iterator it;
long cur;
long id;

void check(long x)
{
 if (x+l[cur]>L)return;
 for (int i=1;i<cur;i++)
  if (active[i]>0&&ps[i]>x-b&&ps[i]<x+f+l[cur])
   return;
  nice.insert(x);
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>L>>b>>f;

cin>>tests;
for (int i=1;i<=tests;i++)
 ans[i]=-1;
 
for (int i=1;i<=tests;i++)
{
 cin>>tp;
 cur=i;
 if (tp==1)
 {
  cin>>l[i];
  nice.clear();
  check(0);
  for (int j=1;j<i;j++)
  {
   if (active[j]==1)
   {
    check(l[j]+ps[j]+b);
   }
  }
  if (nice.size()==0){cout<<-1<<endl;
   continue;}
  active[i]=1;
  it=nice.begin();
  ps[i]=(*it);
  ans[i]=(*it);
  cout<<(*it)<<endl;
 }
 else
 {
  cin>>id;
  active[id]=0;
  continue;
 }
}

cin.get();cin.get();
return 0;}