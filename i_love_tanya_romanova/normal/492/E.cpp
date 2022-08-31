/*
Brick walker won't you cease your time
Instead of ruin daily lives
Against the grain they stand
Against the grain they fall
Paint them a picture of their fate
Face their fearless looks so pale
It's so goddamn beautiful

If you are ready, put your hands on their fate
Your mind is clear and your speech is free
(Speech is free)
Your doors are shut and they won't see
(They won't see)
With your cynic presence they'll shiver
'Til the break of dawn

Come on, come on, come on
They're so expendable

We're all so fatal, we're all too able
(We'd like to have a break)
Say
We're all so tragic, illogical magic
(We'd like to turn the page)
Say

So, watch them cross the yard of time
Do not fail, don't cross that line
(Don't cross that line)
Inside, they will leave tonight
Vanish through the sky

We're all so fatal, we're all too able
(We'd like to have a break)
Say
We're all so tragic, illogical magic
(We'd like to turn the page)
Say

Don't throw the page
Don't throw it all away
Gotta turn the page
Just lead thy pain astray

We're all so fatal, we're all too able
(We'd like to have a break)
Say
We're all so tragic, illogical magic
(We'd like to turn the page)

Inside, they will leave tonight
Vanish through the sky
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,m,dx,dy,qx,qy,ps[1<<20];
long t,ans[1<<20];
long a,b;
long bst,bp;

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>dx>>dy;
qx=qy=0;
for (int i=0;i<n;i++)
{
 ps[qx]=qy;
 qy+=dy;
 qx+=dx;
 qx%=n;
 qy%=n;
}

for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 t=b-ps[a]+n;
 t%=n;
 ans[t]++;
}

bst=-1;

for (int i=0;i<n;i++)
 if (ans[i]>bst)bst=ans[i],bp=i;
/*for (int i=0;i<n;i++)
 cout<<ans[i]<<" ";
 cout<<endl;
 */
cout<<0<<" "<<bp<<endl;

cin.get();cin.get();
return 0;}