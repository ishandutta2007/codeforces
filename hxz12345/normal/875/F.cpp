#include<bits/stdc++.h>
using namespace std;
struct hxz{
int x,y;long long z;
};
int f[2000000],e[2000000];
hxz a[2000000];
int n,m,i,r1,r2;
long long sum;
bool cmp(hxz a,hxz b)
{
    return a.z>b.z;
}
int find(int x)
{
    if (f[x]==x) return f[x];f[x]=find(f[x]);return f[x];
}
int main()
{
    ios::sync_with_stdio(0);cin.tie();cout.tie();
    cin>>n>>m;
    for (i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z;
    for (i=1;i<=n;i++) 
          { f[i]=i;e[i]=1;}
    sort(a+1,a+m+1,cmp);
    for (i=1;i<=m;i++)
          {
              r1=find(a[i].x);r2=find(a[i].y);
              if ( r1!=r2)
                   {
                       if (e[r1]| e[r2]==1)
                            {
                                sum+=a[i].z;
                                e[r2]=e[r2] & e[r1];
                                f[r1]=r2;
                            }
                        }
                    else
                    {
                        if (e[r1]==1)
                             {
                                 sum+=a[i].z;e[r1]=0;
                             }
                    }
          }
    cout<<sum<<endl;
    return 0;
}