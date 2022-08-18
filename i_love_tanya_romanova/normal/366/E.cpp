/*
Tell me where it hurts, so I can reach the pain.
Tell me where it hurts. Just pump it through my vain.
Be brave and tell me where it hurts.

There's something deep inside than you don't want to show.
There's something that you hide, 'cause you're afraid I'll go.
But no.
Tell me where it hurts.

You tell me not to go. (Tell me where it hurts)
Say you want to be my holy grail. (Tell me where it hurts)
And your skin is white like fallen snow. (Tell me where it hurts)
I don't want to leave my marks. (Tell me where it hurts)
But if I do, are you brave enough to let me through to touch you where it hurts?

I'll touch you where it hurts.
I'll touch you where it hurts.
I'll touch you where it hurts.
And you can touch me.
Come on and touch me where it hurts.

Everyone I know seems to be broken inside.
Everybody hurting just from being alive.

Touch me where it hurts.
Touch me where it hurts.
Touch me where it hurts.
Touch me where it hurts.
Come touch me where it hurts.
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,k,s,temp,mxs[1000],mns[1000],mnd[1000],mxd[1000];
long ans[100][100];
long long answ,temp1;

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=1;i<=10;i++)
mxs[i]=mxd[i]=-100000;
for (int i=1;i<=10;i++)
mns[i]=mnd[i]=1000000;

cin>>n>>m>>k>>s;
for (long i=1;i<=n;i++)
for (long j=1;j<=m;j++)
{
 cin>>temp;
 mxs[temp]=max(mxs[temp],i+j);
 mxd[temp]=max(mxd[temp],i-j);
 mns[temp]=min(mns[temp],i+j);
 mnd[temp]=min(mnd[temp],i-j);   
}

for (long i=1;i<=k;i++)
 for (long j=1;j<=k;j++)
 {
  ans[i][j]=mxd[i]-mnd[j];
  ans[i][j]=max(ans[i][j],mxs[i]-mns[j]);
  ans[i][j]=max(ans[i][j],-mnd[i]+mxd[j]);
  ans[i][j]=max(ans[i][j],-mns[i]+mxs[j]);   
 }

answ=0;
cin>>temp;
for (int i=2;i<=s;i++)
{
    cin>>temp1;
    answ=max(answ,0ll+ans[temp][temp1]);
    temp=temp1;
}
cout<<answ<<endl;

cin.get();cin.get();
return 0;}