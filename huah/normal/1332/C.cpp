#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];
int n,k,vis[26];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        int ans=0;
        for(int i=1,j=k;i<=j;i++,j--)
        {
            memset(vis,0,sizeof(vis));
            for(int h=i;h<=n;h+=k)
                vis[s[h]-'a']++;
            if(i!=j)
            for(int h=j;h<=n;h+=k)
                vis[s[h]-'a']++;
            int res=(n/k)+(i!=j)*(n/k);
            for(int h=0;h<26;h++)
                res=min(res,(n/k)+(i!=j)*(n/k)-vis[h]);
            ans+=res;
        }
        printf("%d\n",ans);
    }
}