/*
In the gloom the gathering storm abates
In the ships gimlet eyes await
The call to arms to hammer at the gates
To blow them wide throw evil to its fate

All summers long the drills to build the machine
To turn man from flesh and blood to steel
From paper soldiers to bodies on the beach
From summer sends to Armageddon's reach

Overlord your master not your god
The enemy coast dawning grey with scud
These wretched souls puking shaking fear
To take a bullet for those who send them here

The world's all right the cliffs erupt in flame
No escape remorseless shrapnel rains
Drowning men no chance for a warrior's fate
A choking death enter hell's gates

Sliding we go only fear on our side
To the edge of the wire
And we rush with the tide
Oh the water is red
With the blood of the dead
But I'm still alive pray to God I survive

How long on this longest day
'Till we finally make it through
How long on this longest day
'Till we finally make it through

The rising dead faces bloated torn
They are relieved the living wait their turn
Your number's up the bullet's got your name
You still go on to hell and back again

Valhalla waits Valkyries rise and fall
The warrior tombs lie open for us all
A ghostly hand reaches through the wall
Blood and sand we will prevail

Sliding we go only fear on our side
To the edge of the wire
And we rush with the tide
Oh the water is red
With the blood of the dead
But I'm still alive pray to God I survive

How long on this longest day
'Till we finally make it through
How long on this longest day
'Till we finally make it through

How long on this longest day
'Till we finally make it through
How long on this longest day
'Till we finally make it through
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
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long n,lst[200000],a,b,ans;
long gb;

void check(long x)
{
 if (lst[x]<b)++ans;
 lst[x]=gb;
}

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int j=1;j<=100000;j++)
lst[j]=-1;

for (int i=1;i<=n;i++)
{
    gb=i;
 cin>>a>>b;b=i-b;
 ans=0;   
 for (int j=1;j*j<=a;j++)
 {
     if (a%j==0){check(j);if (a/j!=j)check(a/j);}
 }
 cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}