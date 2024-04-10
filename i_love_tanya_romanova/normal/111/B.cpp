/*
I can't be compromising in my thoughts no more
I can't prevent the times my anger fills my heart
I can't be sympathizing with a new lost cause
I feel I've lost my patience with the world and all

And all the politicians and their hollow promises
And all the lies, deceit and shame that goes with it
The working man pays everything for their mistakes
And with his life too if there was to be a war

[Chorus:]
So we can only get one chance, can we take it?
And we only got one life, can't exchange it
Can we hold on to what we have, don't replace it
The age of innocence is fading like an old dream

A life of petty crime gets punished with a holiday
The victims' mind are scarred for life most everyday
Assailants know just how much further they can go
They know the laws are soft, conviction chances low

[Chorus]

You can't protect yourselves even in your own home
For fear of vigilante cries, the victims wipe their eyes
So now the criminal they launch right in our face
Judical system lets them do it, a disgrace

Despondent public worries, where it will all end?
We can't protect ourselves, our kids from the crime trend
We cannot even warn each other of evil in our midst
They have more rights than us, you cannot call that just

[Chorus]
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