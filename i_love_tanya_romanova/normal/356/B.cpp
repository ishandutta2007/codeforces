/*
Some folks are born made to wave the flag
Ooh, they're red, white and blue
And when the band plays "Hail to the chief"
Ooh, they point the cannon at you, Lord
It ain't me, it ain't me, I ain't no senator's son, son
It ain't me, it ain't me; I ain't no fortunate one, no

Yeah!
Some folks are born silver spoon in hand
Lord, don't they help themselves, oh
But when the taxman comes to the door
Lord, the house looks like a rummage sale, yes

It ain't me, it ain't me, I ain't no millionaire's son, no
It ain't me, it ain't me; I ain't no fortunate one, no

Some folks inherit star spangled eyes
Ooh, they send you down to war, Lord
And when you ask them, "How much should we give?"
Ooh, they only answer More! more! more! yoh

It ain't me, it ain't me, I ain't no military son, son
It ain't me, it ain't me; I ain't no fortunate one, one

It ain't me, it ain't me, I ain't no fortunate one, no no no
It ain't me, it ain't me, I ain't no fortunate son, no no no
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