#include<bits/stdc++.h>
using namespace std;
struct hxz{
    int x,y;long long z,k;
};
hxz a[2000000],b[2000000],t;
int f[2000000];
int n,m,i,j,r1,r2,ww,w;
long long ans,aa,bb;
int find(int x)
{
  if (f[x]==x) return f[x];
  f[x]=find(f[x]);return f[x];
}
bool cmp(hxz a,hxz b)
{
    return a.k<b.k;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie();cout.tie();
    cin>>n>>m;
    cin>>aa>>bb;
    ans=4000000000000000000;
    for (i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z>>a[i].k;
    sort(a+1,a+m+1,cmp);
    for (i=1;i<=m;i++)
         {
             w++;b[w]=a[i];
             for (j=w-1;j>=1;j--)
                 if (b[j].z>b[j+1].z)
                     {
                         t=b[j];b[j]=b[j+1];b[j+1]=t;
                     }
            ww=0;
            for (j=1;j<=n;j++) f[j]=j;
            for (j=1;j<=w;j++)
                {
                    r1=find(b[j].x);r2=find(b[j].y);
                    if (r1!=r2)
                        {
                            f[r1]=r2;
                            ww++;b[ww]=b[j];
                        }
                }
            if (ww==n-1)
                {
                    ans=min(ans,aa*b[ww].z+bb*a[i].k);
                }
            w=ww;
         }
    if (ans==4000000000000000000) ans=-1;
    cout<<ans<<endl;
    return 0;
}