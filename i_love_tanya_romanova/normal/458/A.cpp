/*
There was a sign on an ancient veil,
A dream that never really was
She only ever seemed to hope for a world
So surreal to the touch
She doesn't want to wake
She only wants to sleep
Afraid of what they seek and where she's been
When she awakes, she bends to her knees to pray
Praying for the secret to be safe

Come take my hand
Follow the path to infinity
Come take my hand
Trapped in the dark for eternity
Come take my hand...

After all when the kingdom falls
Her walls are shattered from within
She tries to flee but she's trapped in this curse
Waiting for the cycle to begin
She doesn't want to wake from her eternal sleep
Afraid of what they know and where she is
She doesn't follow faith she's stuck in her belief
Sorrow is the color of her dream...

Long ago...
When she first opened her eyes
there's no tomorrow
The sun will never shine, no...
The sun will never shine
Yeah!

The sun will never shine on you
Daylight blinds your way The sun will never shine through you
Now accept this cold embrace

Come take my hand
Follow the path to infinity
Come take my hand
See everything that you want to see
Come take my hand
Find everything that you sought to seek
Come take my hand
Trading your life for immortality
Come take my hand...

Long ago...
When she first opened her eyes
There's no tomorrow
The sun will never shine, no...
The sun will never shine
Yeah!

The sun will never shine on you
Daylight blinds your way
There sun will never shine on you
No the sun will never shine...
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

double gld,res;

string st1,st2;
long q;

char cmp(string st1,string st2)
{
 for (int i=0;i<st1.size();i++)
 {
  if (st1[i]==st2[i])continue;
  if (st1[i]<st2[i])return '<';
  if (st1[i]>st2[i])return '>';
 }
 return '=';
}

int main(){
//freopen("refrain.in","r",stdin);
//freopen("refrain.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

/*
gld=sqrt(5.0)+1;
gld/=2;
double res=1;
for (int i=1;i<=10;i++)
{ cout<<res<<endl;
res*=gld;
// cout<<res<<endl;
}
*/

cin>>st1;
cin>>st2;
reverse(st1.begin(),st1.end());
reverse(st2.begin(),st2.end());
while (st1.size()<st2.size())st1+='0';
while (st2.size()<st1.size())st2+='0';
st1+="000";
st2+="000";
reverse(st1.begin(),st1.end());
reverse(st2.begin(),st2.end());

for (int i=1;i<st1.size();i++)
{
 if (st1[i]=='1'&&st1[i-1]=='1')
 {st1[i-2]='1';st1[i]=st1[i-1]='0';
  q=i-2;
  while (q>0&&st1[q]=='1'&&st1[q-1]=='1')
  {
   st1[q-1]=st1[q]='0';
   st1[q-2]='1';
   q-=2;
  }
 }
}


for (int i=1;i<st2.size();i++)
{
 if (st2[i]=='1'&&st2[i-1]=='1')
 {
  st2[i-2]='1';st2[i]=st2[i-1]='0';
  q=i-2;
  while (q>0&&st2[q]=='1'&&st2[q-1]=='1')
  {
   st2[q-1]=st2[q]='0';
   st2[q-2]='1';
   q-=2;
  }
 }
}

//cout<<st1<<endl;
//cout<<st2<<endl;

cout<<cmp(st1,st2)<<endl;

cin.get();cin.get();
return 0;}