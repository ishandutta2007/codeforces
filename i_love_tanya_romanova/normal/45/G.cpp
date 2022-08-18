/*
The sun is sleeping quietly
Once upon a century
Wistful oceans calm and red
Ardent caresses laid to rest

For my dreams I hold my life
For wishes I behold my night
The truth at the end of time
Losing faith makes a crime

I wish for this night-time
to last for a lifetime
The darkness around me
Shores of a solar sea
Oh how I wish to go down with the sun
Sleeping
Weeping
With you

Sorrow has a human heart
From my god it will depart
I'd sail before a thousand moons
Never finding where to go

Two hundred twenty-two days of light
Will be desired by a night
A moment for the poet's play
Until there's nothing left to say

I wish for this night-time...

I wish for this night-time...
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
//#include <memory.h>

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
#define bs 1000000003

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,s,ans[200000];

bool prime(long x)
{
 if (x==1)return false;
 for (int i=2;i*i<=x;i++)
 if (x%i==0)return false;
 return true;
}

int main(){
//freopen("post.in","r",stdin);
//freopen("post.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
s=n*(n+1)/2;

if (s>5&s%2>0&&prime(s-2)==0)
{ans[3]=2;s-=3;}
for (int i=1;i<=n;i++)
{
    if (ans[i]==0&&prime(i)&&prime(s-i)){ans[i]=1;break;}
}
for (int i=1;i<=n;i++)
{
    if(i-1)cout<<" ";
    cout<<ans[i]+1;
}
cout<<endl;

cin.get();cin.get();
return 0;}