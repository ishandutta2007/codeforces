#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=100010,maxm=0,mod=1e9+7;
int n,a[maxn],ord[maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
bool cmp(int x,int y){
    return a[x]>a[y];
}
int qpow(int x,int k){
    int res=1;
    while(k){
        if(k&1)res=1ll*res*x%mod;
        x=1ll*x*x%mod;
        k>>=1;
    }
    return res;
}
void proc(){
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i)ord[i]=i;
    sort(ord+1,ord+1+n,cmp);
    for(int i=1,j;i<=n;){
        j=i;
        while(j<=n&&a[ord[i]]==a[ord[j]])++j;
        --j;
        int cnt0=0,cnt1=0;
        for(int k=i;k<=j;++k)
            if((n-k+1)%2==0)++cnt0;
            else ++cnt1;
        for(int k=i;k<=j;++k){
            if(ord[k]%2==0){
                --cnt0;
                if(cnt0<0){
                    puts("NO");return;
                }
            }
            else{
                --cnt1;
                if(cnt1<0){
                    puts("NO");return;
                }
            }
        }
        i=j+1;
    }
    puts("YES");
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}