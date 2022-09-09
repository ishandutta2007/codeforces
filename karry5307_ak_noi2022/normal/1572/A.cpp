#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n,t,a[200005],In[200005];
vector<int> To[200005];
set<int> Q,Nxt;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            To[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&In[i]);
            for(int j=1;j<=In[i];j++)
            {
                int x;
                scanf("%d",&x);
                To[x].push_back(i);
            }
            if(In[i]==0) Nxt.insert(i);
        }
        int turns=0,cnt=0;
        while(!Nxt.empty())
        {
            Q=Nxt;
            Nxt.clear();
            while(!Q.empty())
            {
                cnt++;
                int tmp=*Q.begin();
                Q.erase(Q.begin());
                for(auto &p : To[tmp])
                {
                    In[p]--;
                    if(In[p]) continue;
                    if(p>tmp) Q.insert(p);
                    else Nxt.insert(p);
                }
            }
            turns++;
        }
        if(cnt==n) 
        {
            printf("%d\n",turns);
        }
        else
        {
            printf("-1\n");
        }
    }
}