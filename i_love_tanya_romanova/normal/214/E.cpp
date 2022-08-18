/*
You take a mortal man,
And put him in control
Watch him become a god
Watch peoples heads a'roll
A'roll...

[chorus:]
Just like the Pied Piper
Led rats through the streets
We dance like marionettes
Swaying to the Symphony ...
Of Destruction

Acting like a robot
Its metal brain corrodes
You try to take its pulse
Before the head explodes
Explodes...

[Chorus]

The earth starts to rumble
World powers fall
A'warring for the heavens
A peaceful man stands tall
Tall...

[Chorus]
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
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
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

long ans[610][305][305],ar[305][305],n;

long solve(long x1,long y1,long x2,long y2)
{
 long bst=ans[x1+y1][x1][x2];
 if (x1>n||x2>n||y1>n||y2>n)return -1000000000;
 
 if (bst>-100000000)return bst;
 
 bst=max(bst,solve(x1+1,y1,x2+1,y2));
 bst=max(bst,solve(x1+1,y1,x2,y2+1));
 bst=max(bst,solve(x1,y1+1,x2+1,y2));
 bst=max(bst,solve(x1,y1+1,x2,y2+1));
 
 bst+=ar[x1][y1];
 if (x2!=x1||y2!=y1)
 bst+=ar[x2][y2];
 ans[x1+y1][x1][x2]=bst;
 return bst;     
}

int main(){
//freopen("wedding.in","r",stdin);
//freopen("wedding.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
cin>>ar[i][j];

for (int i=1;i<=n*2;i++)
for (int j=1;j<=n;j++)
for (int q=1;q<=n;q++)
ans[i][j][q]=-1000000000;

ans[n*2][n][n]=ar[n][n];

cout<<solve(1,1,1,1);

cin.get();cin.get();
return 0;}