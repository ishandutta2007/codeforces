/*
If I keep holding out
Will the light shine through?
Under this broken roof
It's only rain that I feel
I've been wishin' out the days
Oh oh oh
Come back

I have been planning out
All that I'd say to you
Since you slipped away
Know that I still remain true
I've been wishin' out the days
Please say that if you hadn't have gone now
I wouldn't have lost you another way
From wherever you are
Oh oh oh oh
Come back

And these days, they linger on, yeah, yeah
And in the night, I've been waiting for
A real possibility that I may meet you in my dreams
I go to sleep

If I don't fall apart
Will my memory stay clear?
So you had to go
And I had to remain here
But the strangest thing to date
So far away and yet you feel so close
I'm not going to question it any other way
It must be an open door for you
To come back

And the days they linger on, yeah
Every night I'm waiting for
The real possibility that I may meet you in my dreams
Sometimes you're there and you're talking back to me
Come the morning I could swear you're next to me
And it's ok

It's ok, it's ok

I'll be here
Come back, come back
I'll be here
Come back, come back
I'll be here
Come back, come back
Oooooooo
Oooooooo
Oooooooo
Oooooooo
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000009
#define bsize 515
//#define N 120000

using namespace std;

long n,m,fib[1600000],s[1600000],tp;
vector<pair<long, long> >vec;
long start[1600000];
long a,b,toad[1600000],res;
long fsum[1600000];
long p1,p2;

void norm(long &x)
{
 while (x<0)x+=bs;
 while (x>=bs)x-=bs;
}

void doupd()
{
 vec.clear();
 for (int i=1;i<=n;i++)
 {
  toad[i]+=toad[i-1];
  norm(toad[i]);
  if (i>1)toad[i]+=toad[i-2];
  norm(toad[i]);
  start[i]+=toad[i];
  norm(start[i]);
 }
 for (int i=1;i<=n;i++)
  toad[i]=0;
 for (int i=1;i<=n;i++)
 {
  s[i]=s[i-1]+start[i];
  norm(s[i]);
 }
}

pair<long, long> inter(long l1,long r1,long l2,long r2)
{
 return make_pair(max(l1,l2),min(r1,r2));
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>start[i]; // t off
//start[i]=0;
 s[i]=s[i-1]+start[i];
 norm(s[i]);
}

fib[1]=1;
for (int i=2;i<=1500000;i++)
 fib[i]=(fib[i-1]+fib[i-2])%bs;

for (int i=1;i<=1500000;i++)
{
 fsum[i]=fsum[i-1]+fib[i];
 norm(fsum[i]);
}

for (int i=1;i<=m;i++)
{
 if (i%bsize==0)doupd();
 cin>>tp;
 //++tp;
 if (tp==1)// ad
 {
  cin>>a>>b;
  toad[a]+=1;
  norm(toad[a]);
  toad[b+1]-=fib[b-a+2];
  toad[b+2]-=fib[b-a+1];
  norm(toad[b+1]);
  norm(toad[b+2]);
  vec.push_back(make_pair(a,b));
 }
 else // get
 {
  pair<long, long> tp;
  cin>>a>>b;
  res=s[b]-s[a-1];// prev;
  norm(res);
  for (int j=0;j<vec.size();j++)
  {
   tp=inter(a,b,vec[j].first,vec[j].second);
   if (tp.first>tp.second)continue; // emp
   p1=tp.first-vec[j].first+1;
   p2=tp.second-vec[j].first+1;
   res+=fsum[p2]-fsum[p1-1];
   norm(res);
  }
  cout<<res<<endl;
 }
/* for (int j=1;j<=n;j++)
  cout<<toad[j]<<" ";
  cout<<endl;
*/ 
}

cin.get();cin.get();
return 0;}