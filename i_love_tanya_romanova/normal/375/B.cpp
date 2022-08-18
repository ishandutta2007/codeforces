/*
Your touch is like a snakebite kiss
Your love is like a boon
A leader in my haggard dreams
Emotions of a fool

No way out

I'm spoiling you with my prurience
My sadness disappears
The way you told me beside stories
Still pleasant to my ears

A willing and addictive girl
Wide open legs so tempting
The gleeming of her greedy eyes
Seduced me to come back

Your touch was like a snakebite kiss
Your love was like a boon
The leader in my haggard dreams
He passes me the gun
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long n,m,ar[5100][5100],calc[5100],tover;
long ans;

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    cin>>st;
    for (int j=1;j<=m;j++)
    {
     ar[i][j]=st[j-1]-48;
    }
}

for (int i=1;i<=n;i++)
 for (int j=m;j;--j)
 {if (ar[i][j]!=0)ar[i][j]+=ar[i][j+1];}

for (int i=1;i<=m;i++)
{
    for (int j=0;j<=5000;j++)
    calc[j]=0;
    for (int j=1;j<=n;j++)
    calc[ar[j][i]]++;
    tover=n;
    for (int j=0;j<=m;j++)
    {
     ans=max(ans,tover*j);tover-=calc[j];
    }
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}