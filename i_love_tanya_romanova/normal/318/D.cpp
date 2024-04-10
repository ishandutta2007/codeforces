/*
You see life through distorted eyes
You know you have to learn
The execution of your mind
You really had to turn
The race is run the book is read
The end begins to show
The truth is out, the lies are old
But you don't want to know

Nobody will ever let you know
When you ask the reason why
They just tell you that you're on your own
Fill your head all full of lies

The people who have crippled you
You want to see them burn
The gates of life have closed on you
And now there's just no return
You're wishing that the hand of doom
Could take your mind away
And you don't care if you don't see again
The light of day

Nobody will ever let you know
When you ask the reasons why
They just tell you that you're on your own
Fill your head all full of lies

Where can you run to
What more can you do
No more tomorrow
Life is killing you
Dreams turn to nightmares
Heaven turns to hell
Burned out confusion
Nothing more to tell

Everything around you
What's it coming to
God knows as your dog knows
Bog blast all of you
Sabbath bloody sabbath
Nothing more to do
Living just for dying
Dying just for you
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3

using namespace std;

long n,calc,t,m,a,b;
long ar[2][160][160];
long liter;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>t;
long shift=70;

ar[1][shift][shift]=n;
liter=1;
long minn=shift;
long maxx=shift;
long miter=0;
long chan=0;
long nextt,cur;

for (int iter=1;iter<=30000;iter++)
{
    nextt=(iter&1);
    nextt=1-nextt;
    cur=1-nextt;
    chan=0;
    
 for (int i=minn;i<=maxx;i++)
 for (int j=minn;j<=maxx;j++)
 ar[nextt][i][j]=0;
 
 
 for (int i=minn;i<=maxx;i++)
 for (int j=minn;j<=maxx;j++)
 if (ar[cur][i][j]>=4)
 {
                         chan=1;
              
  ar[cur][i][j]-=4;           
  ar[nextt][i-1][j]++;
  ar[nextt][i][j-1]++;
  ar[nextt][i][j+1]++;
  ar[nextt][i+1][j]++;
  if (i==minn)--minn;
  if (i==maxx)++maxx;
 }
 for (int i=minn;i<=maxx;i++)
 for (int j=minn;j<=maxx;j++)
 ar[nextt][i][j]+=ar[cur][i][j];
 liter=iter+1;
 if (chan==0)break;else miter++;
}

for (int i=1;i<=t;i++)
{
    cin>>a>>b;
  // a=1;b=1;
    a+=shift;
    b+=shift;
    if (a>=1&&a<=2*shift&&b>=1&&b<=2*shift)
    cout<<ar[liter&1][a][b]<<endl;
    else cout<<0<<endl;
}
cin.get();cin.get();
return 0;}