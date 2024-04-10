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

long lst,arp[10000],ar[200][200],s,ans,n,a,b,c;
void dfs(long a)
{
     //cout<<a<<endl;
     lst=a;
     arp[a]=1;
     for (int i=0;i<n;i++)
     {
     if (arp[i]==0&&ar[a][i]<1000000)
     {
     s+=ar[a][i];dfs(i);
                                     }
     }
}

long trydfs(long a)
{
     if (ar[0][a]>100000)return 10000000;
     for (int i=0;i<n;i++)
     arp[i]=0;
     arp[0]=1;
     arp[a]=1;
     s=ar[0][a];
     dfs(a);
     //cout<<lst<<endl;
     return s+ar[lst][0];
}
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
cin>>n;
for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
ar[i][j]=10000000;

for (int i=1;i<=n;i++)
{
    cin>>a>>b>>c;
    --a;--b;
    ar[a][b]=0;
    ar[b][a]=c;
}

ans=100000000;

for (int i=1;i<n;i++)
{
 ans=min(ans,trydfs(i));
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}