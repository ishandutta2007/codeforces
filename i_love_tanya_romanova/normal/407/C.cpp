/*
I don't wanna leave this world behind
Was the only thing I had in mind, yeah
Now you've sent the angels back
I need them here on earth
'Cause eternity can be a long, long time
Don't turn your back on me, don't take away my choice
'Cause reality is lyin' to my mind, so now

I wanna leave it all behind
I'll leave it all behind
I need a window out of time
Leave it all behind
Ooh

Tell me 'bout the secrets of my life
What is it that makes me feel this way? Yeah
I can feel my energy, it's turned against myself
Like a downwards spiral heading straight to Hell
Maybe I could let it be and leave it all undone
'Cause I'm stumbling and it's time to say goodbye, goodbye

I wanna leave it all behind
I''ll leave it all behind
I need a window out of time
leave it all behind, yeah
I'll leave it, leave it, leave it, leave it, leave it, leave it

I can feel my energy, it's turned against myself
Like a downwards spiral heading straight to hell, to Hell
Don't turn your back on me, don't take away my choice
'Cause I'm stumbling and it's time to say goodbye, goodbye

I wanna leave it all behind
I'll leave it all behind
I need a window out of time
Leave it all behind, daa
Aah, leave all behind
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