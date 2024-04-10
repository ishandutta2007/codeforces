/*
Grace - in a perfect world
On shines the light
Praise - an angelic song
but there's another side you'll see
Now hide
salvation easily denied

Reigns - Down with misery
Life's not always what it seems
False hope
written in the testament of old
Take heed
stop believing every word you read
Truth inconsistencies
Distorts the lie
False imprisonment
Forever lost inside your mind
Fates door
Just be careful what you wish for
Death's door
Just be careful what you wish for

Peace of mind I can't find
Don't be blind take the ride

Hey... we live in a fucked up world
Walking on through the demise
We step into the unknown
Your better save yourself...

Hey... we live in a fucked up world
Hiding behind the disguise
Never let your feelings show
Why can't you be yourself...
We live in a fucked up world
Walking on through the demise
We step into the unknown
Your better save yourself...
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

char t;
long a,b,c,x,y,arp[15][15][15];
long ans;

void dfs(long a,long b,long c)
{
 arp[a][b][c]=1;
 ++ans;
 if (arp[a-1][b][c]==0)dfs(a-1,b,c);
 if (arp[a+1][b][c]==0)dfs(a+1,b,c);
 if (arp[a][b-1][c]==0)dfs(a,b-1,c);
 if (arp[a][b+1][c]==0)dfs(a,b+1,c);
 if (arp[a][b][c-1]==0)dfs(a,b,c-1);
 if (arp[a][b][c+1]==0)dfs(a,b,c+1);
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a>>b>>c;
for (int i=0;i<=a+1;i++)
for (int j=0;j<=b+1;j++)
for (int q=0;q<=c+1;q++)
arp[i][j][q]=1;

for (int i=1;i<=a;i++)
for (int j=1;j<=b;j++)
for (int q=1;q<=c;q++)
{
 cin>>t;if (t=='.')arp[i][j][q]=0;   
}

cin>>x>>y;
dfs(1,x,y);
cout<<ans<<endl;

cin.get();cin.get();
return 0;}