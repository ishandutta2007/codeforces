#include<cstdio>
#include<vector>
using namespace std;
int n,m,q;
int flag[1000005];
vector<vector<int> > vec;
int main()
{
    scanf("%d%d",&n,&m);
    vec.resize(n+5);
    for(int i=0;i<=n;i++) vec[i].resize(m+5);
    for(int i=1;i<=n;i++)
    {   
        for(int j=1;j<=m;j++)
        {
            char tmp;
            scanf(" %c",&tmp);
            if(tmp=='.') vec[i][j]=0;
            else vec[i][j]=1;
            if(vec[i][j-1] && vec[i-1][j]) flag[j-1]=1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        flag[i]+=flag[i-1];
    }
    scanf("%d",&q);
    while(q--)
    {
        int L,R;
        scanf("%d%d",&L,&R);
        if(flag[L-1]==flag[R-1]) printf("YES\n");
        else printf("NO\n");
    }
}