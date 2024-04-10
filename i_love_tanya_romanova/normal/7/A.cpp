#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define EPS 1e-9
#pragma comment(linker, "/STACK:16777216")
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;
 char ar[200][200],ar1[200][200];
 long fl,ans,s,mask1,mask2;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

for (int i=1;i<=8;i++)
for (int j=1;j<=8;j++)
cin>>ar[i][j];
//ar[i][j]='W';
ans=20;

for (mask1=0;mask1<=255;mask1++)
for (mask2=0;mask2<=255;mask2++)
{
    s=0;fl=0;
    for (int i=1;i<=8;i++)
    for (int j=1;j<=8;j++)
    ar1[i][j]='W';
    
    for (int i=1;i<=8;i++)
    {if (mask1&(1<<(i-1)))
    {for (int j=1;j<=8;j++)
    ar1[i][j]='B';s++;
    }
    }
    
      for (int i=1;i<=8;i++)
    {if (mask2&(1<<(i-1)))
    {for (int j=1;j<=8;j++)
    ar1[j][i]='B';s++;
    }
    }
    
    for (int i=1;i<=8;i++)
    for (int j=1;j<=8;j++)
    if (ar[i][j]!=ar1[i][j])
     fl=1;
     
     if (fl==0)ans=min(ans,s);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}