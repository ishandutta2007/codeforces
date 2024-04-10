#include<cstdio>
#include<algorithm>
using namespace std;
class T
{
    public:
    long long data[8000005],tag[8000005];
    void pushup(int k)
    {
        data[k]=max(data[2*k],data[2*k+1]);
    }
    void add(int k,long long val)
    {
        data[k]+=val;
        tag[k]+=val;
    }
    void pushdown(int k)
    {
        if(!tag[k]) return;
        add(2*k,tag[k]);
        add(2*k+1,tag[k]);
        tag[k]=0;
    }
    void build(int k,int l,int r)
    {
        tag[k]=0;
        data[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(2*k,l,mid);
        build(2*k+1,mid+1,r);
        pushup(k);
    }
    void change(int k,int l,int r,int ql,int qr,long long val)
    {
        if(l>qr || r<ql) return;
        if(ql<=l && qr>=r) return add(k,val);
        int mid=(l+r)/2;
        pushdown(k);
        change(2*k,l,mid,ql,qr,val);
        change(2*k+1,mid+1,r,ql,qr,val);
        pushup(k);
    }
    long long ask(int k,int l,int r,int ql,int qr)
    {
        if(l>qr || r<ql) return 0;
        if(ql<=l && qr>=r) return data[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(ask(2*k,l,mid,ql,qr),ask(2*k+1,mid+1,r,ql,qr));
    }
}tr;
int n,t,a[200005],pos[200005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        tr.build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++) tr.change(1,1,n,i,i,n-i+i-i+(i%2));
        long long mx=0;
        int pre=n;
        for(int i=n;i>=1;i--)
        {
            pre=min(pre,pos[i]-1);
            tr.change(1,1,n,pos[i],pos[i],-1e7);
            tr.change(1,1,n,pos[i]+1,n,2);
            tr.change(1,1,n,1,n,-1);
            mx=max(mx,tr.ask(1,1,n,pre+1,n));
        }
        printf("%lld\n",mx);
    }
}