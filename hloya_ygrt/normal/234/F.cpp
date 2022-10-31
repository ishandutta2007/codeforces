#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct tr
{
    int i,j,k;
    tr(){}

    tr(int _i,int _j,int _k){
        i=_i;
        j=_j;
        k=_k;
    }

    bool operator == (const tr &x) const
    {
        return i==x.i&&j==x.j&&k==x.k;
    }

    bool operator !=(const tr &x)const
    {

        return i!=x.i||j!=x.j||k!=x.k;

    }
};
    const int maxn =4e4+5,inf = 2e9;
    int dp[ 202 ][ maxn ] [ 2 ];
    tr parent[ 202 ][ maxn ] [ 2 ];
    int h[202], pref[202];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,a,b;
    scanf("%d",&n);
    scanf("%d %d",&a,&b);
    for (int i=0;i<n;i++)
        scanf("%d",h+i);

    pref[0] = h[0];
    int sum = 0;
    sum+=h[0];
    for (int i=1;i<n;i++){
        sum += h[i];
        pref[i] = pref[i-1] + h[i];
    }

    for (int i=0;i<=200;i++)
    for (int j=0;j<maxn;j++)
    for (int k=0;k<2;k++){
        dp[i][j][k] = inf;
        parent[i][j][k] = tr(i,j,k);
    }
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for (int pos = 0; pos < n; pos++)
        for (int litr_a=0;litr_a <= a;litr_a++)
            for (int last = 0;last<=1;last++){
                if (pos)
                if (pref[pos-1] - litr_a > b)
                    continue;
                int need = h[pos];
                int len = 0;
                if (pos)
                    len = min(h[pos-1],h[pos]);

                if (litr_a+need <= a){
                    int change = last;

                    int ls =dp[pos+1][need + litr_a][ 0 ];
                    int rs = dp[ pos ][ litr_a ][ last ] + change*len;

                    if (rs < ls){
                        dp[pos+1][need + litr_a][ 0 ] = rs;
                        parent[pos+1][ need + litr_a ][ 0 ] = tr(pos,litr_a,last);
                    }
                }
                int litr_b = 0;
             //   if (pos)
                    litr_b = pref[pos] - litr_a;

                if (litr_b<=b){
                    int change = last^1;
                    int ls = dp[pos+1][litr_a][ 1 ];
                    int rs =dp[pos][litr_a][last] + change*len;

                    if (rs < ls){
                        dp[pos+1][litr_a][ 1 ] = rs;
                        parent[pos+1][litr_a][1] = tr(pos,litr_a,last);
                    }
                }
            }
    int ans = inf;
    int pos = n;
    for (int litr_a=0;litr_a<=a;litr_a++)
        for (int last=0;last<=1;last++)
            {
                if (sum - litr_a <= b)
                    {
                        ans = min(ans,dp[pos][litr_a][last]);
                       // if (ans == 0){
//cout<<sum<<endl;
                      //      return 0;
                   //     }
                    }
            }
    if (ans == inf)
        ans=-1;
    cout<<ans;
    return 0;
}