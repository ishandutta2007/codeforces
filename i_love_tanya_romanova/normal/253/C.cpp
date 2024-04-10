/*
Death and destruction rule on this planet
you know life is valid for a limited time
You live with the idea to die
there's no fuckin' chance for mercy
Survive to die
Survive to die
Survive to die
You take advantage of every moment
'cause death hits without exception
There is no challenge 'cause we always loose
Why don't you stop livin??
Survive to die
Survive to die
Survive to die
No prospect of reprieve
when your time is over
Your destiny follows you like your shadow
Future plans and projects, just a waste of time
Our solution is to live day by day
Hazard seems to be mor fair this way.
Survive to die
Survive to die
Survive to die
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
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long long n,l[200000],c1,c2,r1,r2,ans,qmin;
long long suf[200000];
long long tans,qrow,qp,qpos;

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>l[i];

cin>>r1>>c1>>r2>>c2;

--c1;--c2;

ans=1000000000;
ans*=ans;

for (int trow=1;trow<=n;trow++)
{
    tans=0;
    qrow=r1;
    qp=c1;
    while (qrow>trow){--qrow;qp=min(qp,l[qrow]);++tans;}
    while (qrow<trow){++qrow;qp=min(qp,l[qrow]);++tans;}
    while (qrow<r2){++qrow;qp=min(qp,l[qrow]);++tans;}
    while (qrow>r2){--qrow;qp=min(qp,l[qrow]);++tans;}
    tans+=abs(qp-c2);
    ans=min(ans,tans);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}