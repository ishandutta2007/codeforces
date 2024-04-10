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

long n,m,q,ar1[200000],ara[200000],ar2[200000],par[200000];

int main(){
//freopen("mitm.in","r",stdin);
//freopen("mitm.out","w",stdout);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    ar1[q]=i;
}
for (int i=1;i<=n;i++)
{
    cin>>q;
    ar2[q]=i;
}
for (int i=1;i<=n;i++)
{
    par[ar2[i]]=ar1[i];
}
/*
for (int i=1;i<=n;i++)
cout<<par[i]<<endl;
*/
for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<par[i];
}
cout<<endl;

for (int t=1;t<=2;t++)
for (int i=1;i<=n;i++)
{
    ar1[i]=par[ar1[i]];
}

for (int i=1;i<=n;i++)
ara[ar1[i]]=i;

/*for (int i=0;i<n;i++)
{if (i)cout<<" ";
cout<<ara[i+1];}
cout<<endl;
*/
cin.get();cin.get();
return 0;}