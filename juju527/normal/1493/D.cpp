#include<bits/stdc++.h>
using namespace std;
const int N=2e5,maxn=2e5+5,mod=1e9+7,maxp=17985,inf=0x3f3f3f3f;
int n,q;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int power(int x,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        b>>=1;
    }
    return ans;
}
bool bj[maxn];
int len;
int p[maxp],minp[maxn];
void pre(){
    for(int i=2;i<=N;i++){
        if(!bj[i])p[++len]=i,minp[i]=len;
        for(int j=1;1ll*i*p[j]<=N&&j<=len;j++){
            bj[i*p[j]]=1;
            minp[i*p[j]]=j;
            if(i%p[j]==0)break;
        }
    }
    return ;
}
multiset<int>s[maxp];
unordered_map<int,int>mp[maxp];
void modify(int k,int id,int val){
    int v=mp[k][id];
    mp[k][id]+=val;
    if(v)s[k].erase(s[k].find(v));
    s[k].insert(v+val);
    return ;
}
int main(){
    n=read();q=read();
    pre();
    int res=0;
    for(int i=1;i<=n;i++){
        int x,pre,now,c=0,P=0;
        x=read();
        res=gcd(res,x);
        while(x>1){
            if(minp[x]>P&&c)modify(P,i,c),c=0;
            P=minp[x];
            x/=p[minp[x]];c++;
        }
        if(c)modify(P,i,c);
    }
    for(int i=1;i<=q;i++){
        int id,x,pre,now,c=0,P=0;
        id=read();x=read();
        while(x>1){
            if(minp[x]>P&&c){
                pre=s[P].size()==n?*s[P].begin():0;
                modify(P,id,c);
                now=s[P].size()==n?*s[P].begin():0;
                if(now>pre)res=1ll*res*power(p[P],now-pre)%mod;
                c=0;
            }
            P=minp[x];
            x/=p[minp[x]];c++;
        }
        if(c){
            pre=s[P].size()==n?*s[P].begin():0;
            modify(P,id,c);
            now=s[P].size()==n?*s[P].begin():0;
            if(now>pre)res=1ll*res*power(p[P],now-pre)%mod;
        }
        printf("%d\n",res);
    }
    return 0;
}