#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=2e5+9;
int n,q;
char s[1009];
int num;
int a[19][1<<17];
int kp[19][1009];
void OR(int *dp,int o){
    for(int k=1;k<1<<17;k<<=1){
        for(int i=0;i<1<<17;i+=k<<1){
            for(int j=0;j<k;++j){
                dp[i+j+k]=(1ll*dp[i+j+k]+dp[i+j]*o%mod+mod)%mod;
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=17;++i){
        kp[i][0]=1;
        for(int j=1;j<=n;++j){
            kp[i][j]=1ll*kp[i][j-1]*i%mod;
        }
    }
    for(int i=1;i<=n;++i)if(s[i]=='?')num++;
    for(int i=1;i<=n;++i){
        int p=0,t=num;
        for(int k=1;k<=17;++k)a[k][0]=(a[k][0]+kp[k][t])%mod;
        for(int l=1;l<=n;++l){
            if(i-l<1||i+l>n)break;
            if(s[i-l]!=s[i+l]&&s[i-l]!='?'&&s[i+l]!='?')break;
            if(s[i-l]!=s[i+l]){
                if(s[i-l]!='?')p|=1<<(s[i-l]-'a');
                else p|=1<<(s[i+l]-'a');
                t--;
            }
            if(s[i-l]==s[i+l]&&s[i-l]=='?')t--;
            for(int k=1;k<=17;++k)a[k][p]=(a[k][p]+kp[k][t])%mod;
        }
        p=0,t=num;
        for(int l=i,r=i+1;l>=1&&r<=n;--l,++r){
            if(s[l]!=s[r]&&s[l]!='?'&&s[r]!='?')break;
            if(s[l]!=s[r]){
                if(s[l]!='?')p|=1<<(s[l]-'a');
                else p|=1<<(s[r]-'a');
                t--;
            }
            if(s[l]==s[r]&&s[l]=='?')t--;
            for(int k=1;k<=17;++k)a[k][p]=(a[k][p]+kp[k][t])%mod;
        }
    }
    for(int i=1;i<=17;++i)OR(a[i],1);
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        char c[19];
        scanf("%s",c);
        int len=strlen(c),p=0;
        for(int j=0;j<len;++j){
            p|=1<<(c[j]-'a');
        }
        printf("%d\n",a[__builtin_popcount(p)][p]);
    }
    return 0;
}
/*
2
??
1
a

*/