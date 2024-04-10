#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=2e5+5;
int n,q;
char s[N];
struct node
{
    int a[5][5];
    node(){memset(a,inf,sizeof(a));}
    node operator*(const node&o)const
    {
        node ans;
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
            for(int k=0;k<5;k++)
            ans.a[i][j]=min(ans.a[i][j],a[i][k]+o.a[k][j]);
        return ans;
    }
}t[N<<2];
void solve(int l,int k)
{
    for(int i=0;i<5;i++) t[k].a[i][i]=0;
    if(s[l]=='2') t[k].a[0][0]=1,t[k].a[0][1]=0;
    if(s[l]=='0') t[k].a[1][1]=1,t[k].a[1][2]=0;
    if(s[l]=='1') t[k].a[2][2]=1,t[k].a[2][3]=0;
    if(s[l]=='7') t[k].a[3][3]=1,t[k].a[3][4]=0;
    if(s[l]=='6') t[k].a[3][3]=t[k].a[4][4]=1;
}
void build(int l,int r,int k)
{
    if(l==r) {solve(l,k);return;}
    int m=l+r>>1;
    build(l,m,k<<1);build(m+1,r,k<<1|1);
    t[k]=t[k<<1]*t[k<<1|1];
}
node res;
void query(int l,int r,int k,int x,int y)
{
    if(r<x||l>y) return;
    if(l>=x&&r<=y) {res=res*t[k];return;}
    int m=l+r>>1;
    query(l,m,k<<1,x,y);
    query(m+1,r,k<<1|1,x,y);
}
int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    build(1,n,1);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        res=node();
        for(int i=0;i<5;i++) res.a[i][i]=0;
        query(1,n,1,l,r);
        int ans=res.a[0][4];
        if(ans==inf) ans=-1;
        printf("%d\n",ans);
    }
}