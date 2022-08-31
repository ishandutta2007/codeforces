/*
What do you mean, "I don't believe in God"?
I talk to him every day.
What do you mean, "I don't support your system"?
I go to court when I have to.
What do you mean, "I can't get to work on time"?
I got nothing better to do
And, what do you mean, "I don't pay my bills"?
Why do you think I'm broke? Huh?

[Chorus:]
If there's a new way,
I'll be the first in line.
But, it better work this time.

What do you mean, "I hurt your feelings"?
I didn't know you had any feelings.
What do you mean, "I ain't kind"?
I'm just not your kind.
What do you mean, "I couldn't be the president of the United States of America"?
Tell me something, it's still "We the people", right?

[Chorus: (repeat)]
If there's a new way
I'll be the first in line,
But, it better work this time.

Can you put a price on peace?
Peace,
Peace sells...,
Peace,
Peace sells...,
Peace sells...,but who's buying?
Peace sells...,but who's buying?
Peace sells...,but who's buying?
Peace sells...,but who's buying?
[n+1 times more]
No, peace sells...
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;

long long n,ar[600][600],bd[600],ans[600],usd[600];
int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
cin>>ar[i][j];

for (int i=1;i<=n;i++)
cin>>bd[n-i+1];

for (int k=1;k<=n;k++)
{


for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
{
 if (ar[i][bd[k]]+ar[bd[k]][j]<ar[i][j])ar[i][j]=ar[i][bd[k]]+ar[bd[k]][j];
}

usd[bd[k]]=1;
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
if (usd[i]==1&&usd[j]==1)ans[k]+=ar[i][j];
}

for( int i=1;i<=n;i++)
{if (i>1)cout<<" ";cout<<ans[n-i+1];//<<" ";
}
cout<<endl;

cin.get();cin.get();
return 0;}