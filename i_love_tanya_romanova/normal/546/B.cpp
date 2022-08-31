/*
I guess this time you're really leaving
I heard your suitcase say goodbye
And as my broken heart lies bleeding
You say true love is suicide

You say you've cried a thousand rivers
And now you're swimming for the shore
You left me drowning in my tears
And you won't save me anymore

Now I'm praying to God
You'll give me one more chance

I'll be there for you
These five words I swear to you
When you breathe I want to be the air for you
I'll be there for you

I'd live and I'd die for you
I'd steal the sun from the sky for you
Words can't say what a love can do
I'll be there for you

I know you know we've had some good times
Now they have their own hiding place
I can promise you tomorrow
But I can't buy back yesterday

Baby you know my hands are dirty
I wanted to be your valentine
I'll be the water if you get thirsty, baby
When you get drunk, I'll be the wine

I'll be there for you
These five words I swear to you
When you breathe I want to be the air for you
I'll be there for you

I'd live and I'd die for you
I'd steal the sun from the sky for you
Words can't say what a love can do
I'll be there for you

I wasn't there when you were happy
I wasn't there when you were down
I didn't mean to miss your birthday, baby
I wish I'd seen you blow those candles out

I'll be there for you
These five words I swear to you
When you breathe I want to be the air for you
I'll be there for you

I'd live and I'd die for you
I'd steal the sun from the sky for you
Words can't say what a love can do
I'll be there for you
*/
 
#pragma comment(linker, "/STACK:66777216")
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

using namespace std;

int n,q,ar[1<<20],ans;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    ar[q]++;
}
for (int i=1;i<=6000;i++)
{
    if (ar[i]>1){ans+=ar[i]-1;ar[i+1]+=ar[i]-1;ar[i]=1;}
}
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}