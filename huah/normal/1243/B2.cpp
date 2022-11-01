#include<bits/stdc++.h>
using namespace std;
const int N=55;
vector<pair<int,int> >v;
char s[N],t[N];
int vis[26];
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        v.clear();memset(vis,0,sizeof(vis));
        int n;scanf("%d",&n);
        scanf("%s%s",s+1,t+1);
        for(int i=1;i<=n;i++)
            vis[s[i]-'a']++,vis[t[i]-'a']++;
        bool flag=true;
        for(int i=0;i<26;i++) if(vis[i]&1) flag=false;
        if(!flag){printf("No\n");continue;}
        printf("Yes\n");
        for(int i=1;i<=n;i++)
            if(s[i]!=t[i])
        {
            bool f=false;
            for(int j=i+1;j<=n;j++)
            {
                if(t[j]==t[i])
                {
                    v.emplace_back(i,j);
                    swap(s[i],t[j]);
                    f=true;break;
                }
            }
            if(!f)
                for(int j=i+1;j<=n;j++)
            {
                if(s[j]==s[i])
                {
                    v.emplace_back(j,i);
                    swap(s[j],t[i]);
                    f=true;
                    break;
                }
            }
            if(!f)
            {
                for(int j=i+1;j<=n;j++)
                    if(t[j]==s[i])
                {
                    v.emplace_back(j,j);
                    swap(s[j],t[j]);
                    v.emplace_back(j,i);
                    swap(s[j],t[i]);
                    break;
                }
                else if(s[j]==t[i])
                {
                    v.emplace_back(j,j);
                    swap(s[j],t[j]);
                    v.emplace_back(i,j);
                    swap(s[i],t[j]);
                }
            }
        }
        printf("%d\n",v.size());
        for(int i=0;i<v.size();i++)
            printf("%d %d\n",v[i].first,v[i].second);
    }
}