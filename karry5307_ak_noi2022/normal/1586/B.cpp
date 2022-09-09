#include<cstdio>
using namespace std;
int n,m,t;
bool flag[100005]; 
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) flag[i]=false;
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            flag[b]=true;
        }
        for(int i=1;i<=n;i++)
        {
            if(flag[i]) continue;
            for(int j=1;j<=n;j++)
            {
                if(j!=i) printf("%d %d\n",i,j);
            }
            break;
        }
    }
}