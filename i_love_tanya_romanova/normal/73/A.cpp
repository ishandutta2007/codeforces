/*
Never remorse, no kind of piety
There's no explanation but instinctive brutality

I think of those eyes always fixed on that instant
A constant fight with memory
Lights on, then off again

You wasted their souls, wasted innocent wishes
You wiped away joy and dignity
Where joy of life dies, where madness is leader
Where hope falls, there is where the sea ends

You stole their bodies made them like puppets for
A madness of a mad beast and I wonder how

Those people can stare at you, there's no forgiveness
For those human eyes with freak hearts
It will be revenge again

Dreams come true
As I look across the sea
As I walk across my life

Mother of emotions, life you gave the men the hope
The challenge of a fight for freedom in our eyes
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long cx,cy,cz,x,y,z,k;

long long g(long long a,long long b)
{
 if (a==b)return 1e18;
 return a;
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x>>y>>z>>k;

cx=cy=cz=1;

while (true)
{
 if (k==0)break;
 if (cx==x&&cy==y&&cz==z)break;
 --k;
 if (g(cx,x)<=g(cy,y)&&g(cx,x)<=g(cz,z))
 ++cx;
 else if (g(cy,y)<=g(cx,x)&&g(cy,y)<=g(cz,z))
 ++cy;
 else
 ++cz;
}

cout<<(cx)*(cy)*(cz)<<endl;

cin.get();cin.get();
return 0;}