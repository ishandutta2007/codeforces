/*
I memorized all the words for you
But if you only knew how much that's just not like me
I wait up late every night just to hear your voice
But you don't know that's nothing like me

You know I wonder had you already figured out
All these things that I try to hide
All this time I've been hoping you don't find out
All these things that I hide on the inside

I can't be held responsible
This is all so new to me
Just when I think I'm invincible
You come and happen to me

I want to make sure everything is perfect for you
If you only knew that that's not like me to follow through
Maybe even give up on these dead end dreams just to be with you
But you don't know that's nothing like me

Hey, yeah, I wonder had you already figured out
All these things that I try to hide
All this time I've been hoping you don't find out
All these things that I hide on the inside

I can't be held responsible
This is all so new to me
Just when I think I'm invincible
You come and happen to me

Now I'm waking up, I've finally had enough
Of this wreck of a lifetime, I never thought I'd survive it
Now I'm taking back all I gave up for that
Leave my pain behind, wash these stains from my life

Just when I thought all was lost
You came and made it all okay

I can't be held responsible
This is all so new to me
Just when I think I'm invincible
You come and happen to me

I can't be held responsible
This is all so new to me
Just when I think I'm invincible
You come and happen to me

I memorized all the words for you
If you only knew how much that's just not like me
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

long n,a[1<<20],b[1<<20];
set<long> nf;
long snd;
long ans[1<<20];
long bc[1<<20];

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a[i]>>b[i];
 nf.insert(b[i]);
}
for (int i=1;i<=n;i++)
 bc[a[i]]=b[i];
 
for (int i=1;i<=n;i++)
{
 if (a[i]>0&&nf.find(a[i])==nf.end())
 {
  snd=i;
  ans[1]=a[i];
 }
 if (a[i]==0)
  ans[2]=b[i];
}

for (int i=1;i+2<=n;i++)
 ans[i+2]=bc[ans[i]];

for (int i=1;i<=n;i++)
{
 if (i>1)cout<<" ";
 cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}