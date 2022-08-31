/*
I feel like there is no need for conversation
Some questions are better left without a reason
And I would rather reveal myself than my situation
Now and then I consider my hesitation

The more the light shines through me
I pretend to close my eyes
The more the dark consumes me
I pretend I'm burning, burning bright

I wonder if the things I did were just to be different
To spare myself of the constant shame of my existence
And I would surely redeem myself in my desperation
Here and now I'll express my situation

The more the light shines through me
I pretend to close my eyes
The more the dark consumes me
I pretend I'm burning bright
The more the light shines through me
I pretend to close my eyes
The more the dark consumes me
I pretend I'm burning

There's nothing ever wrong, but nothing's ever right
Such a cruel contradiction
I know I crossed the line, it's not easy to define
I'm born to indecision
There's always something new, some path I'm supposed to choose
With no particular rhyme or reason

The more the light shines through me
I pretend to close my eyes
The more the dark consumes me
I pretend I'm burning bright
The more the light shines through me
I pretend to close my eyes
The more the dark consumes me
I pretend I'm burning

I feel like there is no need for conversation
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
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long n,ar1[1<<20],ar2[1<<20],ar3[1<<20],ans1,ans2;

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>ar1[i];
 
}
for (int i=0;i<n-1;i++)
{
 cin>>ar2[i];
}
for (int i=0;i<n-2;i++)
 cin>>ar3[i];
sort(ar1,ar1+n);
sort(ar2,ar2+n-1);
sort(ar3,ar3+n-2);
for (int i=0;i<n;i++)
 if (i==n-1||ar1[i]!=ar2[i])
  {ans1=ar1[i];
  break;}
for (int i=0;i<n-1;i++)
 if (i==n-2||ar2[i]!=ar3[i])
  {ans2=ar2[i];
  break;}

cout<<ans1<<endl;
cout<<ans2<<endl;
    
cin.get();cin.get();
return 0;}