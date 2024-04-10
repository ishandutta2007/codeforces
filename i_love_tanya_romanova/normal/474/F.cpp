/*
Cover me when I walk alone
Cover me when my stance it stumbles homes
Cover me, we'll trip on through the sands of time
Cover me cause I've been branded

I've lost my mind
Lost my mind
But you'll cover me
Won't you give me shelter from the storm?

And over me you fade into the night
And over me you melt into the light
And over me you will fear the things I need
And over me you will feel the hate I breed

You're under me and you will question my authority
You're under me and you will lose almost everything now
You're under me, you will feel the pain I wanna bring you
You're under me, you never change

You never change a fucking thing
Not a fucking thing
But you'll, you'll cover me
And give me shelter from the storm

Cover me, cover me
Won't you cover me, cover me?
Don't you cover me, cover me?
Give me shelter from the storm

Oh yeah, yeah, yeah, no, no, no
People push and shove on time, I give it to you
What I have is what is mine, I feel it for you
You've got to cover me, you've got to cover me

People take and people steal, I have it for you
What I have is what I fear, I fear it for you
You've got to cover me
'Cause I've been branded a broken man, broken man
But you'll cover me yeah, won't you?
Give me shelter from the storm

Cover me, cover me
Won't you cover me, cover me?
Don't you cover me, cover me?
Give me shelter from the storm
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
#define free adsgasdg

using namespace std;

long n,ar[1<<20],t[1<<20];
long temp;

long gcd(long a,long b)
{
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}

void build(long v,long tl,long tr)
{
 if (tl==tr){t[v]=ar[tl];return;}
 long tm=tl+tr;
 tm/=2;
 build(v*2,tl,tm);
 build(v*2+1,tm+1,tr);
 t[v]=gcd(t[v*2],t[v*2+1]);
}

vector <pair<long, long> > v;
long tests,l,r;
long a,b;

long get(long v,long tl,long tr,long l,long r)
{
 if (l>r)return 0;
 if (tl==l&&tr==r)return t[v];
 long tm=tl+tr;
 tm/=2;
 long a=get(v*2,tl,tm,l,min(r,tm));
 long b=get(v*2+1,tm+1,tr,max(l,tm+1),r);
 return gcd(a,b);
}

long solve(long a,long b)
{
 pair<long, long> tp=make_pair(a,b);
 return lower_bound(v.begin(),v.end(),tp)-v.begin();
}

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

build(1,1,n);

for (int i=1;i<=n;i++)
{
 v.push_back(make_pair(ar[i],i));
}

sort(v.begin(),v.end());

cin>>tests;
for (;tests;--tests)
{
 cin>>l>>r;
 temp=get(1,1,n,l,r);
 a=solve(temp,r+1);
 b=solve(temp,l);
 cout<<r-l+1-(a-b)<<endl;
}
cin.get();cin.get();
return 0;}