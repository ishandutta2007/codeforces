#include <iostream>
#include<algorithm>

using namespace std;

long long n,l1,r1,sum[600000],q,m;

long long f(long long node,long long l,long long r,long long beg,long long en)
{
    if(beg<=l && r<=en)
        return sum[node];
    long long mid=(l+r)/2,ans=0;
    if(beg<mid) ans=f(2*node,l,mid,beg,min(mid,en));
    if(mid<en)  ans+=f(2*node+1,mid,r,max(mid,beg),en);
    return ans;
}

void make(long long node,long long l,long long r)
{
    sum[node]=r-l;
    if(l+1>=r)
        return;
    long long mid=(l+r)/2;
    make(2*node,l,mid);
    make(2*node+1,mid,r);
}

void add(long long node,long long l,long long r,long long x,long long val)
{
        sum[node]+=val;
    if(l+1>=r)
        return;
    long long mid=(l+r)/2;
    if(x<mid)   add(2*node,l,mid,x,val);
    else    add(2*node+1,mid,r,x,val);
}

int main()
{
    cin>>n>>q;
    r1=n;
    make(1,0,n);
    for(long long qw=1;qw<=q;qw++)
    {
        long long t1;
        cin>>t1;
        if(t1==1)
        {
            long long p;
            cin>>p;
            if(m==0)
            {
                if(r1-l1>p*2)
                {
                    for(long long i=l1+p;i<l1+p+p;i++)
                        add(1,0,n,i,f(1,0,n,l1+p-i+l1+p-1,l1+p-i+l1+p));
                    l1+=p;
                }
                else
                {
                    for(long long i=l1+p;i<r1;i++)
                        add(1,0,n,l1+p-i+l1+p-1,f(1,0,n,i,i+1));
                    r1=l1+p;
                    m=1-m;
                }
            }
            else
            {
                if(r1-l1>p*2)
                {
                    for(long long i=r1-p-1;i>=r1-p-p;i--)
                        add(1,0,n,i,f(1,0,n,r1-p-1-i+r1-p,r1-p-1-i+r1-p+1));
                    r1-=p;
                }
                else
                {
                    for(long long i=r1-p-1;i>=l1;i--)
                        add(1,0,n,r1-p-1-i+r1-p,f(1,0,n,i,i+1));
                    l1=r1-p;
                    m=1-m;
                }
            }
        }
        else
        {
            long long l,r;
            cin>>l>>r;
            if(m==0)
                cout<<f(1,0,n,l+l1,r+l1)<<endl;
            else
                cout<<f(1,0,n,r1-r,r1-l)<<endl;
        }
       /* cout<<l1<<"->"<<r1<<" "<<m<<endl;
        for(int i=l1;i<r1;i++)
            cout<<f(1,0,n,i,i+1)<<endl;*/
    }
}