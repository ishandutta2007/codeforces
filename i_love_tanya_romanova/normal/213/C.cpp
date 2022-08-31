/*
Born to push you around
You better just stay down
You pull away
He hits the flesh
You hit the ground

Mouth so full of lies
Tend to black your eyes
Just keep them close
Keep praying
Just keep waiting

Waiting for the one
The day that never comes
When you stand up and feel the warmth
But the sunshine never comes, no...
The sunshine never comes

Push you across that line
Just stay down this time
Hide in yourself
Crawl in yourself
You'll have your time

God, I'll make 'em pay
Take it back one day
I'll end this day
I'll splatter color on this grey

Waiting for the one
The day that never comes
When you stand up and feel the warmth
But the sunshine never comes, no...
The sunshine never comes

Love is a four letter word
And never spoken here
Love is a four letter word
Here in this prison

I suffer this no longer
I'll put an end to this I swear!
This I swear!
The sun will shine
This I swear!
This I swear!
This I swear!
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