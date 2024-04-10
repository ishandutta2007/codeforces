#include<bits/stdc++.h>
using namespace std;
int n,a,b,sum;
vector<int>v;
bool vis[400005];
queue<int>q;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x==1) a++;
        else b++;
        sum+=x;
    }
    int now=0;
    for(int i=2;i<=sum;i++)
    {
        if(!vis[i])
        {
            v.push_back(i);
            for(int j=i;j<=sum;j+=i)
                vis[j]=true;
        }
    }
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        int t=v[i]-now;
        if(t%2==1&&a>0)
        {
            a--,t--,now++,ans++;
            q.push(1);
            if(b>=t/2)
            {
                for(int j=1;j<=t/2;j++)
                    q.push(2);
                b-=t/2,t=0;
            }
            else
            {

                t-=2*b;
                for(int j=1;j<=b;j++)
                    q.push(2);
                b=0;
                a-=t;
                for(int j=1;j<=t;j++)
                    q.push(1);
                t=0;
            }
            now=v[i];
        }
        else if(t%2==0)
        {
            ans++;
            if(b>=t/2)
            {
                for(int j=1;j<=t/2;j++)
                    q.push(2);
                b-=t/2,t=0;

            }else
            {
              t-=2*b;

              for(int j=1;j<=b;j++)
                    q.push(2);b=0;
                    for(int j=1;j<=t;j++)
                    q.push(1);
                    a-=t,t=0;
            }
            now=v[i];
        }
    }
    while(a>0) q.push(1),a--;
    while(b>0) q.push(2),b--;
    while(!q.empty())
    {
        printf("%d ",q.front());q.pop();
    }
}