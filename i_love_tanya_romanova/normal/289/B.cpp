/*
It's been a long time
Now I'm coming back home
I've been away now
Oh how, I've been alone

Wait till I come back to your side
We'll forget the tears we've cried

But if your heart breaks
Don't wait, turn me away
And if your heart's strong
Hold on, I won't delay

Wait till I come back to your side
We'll forget the tears we've cried

I feel as though
You ought to know
That I've been good
As good as I can be
And if you do
I'll trust in you
And know that you
Will wait for me

It's been a long time
Now I'm coming back home
I've been away now
Oh how, I've been alone

Wait till I come back to your side
We'll forget the tears we've cried

I feel as though
You ought to know
That I've been good
As good as I can be
And if you do
I'll trust in you
And know that you
Will wait for me

But if your heart breaks
Don't wait, turn me away
And if your heart's strong
Hold on, I won't delay

Wait till I come back to your side
We'll forget the tears we've cried

It's been a long time
Now I'm coming back home
I've been away now
Oh how, I've been alone
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

long long n,m,d,s,ans;
long long ar[200][300];long long q;
long long rem[100000],ddiv[100000];

int main(){
//freopen("bees.in","r",stdin);
//freopen("bees.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>d;
ans=100000000;
ans*=ans;

for (int i=0;i<=10000;i++)
{
 rem[i]=i%d;ddiv[i]=i/d;   
}

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
cin>>ar[i][j];

for (int r=0;r<=10000;r++)
{
s=0;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
    q=ar[i][j]-r;
    q=abs(q);
    if (rem[q])s=1000000000;
    else s+=ddiv[q];
}
ans=min(ans,s);
}
if (ans>100000000)ans=-1;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}