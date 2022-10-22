#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,base=97,mod=4999999;
char s[maxn];
int h[maxn];
bitset<1005>f[maxn];
bitset<mod>mp;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
int main(){
    int n;
    n=read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)h[i]=s[i]-'a';
    for(int i=1;i<=n;i++)f[i].set(1);
    for(int j=2;j<=1000;j++){
        bool flag=0;
        int pos=n-(j*(j-1)/2)+1,lim=(j+1)*j/2;
        if(f[pos][j-1])mp[h[pos]]=1;
        for(int i=n-lim+1;i>=1;i--){
            if(mp[h[i]]||mp[h[i+1]]){f[i].set(j);flag=1;}
            if(f[i+j-1].test(j-1))mp[h[i+j-1]]=1;
        }
        if(!flag){printf("%d\n",j-1);return 0;}
        mp.reset();
        for(int i=1;i<=n-lim+1;i++)h[i]=add(1ll*h[i]*base%mod+s[i+j-1]-'a');
    }
    puts("1000");
    return 0;
}