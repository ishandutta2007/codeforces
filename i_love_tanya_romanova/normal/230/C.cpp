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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1200000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,m; char ar[120][120000];
long d1[120][120000],d2[120][120000];
long fl,p,fl1,ans[120000],answ;

string st;

int main(){
//freopen("subseq.in","r",stdin);
//freopen("subseq.out","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
getline(cin,st);

for (int i=1;i<=n;i++)
{
    getline(cin,st);
    for (int j=1;j<=m;j++)
    ar[i][j]=st[j-1]-48;
}

for (int i=1;i<=n;i++)
{
 fl=0;
 for (int j=1;j<=m;j++)
 if(ar[i][j]==1)fl=1;
 if (fl==0)fl1=1;   
}

if (fl1)
{
        cout<<-1<<endl;
}
else

{
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    ar[i][j+m]=ar[i][j];
    
    for (int i=1;i<=n;i++)
    {
        p=2*m;
        for (int j=2*m;j>m;--j)
        if (ar[i][j])p=j;
        for (int j=m;j;--j)
        {
            
            if (ar[i][j]==1)p=j;
            d1[i][j]=p-j;
        }
    }
    
    for (int i=1;i<=n;i++)
    {
        p=1;
        for (int j=1;j<=m;++j)
        if (ar[i][j])p=j;
        
        for (int j=m+1;j<=2*m;++j)
        {
            
            if (ar[i][j]==1)p=j;
            d2[i][j-m]=j-p;
        }
    }
    
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    {
        ans[j]+=min(d1[i][j],d2[i][j]);
    }
    answ=10000000;
    for (int i=1;i<=m;i++)
    if (ans[i]<answ)answ=ans[i];
    
    cout<<answ<<endl;
}

cin.get();cin.get();
return 0;}