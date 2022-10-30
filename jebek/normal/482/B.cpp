#include <iostream>

using namespace std;

int n,m,t[40][200000],a[200000],flag[1000000],ans;

void make(int node,int l,int r)
{
    if(l+1>=r)
    {
        flag[node]=a[l];
        return;
    }
    int mid=(l+r)/2;
    make(2*node,l,mid);
    make(2*node+1,mid,r);
    flag[node]=flag[2*node]&flag[2*node+1];
}

void f(int node,int l,int r,int beg,int en)
{
    if(beg<=l && r<=en)
    {
        ans&=flag[node];
        return;
    }
    int mid=(l+r)/2;
    if(beg<mid) f(2*node,l,mid,beg,min(mid,en));
    if(mid<en)  f(2*node+1,mid,r,max(beg,mid),en);
}

int l[200000],r[200000],q[200000];

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>l[i]>>r[i]>>q[i];
        l[i]--;
        r[i]--;
        for(int j=0;j<30;j++)
            if(q[i]&(1<<j))
            {
                t[j][l[i]]++;
                t[j][r[i]+1]--;
            }
    }
    for(int j=0;j<30;j++)
        for(int i=0;i<n;i++)
        {
            if(t[j][i]>0)
                a[i]+=(1<<j);
            t[j][i+1]+=t[j][i];
        }
    make(1,0,n);
    for(int i=0;i<m;i++)
    {
        ans=(1<<30)-1;
        f(1,0,n,l[i],r[i]+1);
        if(ans!=q[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}