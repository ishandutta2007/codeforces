#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
const int maxn=1e6+5;
int n,K;
int s[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int tot;
int t[30*maxn][2],siz[30*maxn];
void ins(int x){
    int k=0;
    siz[k]++;
    for(int i=29;i>=0;i--){
        int to=(x&(1<<i))>>i;
        if(!t[k][to])t[k][to]=++tot;
        k=t[k][to];
        siz[k]++;
    }
    return ;
}
int query(int x){
    int k=0,ans=0;
    for(int i=29;i>=0;i--){
        int to=(x&(1<<i))>>i;
        if(!(K&(1<<i))&&!to&&t[k][1])ans+=siz[t[k][1]];
        if(!(K&(1<<i))&&to&&t[k][0])ans+=siz[t[k][0]];
        to=to^((K&(1<<i))>>i);
        k=t[k][to];
        if(!k)return ans;
    }
    return ans+siz[k];
}
int main(){
    n=read();K=read();
    ll ans=0;
    ins(s[0]);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]^read();
//        cout<<s[i]<<" ";
        ans+=query(s[i]);
        ins(s[i]);
//        cout<<ans<<endl;
    }
    printf("%lld\n",ans);
    return 0;
}