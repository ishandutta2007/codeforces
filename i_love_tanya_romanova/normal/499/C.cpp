/*
Underneath the mask you've buried yourself into
It's coal-black
I am tired of the gulping that you do
Every day a new face
What if I unscrew
Your own identity
Wouldn's you guess there's nothing left of you?

The quicksand of life drags us
Down into the circle
One day we might not catch you

I feel sorry, for what you try to do
Breaking others down, to try and to pursue
Your own selfish interests
I am starting to get sick of you

Whatever happened ever since you left
You make yourself and me look like fools
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
#define bs 1000000009
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long x1,y1,x2,y2,n;
long long a,b,c,v1,v2;
long long ans;

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x1>>y1;
cin>>x2>>y2;
cin>>n;
for (int i=0;i<n;i++)
{
 cin>>a>>b>>c;
 v1=a*x1+b*y1+c;
 v2=a*x2+b*y2+c;
 if (v1>0&&v2<0)++ans;
 if (v1<0&&v2>0)++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}