#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,q;
int cnt[N],tp[N],a[N],ans[N];
long long sm[N],k[N];
vector<int>s[N];
int lb(int x){
    return x&-x;
}
void add(int x,int y){
    for(;x<=n;x+=lb(x))
        a[x]+=y;
}
int qry(int k){
    --k;
    int x=0;
    for(int i=1<<20;i;i>>=1)
        if(x+i<=n&&a[x+i]<=k){
            x+=i;
            k-=a[x];
        }
    return x+1;
}
int main(){
    scanf("%d%d%d",&m,&n,&q);
    for(int i=1;i<=m;++i){
        int x;
        scanf("%d",&x);
        s[++cnt[x]].push_back(x);
        ++sm[cnt[x]];
    }
    for(int i=1;i<=m;++i)
        sm[i]=sm[i-1]+n-sm[i];
    for(int i=1;i<=q;++i)
        scanf("%I64d",&k[i]);
    for(int i=1;i<=q;++i)
        tp[i]=i;
    sort(tp+1,tp+q+1,[](int i,int j){return k[i]<k[j];});
    for(int i=1;i<=n;++i)
        if(!cnt[i])
            add(i,1);
    for(int i=1,j=1;i<=q;++i){
        long long x=k[tp[i]]-m;
        for(;j<=m&&x>sm[j];++j){
            for(auto k:s[j])
                add(k,1);
            for(auto k:s[j+1])
                add(k,-1);
        }
        x-=sm[j-1];
        x=(x-1)%n+1;
        ans[tp[i]]=qry(x);
    }
    for(int i=1;i<=q;++i)
        printf("%d\n",ans[i]);
    return 0;
}