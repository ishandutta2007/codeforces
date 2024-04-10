#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,a[110000],f[2][110000],s[110000];
int m,b[110000];
inline int add(int x,int y){ return (x+y>=Mod?x+y-Mod:x+y);}
int main(){
//    freopen("record.in","r",stdin);
//    freopen("record.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int pos=1;
    while (pos<=n){
        for (int i=pos;i<=pos+a[pos]-1;i++){
            if (a[i]!=a[pos]){
                puts("0");
                return 0;
            }
        }
        b[++m]=a[pos]; pos+=a[pos];
    }
    s[0]=1; f[0][0]=1; int now=0;
    for (int i=1;i<=m;i++){// 1..i intervals
        now^=1; f[now][0]=0;
        for (int j=i;j>=1;j--){// number of segments
            f[now][j]=add(s[j-1],s[j-1]);// f[k][j-1]   k+1..i is a segment
            if (b[i]==1) f[now][j]=add(f[now][j],Mod-f[now^1][j-1]);
            s[j]=add(s[j],f[now][j]);
        }
    }
    int mul=1,ans=0;
    for (int j=1;j<=m;j++){
        mul=1ll*mul*j%Mod;
        if ((m-j)&1) ans=(ans+1ll*(Mod-f[now][j])*mul)%Mod;
        else ans=(ans+1ll*f[now][j]*mul)%Mod;
    }
    printf("%d\n",ans);
    return 0;
}