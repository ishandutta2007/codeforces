#include <iostream>

using namespace std;

bool mark[200000][200];
int flag[1000000],y,ans[200000],n,ans1=1000000000;

void xo(int node,int l,int r,int beg,int en)
{
    if(beg<=l && r<=en)
    {
        y=y^flag[node];
        return;
    }
    int mid=(l+r)/2;
    if(beg<mid) xo(2*node,l,mid,beg,min(mid,en));
    if(mid<en)  xo(2*node+1,mid,r,max(beg,mid),en);
}

void add(int node,int l,int r,int x)
{
    if(l+1>=r)
    {
        flag[node]=ans[x];
        return;
    }
    int mid=(l+r)/2;
    if(x<mid) add(2*node,l,mid,x);
    else add(2*node+1,mid,r,x);
    flag[node]=flag[2*node]^flag[2*node+1];
}

int main()
{
    cin>>n;
    for(int i=2;2*i-1<=n;i++)
        for(int j=1;(j+1)*(i+i-j)/2<=n && j<i;j++)
        {
            int x=(j+1)*(i+i-j)/2;
            y=0;
            xo(1,1,n+1,i-j,i+1);
            mark[x][y]=true;
            for(int u=0;u<100;u++)
                if(!mark[x][u])
                {
                    ans[x]=u;
                    add(1,1,n+1,x);
                    break;
                }
           // cout<<i<<" "<<j<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" "<<ans[4]<<" "<<ans[5]<<" "<<ans[6]<<" "<<x<<" "<<y<<endl;
            if(x==n && y==0)
                ans1=min(ans1,j+1);
        }
    if(ans1>n)
        cout<<-1<<endl;
    else
        cout<<ans1<<endl;
}