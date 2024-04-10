/*
Stalking down the enemy
These haunting memories
The evil men are killing blindly
Erased of human waste
It's frozen in their face
Traumatic minds enslaved
Screams that never reached my ears
Until the death redeems

Ambivalence
Lost salvation
Lunatic fringe
Incarceration
Freedom's slave
Subliminal deceit

Blood, blood on your lips
Measure my faith
Come on to die with me
Blood, blood on your lips
You're falling down
Into a pitiless sleep

My systematic procedure
Within my concious mind
Can't wash away the crimson stains
No tears that save my eyes
Passion for the flesh
I know that never dies
The devils that surround me
Never asking why

Imagination
Victimized
Obliteration
Justified
All I see
The multitudes of death

Blood, blood on your lips
Measure my faith
Come on to die with me
Blood, blood on your lips
You're falling down
Into a pitiless sleep

Blood - Die with me
Blood - On your lips

I am the chosen one
Your dad and your lovely mum
I'll offer my secrets for you
My physical lust

This is for me and you
Searching to find the truth
No reason for you to cry
We'll find the paradise

Blood on your lips

Ambivalence
Lost salvation
Lunatic fringe
Incarceration
Freedom's slave
Subliminal deceit

Blood, blood on your lips
Measure my faith
Come on to die with me
Blood, blood on your lips
You're falling down
Into a pitiless sleep

Blood - on your lips
Blood - Die with me
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