#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n,m;
char a[55][55];
bool bl[55][55];
void go(int x,int y)
{
    if(a[x][y]=='#')return;
    bl[x][y]=true;
    if(x>0&&!bl[x-1][y]&&a[x-1][y]!='#')go(x-1,y);
    if(y>0&&!bl[x][y-1]&&a[x][y-1]!='#')go(x,y-1);
    if(x<n-1&&!bl[x+1][y]&&a[x+1][y]!='#')go(x+1,y);
    if(y<m-1&&!bl[x][y+1]&&a[x][y+1]!='#')go(x,y+1);
}
int main()
{
ios::sync_with_stdio(0);
cin>>t;
while(t--)
{cin>>n>>m;
for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){cin>>a[i][j];bl[i][j]=false;}
    bool ans=true;
for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
{
    if(a[i][j]!='B')continue;
    a[i][j]='#';
    if(i>0){if(a[i-1][j]=='G'){ans=false;break;}else if(a[i-1][j]!='B') a[i-1][j]='#';}
    if(j>0){if(a[i][j-1]=='G'){ans=false;break;}else if(a[i][j-1]!='B') a[i][j-1]='#';}
    if(i<n-1){if(a[i+1][j]=='G'){ans=false;break;}else if(a[i+1][j]!='B')a[i+1][j]='#';}
    if(j<m-1){if(a[i][j+1]=='G'){ans=false;break;}else if(a[i][j+1]!='B')a[i][j+1]='#';}
}
if(!ans){cout<<"No\n";continue;}
go(n-1,m-1);
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)if(a[i][j]=='G'&&!bl[i][j]){ans=false;break;}
if(ans)cout<<"Yes\n";
else cout<<"No\n";
}
    return 0;
}