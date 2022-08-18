/*
Waitin', watchin' the clock, it's four o'clock, it's got to stop
Tell him, take no more, she practices her speech
As he opens the door, she rolls over
Pretends to sleep as he looks her over

She lies and says she's in love with him, can't find a better man
She dreams in color, she dreams in red, can't find a better man
Can't find a better man, can't find a better man, oh

Talkin' to herself, "There's no one else who needs to know"
She tells herself, "Oh"
Memories back when she was bold and strong
And waiting for the world to come along

Swears she knew it, now, she swears he's gone
She lies and says she's in love with him, can't find a better man
She dreams in color, she dreams in red, can't find a better man

She lies and says she still loves him, can't find a better man
She dreams in color, she dreams in red, can't find a better man
Can't find a better man, can't find a better man, yeah

She loved him, yeah, she don't want to leave this way
She needs him, yeah that's why she'll be back again
Can't find a better man, can't find a better man
Can't find a better man, can't find a better man, oh, oh
Uh huh, uh huh, uh huh, uh huh, uh huh, oh
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
 
using namespace std;

long n,m,w[1<<10];
long fen[1<<10];
long b[1<<10];
vector<long> v;
vector<long> tv;
long ans;

bool cmp(long a,long b)
{
 long c1,c2;
 c1=c2=0;
 if (fen[a]>m&&fen[b]>m)return (a>b);
 if (fen[a]<fen[b])return true;
 return false;
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 cin>>w[i];

for (int i=1;i<=n;i++)
 fen[i]=1e9;

for (int i=1;i<=m;i++)
{
 cin>>b[i];
 if (fen[b[i]]>1e6)fen[b[i]]=i;
}

for (int i=1;i<=n;i++)
{
 v.push_back(i);
}
sort(v.begin(),v.end(),cmp);

/*for (int i=0;i<v.size();i++)
{
 cout<<" "<<v[i];
}
cout<<endl;
*/

ans=0;
for (int day=1;day<=m;day++)
{
 vector<long> tv;
 tv.push_back(b[day]);
 long f=0;
 for (int i=0;i<v.size();i++)
 {
  long id=v[i];
  if (id==b[day]){f=1;continue;}
  if (f==0)
   ans+=w[id];
  tv.push_back(id);
 }
/* for (int i=0;i<tv.size();i++)
 {
  cout<<tv[i]<<" ";
 }
 cout<<endl;
*/ v=tv;
}

cout<<ans<<endl;


cin.get();cin.get();
return 0;}