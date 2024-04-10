#include<bits/stdc++.h>
using namespace std;

int n,m,q;
long long BtoB,AtoA,ans,a[105],b[100005],DeltaA[105],DeltaB[100005];

class Segment_Tree
{
    public:
    long long sum[400005],maxn[400005],tag[400005];
    void Update(int k)
    {
        maxn[k]=max(maxn[2*k],maxn[2*k+1]);
        sum[k]=sum[2*k]+sum[2*k+1];
    }
    void Build(int k,int L,int R)
    {
        if(L==R)
        {
            sum[k]=maxn[k]=DeltaB[L];
            return ;
        }
        int Mid=(L+R)/2;
        Build(2*k,L,Mid);
        Build(2*k+1,Mid+1,R);
        Update(k);
    }
    void Add(int k,int L,int R,long long val)
    {
        tag[k]+=val;
        maxn[k]+=val;
        sum[k]+=(R-L+1)*val;
    }
    void pushdown(int k,int L,int R)
    {
        if(!tag[k]) return ;
        int Mid=(L+R)/2;
        Add(2*k,L,Mid,tag[k]);
        Add(2*k+1,Mid+1,R,tag[k]);
        tag[k]=0;
        Update(k);
    }
    void Modify(int k,int L,int R,int QL,int QR,long long val)
    {
        if(QL>R || QR<L) return ;
        if(QL<=L && QR>=R) return Add(k,L,R,val);
        int Mid=(L+R)/2;
        pushdown(k,L,R);
        Modify(2*k,L,Mid,QL,QR,val);
        Modify(2*k+1,Mid+1,R,QL,QR,val);
        Update(k);
    }
    long long Querysum(int k,int L,int R,int QL,int QR)
    {
        if(QL>R || QR<L) return 0;
        if(QL<=L && QR>=R) return sum[k];
        int Mid=(L+R)/2;
        pushdown(k,L,R);
        return Querysum(2*k,L,Mid,QL,QR)+Querysum(2*k+1,Mid+1,R,QL,QR);
    }
    int Findval(int k,int L,int R,long long val)
    {
        if(L==R) return L;
        int Mid=(L+R)/2;
        pushdown(k,L,R);
        if(maxn[2*k]>=val) return Findval(2*k,L,Mid,val);
        else return Findval(2*k+1,Mid+1,R,val);
    }
}T;

void GetAns()
{
    long long ans=AtoA+BtoB;
//    printf("A-A = %lld B-B = %lld\n",AtoA,BtoB);
    for(int i=1;i<=n-1;i++)
    {
        int pos=T.Findval(1,1,m,DeltaA[i]);
//        printf("Delta[%d]=%lld pos=%d\n",i,DeltaA[i],pos);
        ans+=(m-pos)*DeltaA[i];
        ans+=T.Querysum(1,1,m,1,pos-1);
    }
    printf("%lld\n",ans);
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(i!=1) DeltaA[i-1]=a[i]-a[i-1];
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&b[i]);
        if(i!=1) DeltaB[i-1]=b[i]-b[i-1];
    }
    AtoA=(n+m-1)*a[1];
    for(int i=1;i<=n-1;i++) AtoA+=(n-i)*DeltaA[i];
    BtoB=(n+m-1)*b[1];
    for(int i=1;i<=m-1;i++) BtoB+=(m-i)*DeltaB[i];

    DeltaB[m]=1e13;
    T.Build(1,1,m);

    for(int i=1;i<=q;i++)
    {
        long long type,pos,val;
        scanf("%lld%lld%lld",&type,&pos,&val);
        if(type==1)
        {
            pos=n-pos+1;
            if(pos==1)
            {
                a[1]+=val;
                AtoA+=(n+m-1)*val;
                pos=2;
            }
            for(int j=pos-1;j<=n-1;j++) DeltaA[j]+=val;
            AtoA+=(n-pos+1)*(n-pos+2)/2*val;
        }
        if(type==2)
        {
            pos=m-pos+1;
            if(pos==1)
            {
                b[1]+=val;
                BtoB+=(n+m-1)*val;
                pos=2;
            }
            T.Modify(1,1,m,pos-1,m-1,val);
            BtoB+=(m-pos+1)*(m-pos+2)/2*val;
        }
        GetAns();
    }
}