/*
I've been a prisoner trapped in by fear
Ordered for the rest of my life
Condemned in a jail cell ain't seen life in years
Escape is the only way out

Restart my life or self destruction
To climb this wall of dark construction
Holding the quest for freedom
That beckons me

My sanity is all but gone my patience is growing very weak
I need to get a hold of myself
I stare at the wall for the right time has come
Escape must occur on this night

Restart my life or self destruction
To climb this wall of dark construction
Holding the quest for freedom
That beckons me

Stand in my way and I'll run you straight through
There's no one to stop me now
For I'm on the loose and I'm ready to start
Torture and hell an this town

Over the wall

The search will not stop and hounds will not rest
Till I am back in my cell
For if I am caught, I'll try it again
Over the wall I will go, I will go
Go

Restart my life or self destruction
To climb this wall of dark construction
Holding the quest for freedom
That beckons me

Over the wall
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

string st;
vector<long> vec;
long op;
long cl;
long bal;
long last;
long er;
long rem;

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 if (st[i]=='('){++op;continue;}
 if (st[i]==')'){++cl;continue;}
 if (st[i]=='#'){vec.push_back(i);last=i;}
}

if (cl+vec.size()>op)
{
 cout<<-1<<endl;
 return 0;
}

rem=op-(cl+vec.size());

bal=0;
er=0;

for (int i=0;i<st.size();i++)
{
 if(st[i]=='(')
 {
  ++bal;continue;
 }
 if (st[i]==')')
 {
  --bal;if (bal<0)er=1;
  continue;
 }
 if (st[i]=='#')
 {
  bal--;
  if (i==last)bal-=rem;
  if (bal<0)er=1;
 }
}

if (bal!=0)
 er=1;
 
if (er)
{
 cout<<-1<<endl;
 return 0;
}

for (int i=0;i<vec.size();i++)
{
 if (i+1==vec.size())
  cout<<1+rem<<endl;
  else cout<<1<<endl;   
}

cin.get();cin.get();
return 0;}