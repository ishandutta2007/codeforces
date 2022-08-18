/*
In my hour of need
Ha you're not there
And though I reached out for you
Wouldn't lend a hand

Through the darkest hour
Grace did not shine on me
It feels so cold, very cold
No one cares for me

Did you ever think I get lonely
Did you ever think that I needed love
Did you ever think to stop thinking
You're the only one that I'm thinking of

You'll never know how hard I tried
To find my space and satisfy you too

Things will be better when I'm dead and gone
Don't try to understand, knowing you I'm probably wrong

But oh how I lived my life for you
Still you'd turn away
Now as I die for you
My flesh still crawls as I breathe your name
All these years I thought I was wrong
Now I know it was you
Raise your head raise your face your eyes
Tell me who you think you are, who ?

I walk, I walk alone
Into the promised land
There's a better place for me
But it's far, far away
Everlasting life for me
In a perfect world
But I gotta die first
Please God send me on my way

Time has a way of taking time
Loneliness is not only felt by fools
Alone I call to ease the pain
Yearning to be held by you, alone, so alone, I'm lost
Consumed by the pain
The pain, the pain, the pain

Won't you hold me again
You just laughed, ha, ha, bitch
My whole life is work built on the past
But the time has come when all things shall pass
This good thing passed away

In my darkest hour
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
 
#define  INF 100000000
#define eps 1e-11
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

long long temp,num[200000],
n,m,k,ar[200000],l[200000],r[200000],d[200000];
long long a,b,op[200000],op1[200000];

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
cin>>ar[i];

for (int i=1;i<=m;i++)
cin>>l[i]>>r[i]>>d[i];

for (int i=1;i<=k;i++)
{
    cin>>a>>b;
    op[a]++;
    op[b+1]--;
}

for (int i=1;i<=m;i++)
{
    temp+=op[i];
    num[i]=temp;
}

for (int i=1;i<=m;i++)
{
    op1[l[i]]+=d[i]*num[i];
    op1[r[i]+1]-=d[i]*num[i];
}

temp=0;

for (int i=1;i<=n;i++)
{
    temp+=op1[i];
    ar[i]+=temp;
}

for (int i=1;i<=n;i++)
{if (i>1)cout<<" ";
cout<<ar[i];}
cout<<endl;

cin.get();cin.get();
return 0;}