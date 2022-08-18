/*
We will never sleep, 'cause sleep is for the weak
And we will never rest, 'til we're all fucking dead
We will never sleep, 'cause sleep is for the weak
And we will never rest, 'til we're all fucking dead

We will never sleep, 'cause sleep is for the weak
And we will never rest, 'til we're all fucking dead
We will never sleep, 'cause sleep is for the weak
And we will never rest, 'til we're all fucking...

We will never sleep, 'cause sleep is for the weak
And we will never rest, 'til we're all fucking dead
We will never sleep, 'cause sleep is for the weak
And we will never rest, 'til we're all fucking dead

I refuse! I refuse!
I refuse to close my eyes

I have loved, and I have lost
I have turned, and I have tossed
I have listened, and I have watched
I've gave into this for long enough
I have lost, and I have loved
Sleep has stolen far too much
So don't close your eyes, not just yet
Sleep is just a cousin of death

I've said it before, and I'll say it again
If you think you're alive then you're better off dead
I've said it before, and I'll say it again
If you think you're alive then you're better off...
I've said it before, and I'll say it again
If you think you're alive then you're better off dead
I've said it before, and I'll say it again
If you think you're alive then you're better off dead

I have loved, and I have lost
I have turned, and I have tossed
I have listened, and I have watched
I've gave into this for long enough
I have lost, and I have loved
Sleep has stolen far too much
So don't close your eyes, not just yet
Sleep is just a cousin of death

So throw your diamonds in the sky, we'll stay gold forever
So throw your diamonds in the sky, we'll stay gold forever

I can promise you one thing: death will take us all
I can promise you one thing: you will die alone

We're all going to Hell, we may as well go out in style
Death is a promise, and your life is a fucking lie

We will never sleep, 'cause sleep is for the weak
And we will never rest, 'til we're all fucking dead
We will never sleep, 'cause sleep is for the weak
And we will never rest, 'til we're all fucking dead

I refuse! I refuse!
I refuse to close my eyes
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

long long n,h1,a1,x1,y1,x2,y2,h2,a2;
long long found;
long long m;
long long move1[1<<20],move2[1<<20];
long long mh1,mh2;
long long val1[1<<22],val2[1<<22],en1[1<<20],en2[1<<20],en3[1<<20],en4[1<<20],c1,c2;
long long cnt;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;

found =-1;

for (int i=0;i<m;i++)
 move1[i]=(1ll*x1*i+y1)%m,
 move2[i]=(1ll*x2*i+y2)%m;

mh1=h1;
mh2=h2;

for (int i=0;i<=10000000;i++)
{
    if (h1==a1&&h2==a2)
    {
        found=i;break;
    }
    h1=1ll*x1*h1+y1;
    h2=1ll*x2*h2+y2;
    h1%=m;
    h2%=m;
}

if (found!=-1)
{
    cout<<found<<endl;
    return 0;
}
 
 h1=mh1;
 h2=mh2;
 
 found =1e15;
 
 val1[0]=h1;
 val2[0]=h2;
 
for (int i=1;i<=3000000;i++)
{
    h1=1ll*x1*h1+y1;
    h2=1ll*x2*h2+y2;
    h1%=m;
    h2%=m;
    if (en1[h1]==0)en1[h1]=i;
    else if (en2[h1]==0)en2[h1]=i;
    if (en3[h2]==0)en3[h2]=i;
    else if (en4[h2]==0)en4[h2]=i;
    val1[i]=h1;
    val2[i]=h2;
}

if (en2[a1]==0||en4[a2]==0){cout<<-1<<endl;return 0;}

c1=c2=0;
for (int i=0;i<m;i++)
 if (en1[i]>0&&en2[i]>0)
  c1=en2[i]-en1[i];
for (int i=0;i<m;i++)
 if (en3[i]>0&&en4[i]>0)
  c2=en4[i]-en3[i];

for (int iter=0;iter<=2000000;iter++)
{
    cnt=1ll*iter*c1+en1[a1];
    cnt-=en3[a2];
    if (cnt%c2==0&&cnt>=0){found=min(found,1ll*iter*c1+en1[a1]);//cout<<cnt<<"%"<<c2<<endl;
    }
}

//cout<<c1<<"  "<<c2<<endl;
for (int iter=0;iter<=2000000;iter++)
{
    cnt=1ll*iter*c2+en3[a2];
    cnt-=en1[a1];
    if (cnt%c1==0&&cnt>=0){found=min(found,1ll*iter*c2+en3[a2]);//cout<<cnt<<" "<<c1<<endl;
    }
}
if (found>1e14)cout<<-1<<endl;
else cout<<found<<endl;

//cin.get();cin.get();
return 0;}