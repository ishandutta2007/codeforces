/*
How much can we take before we care to settle?
Thought we were set for a perfect scene
Everyone is waiting for a failure
Something I can't please and justify
The void within my eyes
Everyone is waiting for something they cannot have

Why don't you drop your guard
I'm on my knees
You got the mindset of a killer
And it will not take you far
If I had the answer would that make you stay?
This is the time and place it is your moment of fate

If this would be your last breath
Would it change a thing?
Dive head first into the fire

If you just let me I'll find a way
To ease your mind and for you to stay
And I will untie all the ropes
It's hard for me but believe me, I'm trying

What are you longing for?
What are you longing for?
What are you longing for?

If I had the answer
Would that make you stay
This is the time and place
You are waiting for something you cannot have

If this would be your last breath
Would it change a thing?
Dive head first into the fire

If you just let me I'll find a way
To ease your mind and for you to stay
And I will untie all the ropes
It's hard for me

If you just let me I'll find a way
To ease your mind and for you to stay
And I will untie all the ropes
It's hard for me, believe me, I'm trying
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 300
#define clone agsdahfaassdg

using namespace std;

long long n,ar[600][600],k,a,b,c,answ;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
cin>>ar[i][j];
cin>>k;

for (int i=1;i<=k;i++)
{
    cin>>a>>b>>c;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    {
        ar[i][j]=min(ar[i][j],ar[i][a]+ar[b][j]+c);
        ar[i][j]=min(ar[i][j],ar[i][b]+ar[a][j]+c);
    }
    answ=0;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    answ+=ar[i][j];
    if (i>1)cout<<" ";cout<<answ/2;
}
cout<<endl;
cin.get();cin.get();
return 0;}