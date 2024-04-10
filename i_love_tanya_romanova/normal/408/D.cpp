/*
I'm reaching out to find a reason
To find an answer and relief
I see a world so strange and cold
I see a world of rules and thieves

The day you're born you're under pressure
Your life is well prepared, my friend
They surely teach you what to think
How to behave until the end

All I ever wanted was a little piece of life
In a world where I decide things on my own
All I ever needed was a little piece of hope
And then things are gonna turn the other way

I'm living in a world of fantasy
Reality ain't good enough for me
And all that I can feel is nothing but sobriety

I'm living in a world of fantasy
Reality ain't meant or made for me
All that I see is so unreal

And once you're old enough they teach you
Not to be wishful, not to care
About the plan that's been already
Made for you by other hands

But when you fail, there's no one out there
To take your hand to catch your tears
The whole construction we have built
Leaves no such room for blinding fears

All I ever wanted was a little piece of life
In a world where I decide things on my own
All I ever needed was a little piece of hope
And then things are gonna turn the other way

I'm living in a world of fantasy
Reality ain't good enough for me
And all that I can feel is nothing but sobriety

I'm living in a world of fantasy
Reality ain't meant or made for me
All that I see is so unreal

I wonder, I wonder if I can handle it all
I wonder, I wonder if I can carry
The weight of the world

I'm living in a world of fantasy
I'm living in a world of fantasy
Reality ain't good enough for me
And all that I can feel is nothing but sobriety

I'm living in a world of fantasy
Reality ain't meant or made for me
All that I see is so unreal

I'm living in a world of fantasy
Reality ain't good enough for me
And all that I can feel is nothing but sobriety

I'm living in a world of fantasy
Reality ain't meant or made for me
All that I see is so unreal



Read more: Helloween - World Of Fantasy Lyrics | MetroLyrics 
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

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

long long n,p[200000],tosolve[20000];
long long moves[20000];

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>p[i];
tosolve[1]=2;
moves[1]=2;
for (int i=2;i<=n;i++)
{
 for (int j=p[i];j<i;j++)
 tosolve[i]+=tosolve[j];
 tosolve[i]+=2;
 tosolve[i]%=bs;
 moves[i]=moves[i-1]+tosolve[i];
 moves[i]%=bs;
}

cout<<moves[n]<<endl;

cin.get();cin.get();
return 0;}