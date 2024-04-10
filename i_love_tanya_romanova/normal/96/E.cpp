/*
I never thought the taste of you
Would be the only thing to make me bleed
Why am I so alive while you lay still in the ground beneath me?

Fear of death, the dark inside have become your only children
Now they're in front of you, watching you
Lost screams, unholy dreams unrest
I laugh at your God as he's passing through

Slicing out your throat to warm my skin
Never thought it'd come to this
What the fuck I've gone wrong, no rest

Your children still call
Can't you hear them screaming out your name?
You've gone insane, they're in my head

They want you to die in front of me, die in front of me
Thinking why me, wishing this was all a dream
Insanity, reality, you're going to die in front of me

Pestilence is here, death awaits
Your body's not of Christ, it's my altar
Helpless and alone, violate
Enveloped in my sin, faceless canvas

Tearing at your flesh, bathed in blood
Violently regress, death's so endless
Brutal is the pain, anguish is the game
Broken and afraid, God can't help you now

You wish you were in hell
You wish you were in hell
You wish you were in hell

Ghostly figures are always standing still
Are they mocking me? What do they see?
I didn't want your death to end so fast
But once you start you cannot stop
I need it now to fucking last

Die in front of me, die in front of me
Thinking why me, wishing this was all a dream
Insanity, reality, you're going to die in front of me

Pestilence is here, death awaits
Your body's not of Christ, it's my altar
Brutal is the pain, anguish is the game
Broken and afraid, God can't help you now

You wish you were in hell
You wish you were in hell
You wish you were in hell
You wish you were in hell

I never thought the taste of you
Would be the only thing to make me bleed
All alone in my funeral home
Playing in blood there's just got to be
Something wrong with me

Draining veins, it's all the same
The torture in my head it won't stop
Until I am fucking dead

Pestilence is here, death awaits
Your body's not of Christ, it's my altar
Helpless and alone, violate
Enveloped in my sin, faceless canvas

Tearing at your flesh bathed in blood
Violently regress, death's so endless
Brutal is the pain, anguish is the game
Broken and afraid, God can't help you now

You wish you were in hell
You wish you were in hell
You wish you were in hell
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

long tests,k,dp[1050][1050][3],nend,nwas,luck[20000];
long pw[20000];
string st1,st2;

void add(long&a,long &b)
{
 a+=b;
 if (a>=bs)a-=bs;
}

bool check(string st)
{
 long l=-100000;
 for (int i=0;i<st.size();i++)
 {
  if (st[i]=='4'||st[i]=='7')
  {
   if (i-k<=l)return 1;
   l=i;
  }
 }
 return 0;
}

long solve(string st)
{
 long ans=0;
 
 if (check(st))++ans;
 long lnice=-1;
 long isgood=0;
 for (int i=0;i<st.size();i++)
 {
  for (int j=0;j+48<st[i];j++)
  {
   long tg=isgood;
   long tl=lnice;
   if (j==4||j==7)
   {
    if (lnice>=0&&lnice+k>=i)tg=1;
    tl=i;
   }
   
   if(i+1==st.size())
   {
    long one=1;
    if (tg)add(ans,one);
   }
   else
   if (tg==1)// evrtn ok
   {
    add(ans,pw[st.size()-i-1]);
   }
   else if (tl==-1||tl+k<=i)// in suf only
   {
    add(ans,luck[st.size()-i-1]);
   }
   else
   {
    add(ans,luck[st.size()-i-1]);
    long aps=k-(i-tl);
    if (aps>=(st.size()-i))aps=st.size()-i-1;
    //cout<<st.size()-i<<"   "<<aps<<endl;
    add(ans,dp[st.size()-i-1][st.size()-i-aps][0]);
   }
  }
  if (st[i]=='4'||st[i]=='7')
   if (lnice>=0&&lnice+k>=i)
    isgood=1;
  if (st[i]=='4'||st[i]=='7')
   lnice=i;
 } 
 
 return ans;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
cin>>k;
dp[0][0][0]=1;
for (int i=0;i<=1000;i++)
 for (int j=0;j<=i;j++)
  for (int was=0;was<=1;was++)
   for (int ad=0;ad<=9;ad++)
   {
    nend=j;
    nwas=was;
    if (ad==4||ad==7)nend=i+1;
    if (j>0&&nend==i+1&&nend-j<=k)nwas=1;
    add(dp[i+1][nend][nwas],dp[i][j][was]);
   }

for (int i=0;i<=1000;i++) //lsuf
 for (int j=0;j<=i;j++)
  add(luck[i],dp[i][j][1]);

for (int i=0;i<=1000;i++)// part sum
 for (int j=i;j>0;j--)
 add(dp[i][j][0],dp[i][j+1][0]);

pw[0]=1;
for (int i=1;i<=1000;i++)
 pw[i]=(pw[i-1]*1ll*10)%bs;

for (;tests;--tests)
{
 cin>>st1>>st2;
 long res=solve(st2);
// cout<<"^"<<res<<endl;
 res-=solve(st1);
 if (check(st1))++res;
 if (res>=bs)res-=bs;
 if (res<0)res+=bs;
 cout<<res<<endl;
}

cin.get();cin.get();
return 0;}