#include<bits/stdc++.h>
using namespace std;
const int N=1001;
bool vis[N];
int n,a[N],id[20],b[N];
vector<int>v;
int main()
{
    for(int i=2;i*i<N;i++)
    {
        if(!vis[i]) v.push_back(i);
        for(int j=i+i;j<N;j+=i) vis[j]=true;
    }
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(id,0,sizeof(id));
        int tot=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<v.size();j++)
                if(a[i]%v[j]==0)
            {
                if(!id[j]) id[j]=++tot;
                b[i]=id[j];
                break;
            }
        printf("%d\n",tot);
        for(int i=1;i<=n;i++)
            printf(i==n?"%d\n":"%d ",b[i]);
    }
}