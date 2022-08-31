/*
Look at all the freaks!
Lined up head to head
They wait for out arrival
Some are here for the show
Some are here to watch
And some to preach the bible
Hats off to the faithful
That come to waltz with us
They're doing what they wanna
Come on to the next show
Parade along with us
You won't be forgotten
You won't be forgotten

Listen to the freak show
Shouting to our songs
They sound like charging rhino
A place to meet an old friend
A place to meet some new
You can always follow
You wanna meet the clowns
When the circus comes to town?
Gather all around!
We'll remember all of you
Unless our crew dismembers you!

Come in from hell or wherever you came
Slums of the world are to us all the same
Step up and join us now and don't be afraid
Our party's starting to become a charade!
Lunatics everywhere will all act the same
And when the sideshow starts there's no one to blame
There's no one left, the town is having a raid
They all have joined us in our lunatic parade!

You wanna meet the clowns
When the circus comes to town?
Gather all around!
Come on to the next show
Parade along with us
You won't be forgotten!
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

#define  INF 100000000
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long long l,r,mid,a,flag;
long long ps;

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
long er=0;
for (int i=0;i<st.size();i++)
 if (st[i]!=st[0])er=1;
 if (er==0){cout<<1<<endl;return 0;}
 
long long mn,mx,ps;
mn=mx=ps=0;

for (int i=0;i<st.size();i++)
{

if (st[i]=='L')--ps;else ++ps;
if (i==st.size()-1&&(ps<mn||ps>mx)){cout<<1<<endl;return 0;}
mn=min(mn,ps);
mx=max(mx,ps);
}

if (st[st.size()-1]=='R')
for (int i=0;i<st.size();i++) 
 if (st[i]=='R')st[i]='L';else st[i]='R';

l=0;
r=1e7;
while (l<r)
{
 long mid=l+r+1;
 mid/=2;
 ps=0;
 a=0;
 flag=0;
 
 for (int i=0;i<st.size();i++)
 {
  if (st[i]=='L'){--ps;}
  else {if (mid==ps+1)continue;++ps;}
  if (i==st.size()-1&&ps==a-1)flag=1;
  a=min(a,ps);
 }
 if (flag)l=mid;
 else r=mid-1;
}

cout<<l<<endl;

cin.get();cin.get();
return 0;}