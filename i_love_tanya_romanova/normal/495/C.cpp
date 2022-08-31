/*
Every fuckin' day I sacrifice myself
Making up for a dime the company can't afford
A professional button pusher
Craving the most valued resource we have in a single serving

Leave dinner on the table, 'cause daddy's comin' home
Corruption ain't so bad after all
Routine self gratification, this parade has got to end
This parade has got to end

She bought a one way ticket on a bullet train
Guess who will be waiting at the end of the line
This is just a test
This is just a test to prove you're worthy

Witness the feast as I lie here dying of starvation
Just sneak a lil' taste no one will ever notice

As I lean over the edge of this dock
I find myself wishing I knew how to swim
These waiting room walls are closing in
But the sweet smell of a rose helps me fight this urge

Untouched, sealed up in mint condition
A pretty pre-wrapped package waiting to be torn apart
Innocence is lost, it was overrated anyway
Let me enlighten you with my touch

Leave it on the table, 'cause daddy's comin' home
It ain't so bad after all
Routine self gratification, this parade has got to end
This parade has got to end

Yeah, let it all build up
Yeah, like hand prints on the wall
This dream has blossomed
This dream has blossomed
This dream has blossomed
And wilted away satisfaction
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