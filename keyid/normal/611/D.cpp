#include <bits/stdc++.h>
using namespace std;

const int MAXN=5005,MOD=1000000007;

char s[MAXN];
int sa[MAXN],wa[MAXN], wb[MAXN], wst[MAXN], wv[MAXN];
int maxbit,rk[MAXN], height[MAXN],rmq[MAXN][20];
int f[MAXN][MAXN],sum[MAXN][MAXN];

bool cmp(int r[], int a, int b, int l) {
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(char r[], int sa[], int n, int m) {
    int i, j, p, *x = wa, *y = wb;
    for (i = 0; i < m; ++i) wst[i] = 0;
    for (i = 0; i < n; ++i) wst[x[i]=r[i]]++;
    for (i = 1; i < m; ++i) wst[i] += wst[i-1];
    for (i = n-1; i >= 0; --i) sa[--wst[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p) {
        for (p = 0, i = n - j; i < n; ++i) y[p++] = i;
        for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < n; ++i) wv[i] = x[y[i]];
        for (i = 0; i < m; ++i) wst[i] = 0;
        for (i = 0; i < n; ++i) wst[wv[i]]++;
        for (i = 1; i < m; ++i) wst[i] += wst[i-1];
        for (i = n-1; i >= 0; --i) sa[--wst[wv[i]]] = y[i];
        for (swap(x, y), p = 1, x[sa[0]] = 0, i = 1; i < n; ++i)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
    }
}

void calheight(char r[], int sa[], int n) {
    int i, j, k = 0;
    for (i = 0; i < n; ++i) rk[sa[i]] = i;
    for (i = 0; i < n; height[rk[i++]] = k)
    {
        if (rk[i]==0)
        {
            k=0;
            continue;
        }
        for (k?k--:0, j = sa[rk[i]-1]; r[i+k] == r[j+k]; k++);
    }
}

int RMQ(int l,int r)
{
    int k=0;
    while ((1<<(k+1))<=r-l+1) k++;
    return min(rmq[l][k],rmq[r-(1<<k)+1][k]);
}

int main()
{
    int n;
    scanf("%d%s",&n,s);
    for (int i=0;i<n;i++) s[i]-='0';
    s[n]=10;
    da(s,sa,n+1,11);
//  for (int i=0;i<=n+1;i++) printf("%d ",sa[i]);puts("");
    calheight(s,sa,n+1);
    while ((1<<maxbit)<=n+1) maxbit++;
    maxbit--;
    for (int j=0;j<=n;j++) rmq[j][0]=height[j];
    for (int j=1;j<=maxbit;j++)
        for (int i=0;i+(1<<j)-1<=n;i++)
            rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]);
    for (int i=0;i<n;i++)
    {
        f[i][0]=1;
        for (int j=1;j<=i;j++)
        {
            if (s[j]==0) continue;
            int d=j-1-(i-j);
            if (d<0) f[i][j]=sum[j-1][0];
            else
            {
                if (rk[d]<rk[j]&&RMQ(rk[d]+1,rk[j])<=i-j)
                {
                    f[i][j]=sum[j-1][d];
                    //printf("%d %d %d %d\n",d,j-1,j,i);
                }
                else 
                {
                    f[i][j]=sum[j-1][d+1];
                    //printf("%d %d %d %d\n",d,j-1,j,i);
                }
            }
        }
        for (int j=i;j>=0;j--) sum[i][j]=(sum[i][j+1]+f[i][j])%MOD;
    }
    int ans=0;
    for (int j=0;j<n;j++) ans=(ans+f[n-1][j])%MOD;
    printf("%d",ans);
    return 0;
}