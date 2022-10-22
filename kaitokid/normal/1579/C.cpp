#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c[30][30];
bool bl[30][30];
int n,m,k;
void go(int x,int y)
{
    int r=0,u=x-1,v=y-1;
    while(u>=0 && v>=0)
    {
        if(c[u][v]!='*')break;
        r++;
        u--;
        v--;
    }
    u=x-1,v=y+1;
    int g=0;
    while(u>=0 && v<m)
    {
        if(c[u][v]!='*')break;
        g++;
        u--;
        v++;
    }
    g=min(g,r);
    if(g<k)return;
    for(int i=0;i<=g;i++)bl[x-i][y-i]=bl[x-i][y+i]=1;

}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        cin>>c[i][j];
        bl[i][j]=0;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)if(c[i][j]=='*')go(i,j);
      bool ans=true;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)if(c[i][j]=='*' && bl[i][j]==0){ans=false;break;}
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

}
return 0;
}