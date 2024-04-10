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

long n,pr[500000],ans[500000];
vector<long> v[200000];
long answ,q,ar[500000],mx;

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

pr[1]=1;

for (int i=2;i<=100000;i++)
if (pr[i]==0)
{
             v[i].push_back(i);
             for (int j=i*2;j<=100000;j+=i)
             {
                 pr[j]=1;v[j].push_back(i);
             }
}

cin>>n;

for (int i=1;i<=n;i++)
cin>>ar[i];

q=ar[1];

for (int i=0;i<v[q].size();i++)
{
    ans[v[q][i]]=1;
}

for (int i=2;i<=n;i++)
{
    q=ar[i];
    mx=-1;
    
    for (int i=0;i<v[q].size();i++)
    mx=max(mx,ans[v[q][i]]);
    
    for (int i=0;i<v[q].size();i++)
    ans[v[q][i]]=mx+1;
}

answ=0;
for (int i=0;i<=100000;i++)
answ=max(answ,ans[i]);
if (answ<1)answ=1;

cout<<answ<<endl;

cin.get();cin.get();
return 0;}