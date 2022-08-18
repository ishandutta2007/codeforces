/*
Running with the wolf pack
Feel like I'm never coming back
And every time, there's sunshine
I'm blind, yeah

I am everybody
And everyone that I know is me
Everyone that I know won't see

I could have been a dreamer
I could have been a shooting star
I could have been a dreamer, yeah

I'm another number
And you know the numbers must agree
But every time, the wind blows
I can't fly, why?

We take away tomorrow
And never see the end of today
Lock it up and send it away, forever

I could have been a dreamer
I could have been a shooting star
I could have been a dreamer
'Cause dreams are what we are
I could have been a dreamer

Running with the wolf pack
Feel like I'm never coming back
But maybe that was sunshine
That I saw

I've heard about a rainbow
I've heard it makes you crazy
I think I'm goin' crazy
Crazy 'cause I see

I could have been a dreamer
I could have been a shooting star
I could have been a dreamer
'Cause dreams are what we are

I could have been a dreamer
I could have been the one to fly
I always could have been a dreamer
'Cause dreamers never die, no

I could have been a dreamer
Dreamer
I could have been a dreamer
Dreamer

I could have been a dreamer
Dreamer
I could have been a dreamer
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,m,q,ar[600][600];
int res;
multiset<long> S;

int solve(int line)
{
    int bst=0;
    int s=0;
    for (int i=1;i<=m;i++)
    {
        ++s;
        if (ar[line][i]==0)
            s=0;
        bst=max(bst,s);
    }
    return bst;
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>q;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  cin>>ar[i][j];

for (int i=1;i<=n;i++)
{
    int res=solve(i);
    S.insert(res);
}

for (;q;--q)
{
    int a,b;
    cin>>a>>b;
    int res=solve(a);
    S.erase(S.find(res));
    ar[a][b]^=1;
    res=solve(a);
    S.insert(res);
    cout<<(*S.rbegin())<<endl;
}

//cin.get();cin.get();
return 0;}