#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>

using namespace std;

typedef long long ll;
const int MAXN=300010;
int n,k,v[20][MAXN];
ll a[MAXN],ans[MAXN*4];
int sum1[20][MAXN],sum2[20][MAXN],m1[1100000],m2[1100000];

inline void merg(int x,int t,int l,int mid,int r)
{
    for(int i=l,j=mid,y=l;i<mid || j<r;y++)
    {
        if(i==mid)
        {
            v[t][y]=(v[t+1][j]);
            j++;
        }
        else if(j==r || a[v[t+1][j]]<=a[v[t+1][i]])
        {
            v[t][y]=(v[t+1][i]);
            i++;
        }
        else
        {
            v[t][y]=(v[t+1][j]);
            j++;
        }
    }
    ans[x]=ans[2*x]+ans[2*x+1];
    for(int i=l;i<mid;i++)
        sum1[t][i]=(sum1[t+1][i]+sum1[t+1][mid])%k;
    for(int i=mid;i<r;i++)
        sum1[t][i]=sum1[t+1][i];
    for(int i=l;i<mid;i++)
        sum2[t][i]=sum2[t+1][i];
    for(int i=mid;i<r;i++)
        sum2[t][i]=(sum2[t+1][i]+sum1[t+1][l])%k;
}

inline void make(int node,int l,int r,int t)
{
    if(l+1>=r)
    {
        sum1[t][l]=a[l]%k;
        sum2[t][l]=a[l]%k;
        v[t][l]=l;
        return;
    }
    int mid=(l+r)/2;
    make(2*node,l,mid,t+1);
    make(2*node+1,mid,r,t+1);
    merg(node,t,l,mid,r);
    int beg=l,en=r-1;
    for(int i=l;i<mid;i++)
        m1[sum1[t+1][i]]++;
    for(int i=mid;i<r;i++)
        m2[sum2[t+1][i]]++;
    for(int i=l;i<r;i++)
    {
        int ind=v[t][i];
        if(ind<mid)
        {
            for(;beg<=ind;beg++)
            {
                ans[node]+=m2[(k-(sum1[t+1][beg]-a[ind]%k+k)%k)%k];
                m1[sum1[t+1][beg]]--;
            }
        }
        else
        {
            for(;en>=ind;en--)
            {
                ans[node]+=m1[(k-(sum2[t+1][en]-a[ind]%k+k)%k)%k];
                m2[sum2[t+1][en]]--;
            }
        }
    }
}

int main()
{
   // ios_base::sync_with_stdio(false);
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
      //  cin>>a[i];
    make(1,0,n,0);
    printf("%lld\n",ans[1]);
//    cout<<ans[1]<<endl;
}