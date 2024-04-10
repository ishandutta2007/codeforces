#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n,q,A[200005],l,r,u,dd,i,t[20][200005];
ll a,b,c,d,e,f,g,h;
void build(int h,int l,int r)
{
    if(l==r) t[h][l]=A[l];
    else
    {
        int mid=(l+r)/2;
        build(h+1,l,mid);
        build(h+1,mid+1,r);
        int i=l,j=mid+1,k=l;
        while(i<=mid && j<=r)
        if(t[h+1][i]<t[h+1][j])
        t[h][k++]=t[h+1][i++];
        else t[h][k++]=t[h+1][j++];
        while(i<=mid)
        t[h][k++]=t[h+1][i++];
        while(j<=r)
        t[h][k++]=t[h+1][j++];
    }
}
int query(int h,int l,int r,int a,int b,int d)
{
    if(a>r || b<l || d<=0 || b<=0 || a>n || b<a) return 0;
    if(r<=b && l>=a) return upper_bound(t[h]+l,t[h]+r+1,d)-(t[h]+l);
    else
    {
        int mid=(l+r)/2;
        return query(h+1,l,mid,a,b,d)+query(h+1,mid+1,r,a,b,d);
    }
}
int main()
{
    io
    cin>>n>>q;
    for(i=1;i<=n;++i)
    cin>>A[i];
    build(0,1,n);
    while(q--)
    {
        cin>>l>>dd>>r>>u;
        g=query(0,1,n,1,l-1,dd-1);
        d=query(0,1,n,1,l-1,u)-g;
        a=l-1-d-g;
        h=query(0,1,n,l,r,dd-1);
        e=query(0,1,n,l,r,u)-h;
        b=r-l+1-h-e;
        i=query(0,1,n,r+1,n,dd-1);
        f=query(0,1,n,r+1,n,u)-i;
        c=n-r-i-f;
        cout<<(a*(e+h+i+f)+b*(d+e+f+g+h+i)+c*(d+e+g+h)+d*(b+c+e+f+h+i)+e*(a+b+c+d+f+g+h+i)+f*(a+b+d+e+g+h)+g*(b+c+e+f)+h*(a+b+c+d+e+f)+i*(a+b+d+e))/2+(e*(e-1))/2<<"\n";
    }
    return 0;
}