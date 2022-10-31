// Hydro submission #615503e09031231391c33f3c@1632961504764
#include <bits/stdc++.h>
using namespace std;
const long long maxn=400005;
long long N,cnt,sum[maxn<<2],lz[maxn<<2],cmd[maxn],l[maxn>>1],r[maxn>>1],lsh[maxn];

void pushdown(long long L,long long R,long long id){
    if(lz[id]==-1)return;
    long long M=L+R>>1;
    lz[id<<1]=lz[id<<1|1]=lz[id];
    sum[id<<1]=lz[id]*(M-L+1);
    sum[id<<1|1]=lz[id]*(R-M);
    lz[id]=-1;
}

void change(long long x,long long y,long long L,long long R,long long id,long long k){
    if(x<=L&&R<=y){
        lz[id]=k;sum[id]=(R-L+1)*k;return;
    }
    pushdown(L,R,id);
    long long M=(L+R)>>1;
    if(x<=M)change(x,y,L,M,id<<1,k);
    if(y>M)change(x,y,M+1,R,id<<1|1,k);
    sum[id]=sum[id<<1]+sum[id<<1|1];
}

void rotate(long long x,long long y,long long L,long long R,long long id){
    if(x<=L&&R<=y&&lz[id]!=-1){
        lz[id]^=1;sum[id]=R-L+1-sum[id];return;
    }
    pushdown(L,R,id);
    long long M=(L+R)>>1;
    if(x<=M)rotate(x,y,L,M,id<<1);
    if(y>M)rotate(x,y,M+1,R,id<<1|1);
    sum[id]=sum[id<<1]+sum[id<<1|1];
}

long long query(long long L,long long R,long long id){
    if(L==R)return L;
    long long M=L+R>>1;
    pushdown(L,R,id);
    if(sum[id<<1]<M-L+1)return query(L,M,id<<1);
    else return query(M+1,R,id<<1|1);
}

void build(long long L,long long R,long long id){
    if(L==R){
        lz[id]=0;
        return;
    }
    long long M=L+R>>1;
    build(L,M,id<<1);
    build(M+1,R,id<<1|1);
}

int main(){
    memset(lz,-1,sizeof(lz));
    cin>>N;
    lsh[++cnt]=1;
    for(long long i=1;i<=N;i++){
        cin>>cmd[i]>>l[i]>>r[i];
        lsh[++cnt]=l[i];lsh[++cnt]=r[i];lsh[++cnt]=r[i]+1;
    }
    sort(lsh+1,lsh+cnt+1);
    long long len=unique(lsh+1,lsh+cnt+1)-lsh-1;
    build(1,len,1);
    for(long long i=1;i<=N;i++){
        long long x=lower_bound(lsh+1,lsh+len+1,l[i])-lsh;
        long long y=lower_bound(lsh+1,lsh+len+1,r[i])-lsh;
        if(cmd[i]==1)change(x,y,1,len,1,1);
        else if(cmd[i]==2)change(x,y,1,len,1,0);
        else if(cmd[i]==3)rotate(x,y,1,len,1);
        printf("%lld\n",lsh[query(1,len,1)]);
    }
    return 0;
}