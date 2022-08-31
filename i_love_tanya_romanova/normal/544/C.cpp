/*
I can't believe this now
This isn't what I planned
I lived and died and now
I just can't understand
With all the love I feel
I could never leave you
No matter what the cost
My soul 's the price to see you

Oh how I love you
The pain won't go away
Oh when I need you
You're always so far away
I cry for you
Leaving myself to blame
I died for you
I gave up everything

The pain was just too much
When I finally saw her
She's happy and in love
In love with my best friend
What makes it hurt so bad
Is that I love them both
And they will never know
For love I sold my soul

Oh how I love you
The pain won't go away
Oh when I need you 
You're always so far away
I cry for you
Leaving myself to blame
I died for you
I gave up everything
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