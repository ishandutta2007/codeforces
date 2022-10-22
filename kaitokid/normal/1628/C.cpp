#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1009][1009],n;
int pr[1009][1009];
int cal(int x,int y,int u,int v)
{
    int ans=pr[u][v];
    ans^=pr[x-1][v];
    ans^=pr[u][y-1];
    ans^=pr[x-1][y-1];
    return ans;
}
int go1(int x,int y,int r)
{
    if(x>n||y<1)return 0;
    int g=a[x][y];
    if(r==0)g=0;
    int f=go1(x+1,y-1,1-r);
    f^=g;
    return f;

}

int go2(int x,int y,int r)
{
    if(x>n||y>n)return 0;
    int g=a[x][y];
    if(r==0)g=0;
    return g^go2(x+1,y+1,1-r);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            pr[i][j]=pr[i-1][j]^pr[i][j-1]^pr[i-1][j-1]^a[i][j];
        }

        vector<int>r;
        r.push_back(cal(1,1,n,n));
        int ans=r[0];
      //  cout<<r[0]<<endl;
        int i=2,j=n-1;
        while(j>i)
        {
            int g=cal(i,i,j,j);
            int p=r.back();
            g^=p;
            ans^=g;
            r.push_back(g);
        //    cout<<g<<endl;
        j--;
        i++;
        }
      for(int i=1;i<n;i+=2)
            ans^=go1(1,i,1);
      for(int i=n;i>1;i-=2)
        ans^=go2(1,i,1);
    cout<<ans<<endl;
    }
    return 0;
}