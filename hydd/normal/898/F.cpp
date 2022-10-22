#include<bits/stdc++.h>
using namespace std;
int n; char s[2100000];
struct T{
    int Mod,pw[2100000],hs[2100000];
    void init(){
        pw[0]=1; hs[0]=0;
        for (int i=1;i<=n;i++){
            pw[i]=10ll*pw[i-1]%Mod;
            hs[i]=(10ll*hs[i-1]+s[i]-'0')%Mod;
        }
    }
    int getnum(int l,int r){
        return (hs[r]-1ll*hs[l]*pw[r-l]%Mod+Mod)%Mod;
    }
    bool check(int a,int b){
        if (a<=0||b<=a||n<=b) return 0;
        if (a>1&&s[1]=='0'||b>a+1&&s[a+1]=='0'||n>b+1&&s[b+1]=='0') return 0;
        return (getnum(0,a)+getnum(a,b))%Mod==getnum(b,n);
    }
} T1,T2;
int main(){
    scanf("%s",s+1); n=strlen(s+1);
    T1.Mod=1e9+9; T1.init();
    T2.Mod=998244853; T2.init();
    for (int len=0;len<=n;len++)
        for (int j=0;j<=1;j++){
            if (T1.check(len-j,n-len)&&T2.check(len-j,n-len)){
                for (int i=1;i<=len-j;i++) putchar(s[i]); putchar('+');
                for (int i=len-j+1;i<=n-len;i++) putchar(s[i]); putchar('=');
                for (int i=n-len+1;i<=n;i++) putchar(s[i]);
                return 0;
            }
            if (T1.check(n-(len<<1)+j,n-len)&&T2.check(n-(len<<1)+j,n-len)){
                for (int i=1;i<=n-(len<<1)+j;i++) putchar(s[i]); putchar('+');
                for (int i=n-(len<<1)+j+1;i<=n-len;i++) putchar(s[i]); putchar('=');
                for (int i=n-len+1;i<=n;i++) putchar(s[i]);
                return 0;
            }
        }
    return 0;
}