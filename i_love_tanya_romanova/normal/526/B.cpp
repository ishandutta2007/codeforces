/*
Days at a time pass
In the dead of the night is when you come to me
You've got so much to say
Just spread your wings and ride
On the electric universe
Behind your computer
What do you picture when you read my
Words and thoughts and dreams?
Do they all come alive and breathe?
It's no wonder
This is a brand new world we're on
I'd really like to meet you somewhere along

The way you come to me is such a mistery
I just reach out and connect
A thousand miles from me and yet it's all right here
It's electric on a silver thread
I never see your face you're such a mystery
Where you are I can only guess
Addictive screens
I just cannot turn away

Where are you anyway?
Those things you say seem so damn far from real
But I can tell you this
I have seen things for myself that just don't seem right
I have always been an honest man
I believed that the system
Worked for
You and for
Me but - no
You say it's just a show
And we've all been way too busy
Or too spoiled to even care who's got the wheel

I used to look behind the lies
Use to look for sunny skies
I learned so much since I've been
Hacking their computer systems
The truth had knocked me to the floor
That a boy now out the door
A little power and I'm
On my way to logging on the world

The way you come to me is such a mistery
I just reach out and connect
A thousand miles from me and yet it's all right here
It's electric on a endless thread
I never see your face you're such a mystery
And your touch I can only guess
I lay here dreaming
We're so gone away

The way you come to me is such a mystery
I just reach out and connect
A thousand miles from me and yet it's all right here
Just electric on a silver web
Ane every night you're here you are my mystery
And where you are I can only guess
Morning's rising
And it's dawn again
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

using namespace std;

long n,cost[1<<20],l,r,mx,ans,sub[1<<20];

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=2;i<=(1<<n)*2-1;i++)
{
 cin>>cost[i];
}

mx=0;
for (int i=(1<<n);i;i--)
{
 l=cost[i*2]+sub[i*2];
 r=cost[i*2+1]+sub[i*2+1];
 ans+=abs(l-r);
 sub[i]=max(l,r);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}