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
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,m,k,ar[1100][1100],row[1100],col[1100];
long a,b,c;
char tp;

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
for (int i=1;i<=max(n,m);i++)
row[i]=col[i]=i;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
cin>>ar[i][j];
for (int i=1;i<=k;i++)
{
    cin>>tp;
    cin>>a>>b;
    if (tp=='c')
    {
                swap(col[a],col[b]);
    }
    else if (tp=='r')
    {
         swap(row[a],row[b]);
         
    }
    
    else cout<<ar[row[a]][col[b]]<<endl;
    
}


cin.get();cin.get();
return 0;}