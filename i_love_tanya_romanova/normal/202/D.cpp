/*
Rotten psyche, what I have done?
What I can do now it's time
Tomorrow comes, summer again
Butcher in me, kills for fun

How can I be the bad part of me
What can I do to get free?
Holding an instrument to satisfy his lust,
I'm innocent, it kills me

Confused mind
Confused mind

He commits suicide break his mind
When he dies, my life is damned sure
A mind confused I feel so slow
Cause that's the only thing I can do

I'm taking the knife to finish my life
But this strange feeling comes up again
This evil lust takes over me
The butcher, the winner again

Confused mind
Confused mind

Through the backstreet of the town
His steps are clanging
Now he's only an old imagine
In his hand a blade of solid steel
Now its the time you've got it to feel
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long long n,m,ar[1050][1050],rs[1050],cs[1050];
long long bst,bp;
long long temp,ans1,ans2;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  cin>>ar[i][j];
  rs[i]+=ar[i][j];
  cs[j]+=ar[i][j];
 }

bst=1e18;
bp=0;

for (int i=0;i<=n*4;i+=4)
{
 temp=0;
 for (int j=1;j<=n;j++)
 {
  temp+=rs[j]*1ll*(i-j*4+2)*(i-j*4+2);
 }
 if (temp<bst)
 {
  bst=temp;
  bp=i/4;
 }
}

ans1=bst;
ans2=bp;

bst=1e18;
bp=0;

for (int i=0;i<=m*4;i+=4)
{
 temp=0;
 for (int j=1;j<=m;j++)
 {
  temp+=cs[j]*1ll*(i-j*4+2)*(i-j*4+2);
 }
 if (temp<bst)
 {
  bst=temp;
  bp=i/4;
 }
}

cout<<ans1+bst<<endl;
cout<<ans2<<" "<<bp<<endl;

cin.get();cin.get();
return 0;}