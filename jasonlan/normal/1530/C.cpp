#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<bitset>
using namespace std;
const int maxn=1e5+5,maxm=0,mod=0;
int n,m;
int a[maxn],b[maxn];
inline int read(){
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
int qmod(int x){
    return x>=mod?x-mod:x;
}
int qdec(int x){
    return x<0?x+mod:x;
}
bool Check(int p){
    int lim=n+p-((n+p)/4);
    long long ans1=0,ans2=0;
    for(int i=1;i<=lim;++i)
        if(n+p-i+1>n)ans1+=100;
        else ans1+=a[n+p-i+1];
    for(int i=1;i<=lim;++i){
        if(n-i+1==0)break;
        ans2+=b[n-i+1];
    }
    return ans1>=ans2;
}
void proc(){
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i)b[i]=read();
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int l=0,r=8e5,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(Check(mid))r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}