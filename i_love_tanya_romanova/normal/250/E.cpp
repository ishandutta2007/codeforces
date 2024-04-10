/*
One more nightmare
No place like home
You see a picture of angels
I see a nail in the wall

Make him over
No time to lose

And if you've heard this one before
Don't stop me
Don't stop me

We learn slowly
Evil's in the holy
Incidental
God hates heavy metal
So I know he must hate me

Lazy-crazy
Must be my name
Why are you running to nowhere
Why do you listen to noise

So if you've heard this all before
Please stop me
Please stop me

Live don't preach it
If you can't don't teach it
Accidental
God loves heavy metal
So I know he must want me

We learn slowly
Mind control is holy
Stir don't shake it
Move too fast you'll break it up
Incidental
God is heavy metal
So I know he must need me
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,m;
char ar[110][11000];
long long qi,qj,mx,mn,moves,iters;
long dir;

int main(){
//freopen("experimental.in","r",stdin);
//freopen("experimental.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=0;i<=n+1;i++)
for (int j=0;j<=m+1;j++)
ar[i][j]='#';

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
cin>>ar[i][j];

qi=1;
qj=1;
dir=1;
mx=mn=1;
while (true)
{
 ++iters;
 if (qi==n)break;
 if (iters>6000000)break;
// cout<<qi<<" "<<qj<<endl;
 //cin.get();
 if (ar[qi+1][qj]=='.'){++qi;moves++;mx=mn=qj;continue;}
 if (dir==1&&ar[qi][qj+1]=='+'){ar[qi][qj+1]='.';dir=3-dir;++moves;continue;}
 if (dir==2&&ar[qi][qj-1]=='+'){ar[qi][qj-1]='.';dir=3-dir;++moves;continue;}
 if (dir==1&&qj<mx){moves+=mx-qj;qj=mx;continue;}
 if (dir==2&&qj>mn){moves+=qj-mn;qj=mn;continue;}
 if (dir==1&&ar[qi][qj+1]=='#'){dir=3-dir;++moves;continue;}
 if (dir==2&&ar[qi][qj-1]=='#'){dir=3-dir;++moves;continue;}
 if (dir==1){++qj;++moves;mx=max(mx,qj);continue;}
 if (dir==2){--qj;++moves;mn=min(mn,qj);continue;}
}

if (iters>6000000)cout<<"Never"<<endl;
else
cout<<moves<<endl;

cin.get();cin.get();
return 0;}