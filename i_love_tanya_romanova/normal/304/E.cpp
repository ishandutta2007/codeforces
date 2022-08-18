/*
I put the finger on you, yeah
My hands all outta control
I can't stop it gettin' down on you
It's movin' of its own accord
I got fire in my finger tips
Radiate it all to you
I can't control it
Can't even hold it
It's knockin' on your door and you know what it's for
I put the finger right on you
I put the finger right on you
You put your finger on me too
And I put the finger, I put the finger, I put the finger
I put the finger

I got the finger on you for sure
It's the key to unlockin' your door
Don't you know
I broken thru' your security
My hands ain't tied no more, you better watch out
I can't control it
Can't even hold it
Sneakin' up for your pleasure
You can feel it on your ankle
Feel it on your knee
Feel it on your thigh
Can you feel me
I put the finger right on you
I put the finger right on you
You put your finger on me too
I put the finger, I put the finger, I put the finger
I put the finger on you

I can't control it
Can't even hold it
Sneakin' up for your pleasure
You can feel it on your ankle
Feel it on your knee
Feel it on your thigh
Can you feel me
Put it, right on you
Put it, right on you
I'll do it if you
Want me to
Come on put it
Come on put it
I put the finger on you, I put the finger on you, I put the finger on you
I put the finger on you, I put the finger on you, I put the finger on you

So close
I hit the spot
I put the finger
Right on
You
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,k,bd,s,ar[6000],ans,calc[1200000];
long lst[1200000];
long del;
long q;

void check(long mod)
{
     del=0;
     for (int i=1;i<=n;i++)
     {
         q=ar[i]%mod;
         if (lst[q]==mod)++del;
         else lst[q]=mod;
         if (del>k)break;
     }
     if (del<=k)ans=mod;
}

int main(){
//freopen("funny.in","r",stdin);
//freopen("funny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
if (k==0)bd=0;
if (k==1)bd=1;
if (k==2)bd=3;
if (k==3)bd=6;
if (k==4)bd=10;

for (int i=1;i<=n;i++)
cin>>ar[i];
sort(ar+1,ar+n+1);

for (int i=1;i<=n;i++)
for (int j=i+1;j<=n;j++)
calc[ar[j]-ar[i]]++;

ans=0;
for (int mod=1;mod<=1000001;mod++)
{
   s=0;
   if (ans>0)break;
   for (int p=mod;p<=1000001;p+=mod)
   {s+=calc[p];if (s>bd)break;}
   if (s<=bd)check(mod);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}