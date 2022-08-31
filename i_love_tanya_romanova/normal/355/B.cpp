/*
Life it seems, will fade away
Drifting further every day
Getting lost within myself
Nothing matters no one else
I have lost the will to live
Simply nothing more to give
There is nothing more for me
Need the end to set me free

Things are not what they used to be
Missing one inside of me
Deathly lost, this can't be real
Cannot stand this hell I feel
Emptiness is filing me
To the point of agony
Growing darkness taking dawn
I was me, but now He's gone

No one but me can save myself, but it's too late
Now I can't think, think why I should even try
Yesterday seems as though it never existed
Death Greets me warm, now I will just say good-bye
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long c1,c2,c3,c4,ans,n,m,ts,ar1[200000],ar2[20000];
long fl1,fl2;

int main(){
//freopen("deny.in","r",stdin);
//freopen("deny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>c1>>c2>>c3>>c4;

ans=c4;
ans=min(ans,c3*2);
cin>>n>>m;
for (int i=1;i<=n;i++)
cin>>ar1[i];
for (int i=1;i<=m;i++)
cin>>ar2[i];

fl1=fl2=0;

for (int i=1;i<=n;i++)
fl1+=ar1[i];
for (int i=1;i<=m;i++)
fl2+=ar2[i];

if (fl1==0&&fl2==0)
ans=0;
if (fl1==0)ans=min(ans,c3);
if (fl2==0)ans=min(ans,c3);

ts=0;
for (int i=1;i<=n;i++)
{
    ts+=min(c2,c1*ar1[i]);
}
ans=min(ans,ts+c3);

long ts1=ts;
ts=0;
for (int i=1;i<=m;i++)
ts+=min(c2,c1*ar2[i]);
ans=min(ans,ts+ts1);
ans=min(ans,c3+ts);

cout<<ans<<endl;
cin.get();cin.get();
return 0;}