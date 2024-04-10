/*
Well I just heard the news today
It seems my life is going to change
I close my eyes, begin to pray
Then tears of joy stream down my face

With arms wide open
Under the sunlight
Welcome to this place
I'll show you everything
With arms wide open
With arms wide open

Well I don't know if I'm ready
To be the man I have to be
I'll take a breath, I'll take her by my side
We stand in awe, we've created life

With arms wide open
Under the sunlight
Welcome to this place
I'll show you everything
With arms wide open
Now everything has changed
I'll show you love
I'll show you everything

With arms wide open
With arms wide open
I'll show you everything, oh yeah
With arms wide open, wide open

If I had just one wish
Only one demand
I hope he's not like me
I hope he understands
That he can take this life
And hold it by the hand
And he can greet the world
With arms wide open

With arms wide open
Under the sunlight
Welcome to this place
I'll show you everything
With arms wide open
Now everything has changed
I'll show you love
I'll show you everything
With arms wide open
With arms wide open

I'll show you everything, oh yeah
With arms wide open, wide open
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
#define M_PI 3.141592653589793
//#define bs 1000000007
#define bsize 256

using namespace std;

int n,m,b,bs,er[600],dp[55][505][505];

void add(int &a,int b)
{
    a+=b;
    if (a>=bs)a-=bs;
}

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>b>>bs;
for (int i=0;i<n;i++)
    cin>>er[i];

dp[0][0][0]=1;

for (int iter=0;iter<n;iter++)
{

for (int i=0;i<=m;i++)
    for (int j=0;j<=b;j++)
        dp[1^(iter%2)][i][j]=0;
        
for (int i=0;i<=m;i++)
{
    for (int j=0;j<=b;j++)
    {
        if (j+er[iter]<=b)
            add(dp[iter%2][i+1][j+er[iter]],dp[iter%2][i][j]);
        add(dp[(iter+1)%2][i][j],dp[iter%2][i][j]);
    }
}

}

int answ=0;
for (int i=0;i<=b;i++)
    add(answ,dp[n%2][m][i]);
cout<<answ<<endl;

//cin.get();cin.get();
return 0;}