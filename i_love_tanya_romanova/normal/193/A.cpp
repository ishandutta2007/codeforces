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
long n,m,s,fl,arp[500][500],ar[500][500];
char q;

void dfs(long a,long b)
{
     arp[a][b]=1;
     if (ar[a-1][b]==1&&arp[a-1][b]==0)
     dfs(a-1,b);
          if (ar[a+1][b]==1&&arp[a+1][b]==0)
     dfs(a+1,b);

     if (ar[a][b-1]==1&&arp[a][b-1]==0)
     dfs(a,b-1);
     if (ar[a][b+1]==1&&arp[a][b+1]==0)
     dfs(a,b+1);

}
void check(long a,long b)
{
     if (ar[a][b]==0)return;
     
     for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++)
     arp[i][j]=0;
     
     arp[a][b]=1;
     long fll=0;
     for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++)
      if (fll==0&&ar[i][j]==1&&arp[i][j]==0)
      {
                    fll=1;                //cout<<i<<" "<<j<<endl;
       dfs(i,j);break;
                                    }
       for (int i=1;i<=n;i++)
       for (int j=1;j<=m;j++)
       if (ar[i][j]==1&&arp[i][j]==0)
       fl=1;
       
       if (a==7&&b==6)
       {
       /*
for(int i=1;i<=n;i++)
{for (int j=1;j<=m;j++)

    cout<<arp[i][j]<<" ";cout<<endl;
}*/
       }
       
}
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
{
        cin>>q;
        if (q=='#')ar[i][j]=1;else ar[i][j]=0;
        if (ar[i][j]==1)s++;
}

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
    check(i,j);
}

if (s<3)cout<<-1<<endl;
else 
if (fl)cout<<1<<endl;
else cout<<2<<endl;

cin.get();cin.get();
return 0;}