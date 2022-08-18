/*
Oh, can't you tell me what makes me fell this way?
It's overwhelming, obscuring all my days.

Give me a reason to carry on for more.
The change of season, it undermines my core.
A constant darkness coating me,
I cannot see you, no more...

Excuse me for the things I've said,
if I could change it I'd be glad,
it is just, it drives me to desperation,
to desperation.

There's no solution, I'm heading for the end.
The consecution is lying in my hand.
A constant streaming, opening me.
I cannot feel you, no more...

Forgive me all the things I've made
for peace of mind, now it's too late,
it is just, it drives me to desperation.

Excuse me for the things I've said,
if I could change it I'll be glad,
it is just, it drives me to desperation,
to desperation.
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
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

string st1,st2;
long long n,m,sz1,sz2,ol,fc,ans;
long calc[1100000][30];

long long gcd(long long a,long long b)
{
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}

int main(){
//freopen("deny.in","r",stdin);
//freopen("deny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
cin>>st1;
cin>>st2;

sz1=st1.size();
sz2=st2.size();
ol=gcd(sz1,sz2);

for (int i=0;i<st2.size();i++)
{
 calc[i%ol][st2[i]-'a']++;   
}

fc=n/(sz2/ol);
//cout<<fc<<endl;
ans=n*sz1;

for (int i=0;i<st1.size();i++)
{
 ans-=1ll*fc*calc[i%ol][st1[i]-'a'];   
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}