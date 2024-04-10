/*
Today is the day where redemption sings to me.
For years of doing the devil's work, for years I've tried to find it.
Living every second of the hopeless,
Learning every minute from the powerless.

Through this tunnel
I fear I see the light
I can feel it when I look to the sky

We only see what we want to see,
We only see what we want to see.
Give me the chance,
To prove who I am.
I'll never deny,
There's more to this life than this.

[Chorus:]
Sometimes things are not what they seem
Sometimes things are not what they seem
I have waited so long (Waited so long) to make this your day
Let this moment be the one that you remember forever.
I'm fighting for my life,
This may be the last time.
What can I do to cure this disaster?

Hard to tell who's wrong or right,
Broken pieces, let's put what we still have together (together)
Life was so good when you had control.
How the times have changed, How the times have changed for you.

[Chorus]

I am in control.
How the times have changed
I am in control of my life.
It never was yours!
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

long m,s,lwr,upr;
long ar[1<<10];
string st;
long rem;

string get_big()
{
 long ts=s;
 for (int i=0;i<m;i++)
 {
  if (ts>9)ar[i]=9;
  else ar[i]=ts;
  ts-=ar[i];
 }
 string res;
 for (int i=0;i<m;i++)
  res+=char(ar[i]+48);
 return res;
}

string get_small()
{
 
 long ts=s;
 if (ts==0)
  return "0";
 long limi=ts-9*(m-1);
 if (limi<0)limi=1;
 ar[0]=limi;
 ts-=limi;
 for (int i=1;i<m;i++)
 {
  rem=(m-i-1)*9;
  limi=ts-rem;
  if (limi<0)limi=0;
  //cout<<rem<<" "<<ts<<" "<<limi<<endl;
  ar[i]=limi;
  ts-=limi;
 }
 string res;
 for (int i=0;i<m;i++)
  res+=char(ar[i]+48);
 return res;
}

int main(){
//freopen("billing.in","r",stdin);
//freopen("billing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>s;

if (m>1)
{
 lwr=1;
 upr=9*m;
}
else
{
 lwr=0;
 upr=9*m;
}

if (s<lwr||s>upr)
{
 cout<<-1<<" "<<-1<<endl;
 return 0;
}


cout<<get_small()<<" "<<get_big()<<endl;


cin.get();cin.get();
return 0;}