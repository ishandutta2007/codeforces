/*
This one came from looking
This one opened twice
These two seemed smooth as silk
Flush against my eyes

This one needed stitches
And this one came from rings
This one isn't even there
But I feel it more because you don't care

Yeah, cut right into me
Yeah because I am made of scars
Yes, I am made of scars

This one had it coming
This one found a vein
This one was an accident
But never gave me pain

This one was my father's
And this one you can't see
This one had me scared to death
But I guess I should be glad I'm not dead

Yeah, cut right into me
Yeah because I am made of scars
Yes, I am made of scars, yeah

God, don't you believe the hype
God, don't you believe the hype
God, don't you believe the hype
Don't you believe the hype
Don't believe, don't believe

And I will find a way
Everything you are, I will betray
I swear that I will find a way
Everything you are is inside of me

This one was the first one
This one had a vice
This one here, I like to rub
On dark and stormy nights

This one was the last one
I don't remember how
But I remember blood and rain
And I never saw it coming again

Yeah, cut right into me
Yeah because I am made of scars
Yes, I am made of scars

Yes, I am made of scars
Yes, I am made of scars
That's what I'm made of
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

long n;
long ar[5050][5050];
string st;
long c_st;
vector<long> cycle;
long c_end;
long v1,v2,v3;
long p[5050];
long cl[5050];

bool dfs(long v)
{
 cl[v]=1;
 for (int i=0;i<n;i++)
 {
  if (ar[v][i]==0)continue;
  if (cl[i]==0)
  {
   p[i]=v;
   if (dfs(i))return true;
  }
  else if (cl[i]==1)
  {
   c_end=v;
   c_st=i;
   return true;
  }
 }
 cl[v]=2;
 return false;
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
    cin>>st;
    for (int j=0;j<st.size();j++)
     ar[i][j]=st[j]-48;
}

c_st=-1;
for (int i=0;i<n;i++)
{
 if (dfs(i))break;   
}

if (c_st==-1)
{
 cout<<-1<<endl;
 return 0;
}

long v=c_end;

while (v!=c_st)
{
 cycle.push_back(v);
 v=p[v];
}
cycle.push_back(v);
reverse(cycle.begin(),cycle.end());

while (cycle.size()>3)
{
 v1=cycle[0];
 v2=cycle[1];
 v3=cycle[2];
 if (ar[v3][v1]==1)
 {
  cycle.clear();
  cycle.push_back(v1);
  cycle.push_back(v2);
  cycle.push_back(v3);
 }
 else
 {
  cycle.erase(cycle.begin()+1);
 }
}

for (int i=0;i<cycle.size();i++)
{
 if (i)cout<<" ";
 cout<<cycle[i]+1;   
}
cout<<endl;

cin.get();cin.get();
return 0;}