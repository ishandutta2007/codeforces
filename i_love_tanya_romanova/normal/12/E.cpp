/*
The sullen man before me turns a head and demonstrates
The power of a weak mind can't conceal or captivate

It's lost in a bleak scope of fragmented ways
Eternal non-events occur throughout its poor days
You're lost forever unable to see yourself
The thoughts arising, there's
no disguising where you've been...

Reveal to me, your mind's identity

You'll pay, pay for the feelings that you feed me
Don't hold on to what you call a life...

Anger compels a force of weakness or fear
I'll promise no forgiveness for the rest of my years
A negative release, subliminal urge
Unwish declining, grey thoughts reviving all the way...

Your fallen prey, a loser pays

You'll pay for the feelings that you feed me
Don't hold on to what you call a life...
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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,ar[2000][2000];

int main(){
//freopen("scanner.in","r",stdin);
//freopen("scanner.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<=n;i++)
 for (int j=0;j<=n;j++)
  ar[i][j]=(i+j)%(n-1)+1;

for (int i=0;i<n;i++)
{
    ar[i][n-1]=ar[n-1][i]=ar[i][i];
    ar[i][i]=0;
}
for (int i=0;i<n;i++)
{
    for (int j=0;j<n;j++)
    {
        if (j)cout<<" ";
        cout<<ar[i][j];
    }
    cout<<endl;
}
cin.get();cin.get();
return 0;}