#include<bits/stdc++.h>
using namespace std;
const int N=10005;
vector<pair<int,int> >v;
char s[N],t[N];
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n;scanf("%d",&n);
        scanf("%s%s",s+1,t+1);
        for(int i=1;i<=n;i++)
            if(s[i]!=t[i])
        {
            for(int j=i+1;j<=n;j++)
            if(t[j]==t[i]&&s[j]==s[i])
            {
                swap(s[i],t[j]);break;
            }
            break;
        }
        bool flag=true;
        for(int i=1;i<=n;i++) if(s[i]!=t[i]) flag=false;
        printf(flag?"Yes\n":"No\n");
    }
}