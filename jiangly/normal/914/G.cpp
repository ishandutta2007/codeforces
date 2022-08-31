#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
const int INV2=(MOD+1)>>1;
const int MAX_N=1000000;
const int MAX_S=1<<17;
int n;
int s[MAX_N];
int f[MAX_S];
int a[MAX_S][18];
int b[MAX_S];
int c[MAX_S];
int d[MAX_S];
void FMTOr(int a[][18],int n){
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;i+=k<<1){
            for(int j=i;j<i+k;++j){
                for(int l=0;l<=17;++l){
                    a[j|k][l]=(a[j|k][l]+a[j][l])%MOD;
                }
            }
        }
    }
}
void IFMTOr(int a[][18],int n){
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;i+=k<<1){
            for(int j=i;j<i+k;++j){
                for(int l=0;l<=17;++l){
                    a[j|k][l]=(a[j|k][l]-a[j][l]+MOD)%MOD;
                }
            }
        }
    }
}
void FMTAnd(int a[],int n){
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;i+=k<<1){
            for(int j=i;j<i+k;++j){
                a[j]=(a[j|k]+a[j])%MOD;
            }
        }
    }
}
void IFMTAnd(int a[],int n){
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;i+=k<<1){
            for(int j=i;j<i+k;++j){
                a[j]=(a[j]-a[j|k]+MOD)%MOD;
            }
        }
    }
}
void FWT(int a[],int n){
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;i+=k<<1){
            for(int j=i;j<i+k;++j){
                int u=a[j];
                int v=a[j|k];
                a[j]=(u+v)%MOD;
                a[j|k]=(u-v+MOD)%MOD;
            }
        }
    }
}
void IFWT(int a[],int n){
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;i+=k<<1){
            for(int j=i;j<i+k;++j){
                int u=a[j];
                int v=a[j|k];
                a[j]=1ll*(u+v)*INV2%MOD;
                a[j|k]=1ll*(u-v+MOD)*INV2%MOD;
            }
        }
    }
}
int main(){
    f[0]=0;
    f[1]=1;
    for(int i=2;i<MAX_S;++i){
        f[i]=(f[i-1]+f[i-2])%MOD;
    }
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&s[i]);
        ++a[s[i]][__builtin_popcount(s[i])];
        ++b[s[i]];
        ++c[s[i]];
    }
    FMTOr(a,MAX_S);
    for(int i=0;i<MAX_S;++i){
        for(int j=17;j>=0;--j){
            int tmp=0;
            for(int k=0;k<=j;++k){
                tmp=(tmp+1ll*a[i][j-k]*a[i][k])%MOD;
            }
            a[i][j]=tmp;
        }
    }
    IFMTOr(a,MAX_S);
    for(int i=0;i<MAX_S;++i){
        d[i]=a[i][__builtin_popcount(i)];
    }
    FWT(c,MAX_S);
    for(int i=0;i<MAX_S;++i){
        c[i]=1ll*c[i]*c[i]%MOD;
    }
    IFWT(c,MAX_S);
    for(int i=0;i<MAX_S;++i){
        b[i]=1ll*b[i]*f[i]%MOD;
        c[i]=1ll*c[i]*f[i]%MOD;
        d[i]=1ll*d[i]*f[i]%MOD;
    }
    FMTAnd(b,MAX_S);
    FMTAnd(c,MAX_S);
    FMTAnd(d,MAX_S);
    for(int i=0;i<MAX_S;++i){
        b[i]=1ll*b[i]*c[i]%MOD*d[i]%MOD;
    }
    IFMTAnd(b,MAX_S);
    int ans=0;
    for(int i=1;i<MAX_S;i<<=1){
        ans=(ans+b[i])%MOD;
    }
    printf("%d\n",ans);
    return 0;
}