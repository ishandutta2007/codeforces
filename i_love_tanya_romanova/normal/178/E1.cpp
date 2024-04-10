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
#define bs 201004
//#define szz 400
//#define pb push_back
using namespace std;
long n,ar[2100][2100],arp[2100][2100],mx,ans1,ans2;
void dfs(long a,long b)
{
     if (b<mx)mx=b;arp[a][b]=1;
     if (ar[a-1][b]==1&&arp[a-1][b]==0)dfs(a-1,b);
     if (ar[a+1][b]==1&&arp[a+1][b]==0)dfs(a+1,b);
     if (ar[a][b-1]==1&&arp[a][b-1]==0)dfs(a,b-1);
     if (ar[a][b+1]==1&&arp[a][b+1]==0)dfs(a,b+1);
}


int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
{
    cin>>ar[i][j];
}
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
if (arp[i][j]==0&&ar[i][j]==1)
{
                              mx=j;
                 dfs(i,j);
           //      cout<<mx<<" "<<j<<endl;
                 if (mx==j)ans1++; else ans2++;
                 }

cout<<ans2<<" "<<ans1<<endl;

cin.get();cin.get();
return 0;}