#include <iostream>
#include<algorithm>

using namespace std;

int dp[500000][65],n,q,k,a[200000];

void update(int x)
{
    for(int i=0;i<60;i++)
        dp[x][i]=dp[2*x][i]+dp[2*x+1][(dp[2*x][i]+i)%60];
}

void make(int node,int l,int r)
{
    if(l+1>=r)
    {
        for(int i=0;i<60;i++)
        {
            if(i%a[l]==0)
                dp[node][i]=2;
            else
                dp[node][i]=1;
        }
 //   cout<<node<<" "<<l<<" "<<r<<" "<<dp[node][5]<<endl;
        return;
    }
    int mid=(l+r)/2;
    make(2*node,l,mid);
    make(2*node+1,mid,r);
    update(node);
   // cout<<node<<" "<<l<<" "<<r<<" "<<dp[node][5]<<endl;
}

void change(int node,int l,int r,int x,int val)
{
   // cout<<node<<" "<<l<<" "<<r<<" "<<x<<" "<<val<<endl;
    if(l+1>=r)
    {
        a[l]=val;
        for(int i=0;i<60;i++)
        {
            if(i%a[l]==0)
                dp[node][i]=2;
            else
                dp[node][i]=1;
        }
        return;
    }
    int mid=(l+r)/2;
    if(x<mid)   change(2*node,l,mid,x,val);
    else    change(2*node+1,mid,r,x,val);
    update(node);
}

void f(int node,int l,int r,int beg,int en)
{
    if(beg<=l && r<=en)
    {
      //  cout<<node<<" "<<l<<" "<<r<<" "<<k<<" "<<dp[node][k%60]<<endl;
        k+=dp[node][k%60];
        return;
    }
    int mid=(l+r)/2;
    if(beg<mid) f(2*node,l,mid,beg,min(mid,en));
    if(mid<en)  f(2*node+1,mid,r,max(beg,mid),en);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    make(1,0,n);
    cin>>q;
    for(int i=0;i<q;i++)
    {
        char c;int l,r;
        cin>>c>>l>>r;
        if(c=='A')
        {
            k=0;
            f(1,0,n,l-1,r-1);
            cout<<k<<endl;
        }
        else
        {
            change(1,0,n,l-1,r);
        }
     //   cout<<"******"<<dp[5][0]<<endl;
    }
}