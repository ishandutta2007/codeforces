/*
I've never believed in miracles I rarely even cried
But you never know the day when things will change
You came to me and gave me back what I have left unpaid
And to see myself, it felt so very strange

The mirror in your eyes
(The mirror in your eyes)
Is tellin' me what I've become alive and that is why
The mirror never lies
(There's pain inside your eyes)
The mirror in your eyes, yeah

I never thought of consequences bringin' life to fall
Though I want to love instead I pull you down
How can I be this way when I don't feel like this at all
And you know how much I need to be around

The mirror in your eyes
(The mirror in your eyes)
Is tellin' me what I've become alive and that is why
The mirror never lies
(There's pain inside your eyes)
The mirror in your eyes, yeah

Painful I'm learnin'
In Hell I am churnin'
I see my reflection in you
A monster returnin'
A heart that's still burnin'
I see my reflection in you

Thankful I'm learnin'
The candles are burnin'
Don't know where I'm turnin'
The mirror is blurrin'
In Hell I am burnin', yeah

The mirror in your eyes
(The mirror in your eyes)
Is tellin' me what I've become alive and that is why
There's pain inside your eyes
(The mirror never lies)
The mirror in your eyes
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

long c[111111][200],b[111111][200],l,r,n,k,m;
long temp;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

c[0][0]=1;
for (int i=1;i<=100500;i++)
 for (int j=0;j<=100&&j<=i;j++)
 {
  if (j==0)c[i][j]=1;
  else c[i][j]=(c[i-1][j]+c[i-1][j-1])%bs;
 }

cin>>n>>m;
for (int i=1;i<=n;i++)
cin>>b[i][0];

for (int i=0;i<m;i++)
{
 cin>>l>>r>>k;
 b[l][k+1]++;
 b[l][k+1]%=bs;
 for (int j=1;j<=k+1;j++)
 {
  b[r+1][j]=(b[r+1][j]+bs-c[r-l+k-j+1][k-j+1])%bs;
 }
}
for (int i=101;i>=0;--i)
{
 temp=0;
 for (int j=1;j<=n;j++)
 {temp+=b[j][i+1];
 temp%=bs;
 b[j][i]+=temp;
 b[j][i]%=bs;
 }
}
for (int i=1;i<=n;i++)
{
 if (i-1)cout<<" ";
 cout<<b[i][0];
 }
 cout<<endl;

cin.get();cin.get();
return 0;}