/*
You know my friend
I've been walking on a really strange path lately
I'm so glad you were not there
to see my fall, to see me passing on
My wound so deep
my veins opened wide
letting flow my distress
letting flow my requests
Listen my friend
as no one wanted to hear I'm telling you now
So weak was my hope
so cold the world around
so strong the calls
my pain invited echoes to my pain
Anguish
coiled in the gut like a starving worm
Fallen, between...
I slide down the hole at the center of my soul
I've given up, I've given up, larvae rots
for I let the angel rise...
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

long n,lwr,upr;
string st1,st;
long num;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
lwr=-2e9;
upr=2e9;
for (int i=1;i<=n;i++)
{
cin>>st;
cin>>num;
cin>>st1;

if (st1=="N")
{
 if (st[0]=='<')st[0]='>'; else st[0]='<';
 if (st.size()==1)st+="=";else st.erase(st.begin()+1);
}
if (st[1]=='='){if (st[0]=='<')++num;else--num;}
if (st[0]=='<'){upr=min(upr,num-1);}
if (st[0]=='>'){lwr=max(lwr,num+1);}
}

if (upr<lwr)cout<<"Impossible"<<endl;
else cout<<lwr<<endl;

cin.get();cin.get();
return 0;}