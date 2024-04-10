//#pragma comment(linker, "/STACK:16777216")
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
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,s,x[200000],y[200000],arp[20000];

void dfs(long v)
{
     arp[v]=1;
     
     for (int i=1;i<=n;i++)
     if (arp[i]==0)
     if (x[i]==x[v]||y[i]==y[v])
     dfs(i);
}

int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>x[i]>>y[i];
}
s=0;

for (int i=1;i<=n;i++)
{
    if (arp[i]==0)
    {++s;dfs(i);}
}

cout<<s-1<<endl;
cin.get();cin.get();
return 0;}