/*
I don't care if my lady's gone
as long as you give me just what I want.
I've been losin' my direction,
got to find a new connection.

You have wasted the love I tasted,
now I'm really gettin' hungry more and more.
Been a long time, had a bad sign.
Tell me what am I fighting for?

Let me know you feel it,
you know I really need it.
Keep on pushin' for more,
lay down, stay down.
I got something to find,
there's one thing I really need.
I'm gonna tell you right now,
lay down, stay down.

Lookin' for trouble, I guess that's right.
When I was young I was taught to fight.
It's been long gone since I had known,
now I'm headin' for some more.

Let me know you feel it,
you know I really need it.
Keep on pushin' for more,
Lay down, stay down.
I got something to find,
there's one thing I really need.
I'm gonna tell you right now,
lay down, stay down.

Let me know you feel it,
you know I really need it.
Keep on pushin' for more,
lay down, stay down.
I got something to find,
there's one thing I really need.
I'm gonna tell you right now,
lay down, stay down.
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
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long long n,q,a;
vector<long long> v,vec1;
long long p,b,qdeg,answ;
long long d[500000];

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>q;
for (int i=1;i<=n;i++)
{
    cin>>a;v.push_back(a);
}
for (int i=1;i<=q;i++)
{
    cin>>a>>b;
    d[a]++;
    d[b+1]--;
}

qdeg=0;

for (int i=1;i<=n;i++)
{
 qdeg+=d[i];
 vec1.push_back(qdeg);   
}

sort(v.begin(),v.end());
sort(vec1.begin(),vec1.end());

for (int i=0;i<v.size();i++)
{
 answ+=v[i]*vec1[i];   
}
cout<<answ<<endl;

cin.get();cin.get();
return 0;}