/*
Now there is no end
The wheel will turn, my friend

I'm in flames
Cause I have touched the light
It pulls me son
we shall be one
Forevermore
That's all I want
It's all I need
Everything is fixed
There's no chance
There's no choice

It's calling me
"Saidin"
So precious and sweet
My mind keeps fading away

It's scratching deeper
My sole reliever
How can I find you now?

Passing through the flames
I see
How terror will rise
It soon will be over
Oh Father of lies
Like foul winds at twilight
It's coming over me
What was and what will be?
What is?
I don't know

Driving me insane
Just feel the heat
Madness creeps in
I'll tear it down

There's no end
Wheel of time
It keeps on spinning
There's no beginning
Turn the wheel of time
There's no beginning
Just keep on spinning

Light - it binds me
Light - it blinds me
Light - it finds me
Light denies me now

I creep along
So desperate and tired
Let me ask you
Why?
I am what I am
Prophecies I am the chosen
"Taveren"
The flame will grow
Feel the heat
I'll keep on breathing
After all there's no tomorrow

Wheel of time
Save my soul, find a way
And if I fail, will it all be over
Oh wheel of time

The vision
So fleeting and vague
Once again I will bring down the mountain
One last glimpse
It is constantly slipping away

The young man said
"I will never give up"
The inner war
I can hold against it
My mind, my mind
My mind's in darkness

The young man says
"I will never give in"
The prophecy Behold It's true
I conquer the flame
To release the insane
I'm crying
I cannot erase
I'm the dragon reborn
and in madness
I soon shall prevail
Twice I'll be marked and
Twice I shall live
The heron sets my path
And name me true
Twice I'll be marked and
Twice I shall die
My memory's gone
But twice I pay the price

wheel of time
Save my soul
find a way
May it be as the pattern has chosen
Oh, wheel of time
Turn the wheel of time
It keeps on spinning
There's no beginning
There's no end, wheel of time
There's no beginning
Just keep no spinning

Shine on
Embrace and deny me
Turn on, wheel of time
Shine on
You've burnt, now guide me
Weave on, wheel of time
Oh wheel of time
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,ar[10000],nuls,sum,rdown,rup,bans,ts;
double temp;

int main(){
//freopen("firesafe.in","r",stdin);
//freopen("firesafe.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n*2;i++)
{cin>>temp;ar[i]=temp*1000+1e-3;if (ar[i]%1000==0)nuls++;sum+=ar[i];}

bans=1000000000;

for (int ndown=0;ndown<=nuls;++ndown)
{
    if (ndown>n)continue;
    rdown=n-ndown;
    rup=n-(nuls-ndown);
    if(rup>n)continue;
    if (rup<0)continue;
    ts=0;
    for (int i=1;i<=n*2;i++)
    if (ar[i]%1000==0)ts+=ar[i];
    else if (rdown>0){ts+=(ar[i]-ar[i]%1000);--rdown;}
    else if (rup>0){ts+=ar[i]-ar[i]%1000+1000;--rup;}
    if (abs(ts-sum)<bans)
    bans=abs(ts-sum);
}

cout<<bans/1000<<".";
bans%=1000;
cout<<bans/100;
bans%=100;
cout<<bans/10;
cout<<bans%10<<endl;
//bans%1000<<endl;
cin.get();cin.get();
return 0;}