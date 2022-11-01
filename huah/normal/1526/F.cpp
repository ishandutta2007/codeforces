#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int p[]={0,9,10,19,7,16,18,11,14,15,6,20,8,17,4,5,3,12,2,13,1};
int query(int a,int b,int c)
{
    printf("? %d %d %d\n",a,b,c);
    /*
    if(p[a]>p[b]) swap(a,b);
    if(p[b]>p[c]) swap(b,c);
    if(p[a]>p[b]) swap(a,b);
    return max(p[b]-p[a],p[c]-p[b]);
    */
    fflush(stdout);
    int ans;scanf("%d",&ans);
    return ans;
}
int n,mx,arr[N];
vector<int>v[N];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++) v[i].clear();
        mx=0;
        int a=0,b;
        for(int i=1;i<=13;i++)
            for(int j=i+1;j<=13;j++)
            for(int k=j+1;k<=13;k++)
            if(query(i,j,k)<=(n-4)/6)
            a=i,b=j;
        assert(a!=0);
        for(int i=1;i<=n;i++)
            if(i!=a&&i!=b)
        {
            int s=query(a,b,i);
            mx=max(mx,s);
            v[s].push_back(i);
        }
        int s1=v[mx][0];
        int s2=v[mx-1][0];
        if(v[mx-1].size()>=2&&query(s1,v[mx-1][0],a)>query(s1,v[mx-1][1],a))
            s2=v[mx-1][1];
        arr[s1]=1;arr[s2]=2;
        for(int i=1;i<=n;i++)
            if(i!=s1&&i!=s2) arr[i]=query(s1,s2,i)+2;
        if(arr[1]>arr[2])
            for(int i=1;i<=n;i++) arr[i]=n-arr[i]+1;
        printf("! ");
        for(int i=1;i<=n;i++) printf(i==n?"%d\n":"%d ",arr[i]);
        fflush(stdout);
        int x;scanf("%d",&x);
    }
}