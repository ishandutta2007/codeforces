#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n,t,tot,cnt;
char s[15][205];
int len[15],pos[15][205][2],dp[205][(1<<10)+5];
pair<int,int> From[205][(1<<10)+5];
struct query
{
    int ch;
    int Mask;
    int sumpos;
}Q[100005];
bool cmp(query x,query y)
{
    return x.sumpos<y.sumpos;
}

int Nxt(int x,int p,int ch)
{
    if(pos[x][ch][0]>p) return 0;
    if(pos[x][ch][1]>p) return 1;
    return -1;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        memset(pos,0,sizeof(pos));
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        tot=(1<<n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s[i]+1);
            len[i]=strlen(s[i]+1);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=len[i];j++)
            {
                if(!pos[i][s[i][j]][0]) pos[i][s[i][j]][0]=j;
                else pos[i][s[i][j]][1]=j;
            }
        }
        for(int i=1;i<=200;i++)
        {
            if((i<'a' || i>'z') && (i<'A' || i>'Z')) continue;
            for(int j=0;j<tot;j++)
            {
                int sumpos=0;
                bool flag=true;
                for(int k=1;k<=n;k++)
                {
                    int tmp=(j & (1<<(k-1))) ? 1 : 0;
                    if(!pos[k][i][tmp]) 
                    {
                        flag=false;
                        break;
                    }
                    sumpos+=pos[k][i][tmp];
                }
                if(flag)
                {
                    Q[++cnt]=(query){i,j,sumpos};
                }
            }
        }
        sort(Q+1,Q+cnt+1,cmp);
        int Maxch=0,MaxMask=0,Maxn=0;
        for(int i=1;i<=cnt;i++)
        {
//            printf("DP : %d %c %d\n",i,Q[i].ch,Q[i].Mask);
            if(dp[Q[i].ch][Q[i].Mask]==0)
            {
                From[Q[i].ch][Q[i].Mask]=make_pair(0,0);
                dp[Q[i].ch][Q[i].Mask]=1;
            }
            if(dp[Q[i].ch][Q[i].Mask]>Maxn)
            {
                Maxn=dp[Q[i].ch][Q[i].Mask];
                Maxch=Q[i].ch;
                MaxMask=Q[i].Mask;
            }
            for(int j=1;j<=200;j++)
            {
                if((j<'a' || j>'z') && (j<'A' || j>'Z')) continue;
                int NxtMask=0;
                bool flag=true;
                for(int k=1;k<=n;k++)
                {
                    int NowPos=(Q[i].Mask & (1<<(k-1))) ? pos[k][Q[i].ch][1] : pos[k][Q[i].ch][0];
                    int NxtP=Nxt(k,NowPos,j);
                    if(NxtP==-1)
                    {
                        flag=false;
                        break;
                    }
                    NxtMask+=NxtP*(1<<(k-1));
                }
                if(flag)
                {
//                    printf("dp(%d,%d)->(%d,%d)\n",Q[i].ch,Q[i].Mask,j,NxtMask);
                    if(dp[j][NxtMask]>=dp[Q[i].ch][Q[i].Mask]+1) continue;
                    From[j][NxtMask]=make_pair(Q[i].ch,Q[i].Mask);
                    dp[j][NxtMask]=dp[Q[i].ch][Q[i].Mask]+1;
                }
            }
        }
        vector<int> Ans;
        while(Maxch!=0)
        {
            Ans.push_back(Maxch);
            auto tmp=From[Maxch][MaxMask];
            Maxch=tmp.first;
            MaxMask=tmp.second;
        }
        printf("%d\n",Ans.size());
        for(int i=Ans.size()-1;i>=0;i--)
        {
            printf("%c",Ans[i]);
        }
        printf("\n");
    }
}