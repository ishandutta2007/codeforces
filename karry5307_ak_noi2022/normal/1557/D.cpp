#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,lst[300005],b[300005],tot,dp[300005];
struct M
{
    int pos,L,R;
}F[300005];
bool cmp(M a,M b)
{
    return a.pos<b.pos;
}
int Dmax(int x,int y)
{
    return dp[x]>dp[y] ? x : y;
}
class Segment_Tree
{
    public:
    int Data[2400005],Tag[2400005];
    void Update(int k)
    {
        Data[k]=Dmax(Data[2*k],Data[2*k+1]);
    }
    void Add(int k,int val)
    {
        Data[k]=Dmax(Data[k],val);
        Tag[k]=Dmax(Tag[k],val);
    }
    void Pushdown(int k)
    {
        Add(2*k,Tag[k]);
        Add(2*k+1,Tag[k]);
    }
    void Modify(int k,int L,int R,int QL,int QR,int val)
    {
        if(QL>R || QR<L) return;
        if(QL<=L && QR>=R) return Add(k,val);
        Pushdown(k);
        int Mid=(L+R)/2;
        Modify(2*k,L,Mid,QL,QR,val);
        Modify(2*k+1,Mid+1,R,QL,QR,val);
        Update(k);
    }
    int Query(int k,int L,int R,int QL,int QR)
    {
        if(QL>R || QR<L) return 0;
        if(QL<=L && QR>=R) return Data[k];
        int Mid=(L+R)/2;
        Pushdown(k);
        return Dmax(Query(2*k,L,Mid,QL,QR),Query(2*k+1,Mid+1,R,QL,QR));
    }
}S;
bool flag[300005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&F[i].pos,&F[i].L,&F[i].R);
        b[++tot]=F[i].L;
        b[++tot]=F[i].R;
    }
    sort(b+1,b+tot+1);
    tot=unique(b+1,b+tot+1)-b-1;
    for(int i=1;i<=m;i++)
    {
        F[i].L=lower_bound(b+1,b+tot+1,F[i].L)-b;
        F[i].R=lower_bound(b+1,b+tot+1,F[i].R)-b;
        // printf("L=%d R=%d\n",F[i].L,F[i].R);
    }
    sort(F+1,F+m+1,cmp);
    int Now=1,Pre=1;
    for(int i=1;i<=n;i++)
    {
        int NowAns=0;
        while(F[Now].pos==i)
        {
            // printf("query %d %d = %d\n",F[Now].L,F[Now].R,S.Query(1,1,tot,F[Now].L,F[Now].R));
            NowAns=Dmax(NowAns,S.Query(1,1,tot,F[Now].L,F[Now].R));
            Now++;
        }
        lst[i]=NowAns;
        dp[i]=dp[NowAns]+1;
        while(F[Pre].pos==i)
        {
            // printf("add %d %d %d\n",F[Pre].L,F[Pre].R,i);
            S.Modify(1,1,tot,F[Pre].L,F[Pre].R,i);
            Pre++;
        }
    }
    // for(int i=1;i<=n;i++) printf("dp[%d]=%d\n",i,dp[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]>dp[ans]) ans=i;
    }
    int cnt=0;
    while(ans!=0)
    {
        flag[ans]=true;
        ans=lst[ans];
        cnt++;
    }
    printf("%d\n",n-cnt);
    for(int i=1;i<=n;i++)
    {
        if(!flag[i]) printf("%d ",i);
    }
    printf("\n");
}