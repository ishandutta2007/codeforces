#include <cstdio>

typedef long long LL;

const int MAXN=25,MOD=1000000007;

int n,ans,inv[MAXN];
LL s,f[MAXN];

inline int quick_pow(int a,int x)
{
    int ret=1;
    while (x)
    {
        if (x&1) ret=(LL)ret*a%MOD;
        a=(LL)a*a%MOD;
        x>>=1;
    }
    return ret;
}

int C(LL n,int m)
{
    n%=MOD;
    int ret=1;
    for (int i=0;i<m;i++)
        ret=ret*(n-i)%MOD*inv[i+1]%MOD;
    return ret;
}

void dfs(int x,LL sum,int c)
{
    if (sum>s) return;
    ans=(ans+c*C(s-sum+n-1,n-1))%MOD;
    for (int i=x;i<n;i++)
        dfs(i+1,sum+f[i]+1,-c);
}

int main()
{
    scanf("%d%I64d",&n,&s);
    for (int i=0;i<n;i++) scanf("%I64d",&f[i]);
    for (int i=1;i<=n;i++) inv[i]=quick_pow(i,MOD-2);
    dfs(0,0,1);
    printf("%d",(ans+MOD)%MOD);
    return 0;
}