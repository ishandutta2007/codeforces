#include <bits/stdc++.h>

const int maxn = 1e3+5,inf = 2e9;
using namespace std;
int to1[maxn],to0[maxn];
    int dp[maxn][maxn][2];

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
    tr par[maxn][maxn][2];
int main()
{
    //freopen("input.txt","r",stdin);
    int n,m,x,y;
    scanf("%d %d %d %d",&n,&m,&x,&y);

    memset(to1,0,sizeof(to1));
    memset(to0,0,sizeof(to0));

    for (int i=0;i<n;i++){
        scanf("%*c");
    for (int j=0;j<m;j++){
        char x;
        scanf("%c",&x);
        if (x=='.')
            to1[j]++;
        else
            to0[j]++;
        }
    }

    for (int i=0;i<maxn;i++)
    for (int j=0;j<maxn;j++)
    for (int k=0;k<2;k++){
        dp[i][j][k] = inf;
        par[i][j][k] = tr(i,j,k);
    }
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;

    for (int pos = 0; pos < m ;pos++)
        for (int len = 0; len <= y; len++ )
            for (int lclr = 0;lclr<=1;lclr++){
                if (len>=x&&len!=0){
                    int cost;
                    if (lclr==0)
                        cost = to1[pos];
                    else
                        cost = to0[pos];
                    int ls = dp[pos+1][1][lclr^1];
                    int rs = dp[pos][len][lclr] + cost;
                    if (rs < ls){
                        dp[pos+1][1][lclr^1] = rs;
                        par[pos+1][1][lclr^1] = tr(pos,len,lclr);
                    }
                }
                if (pos&&len==0)
                    continue;
                int cost;
                    if (lclr==0)
                        cost = to0[pos];
                    else
                        cost = to1[pos];
                int ls =dp[pos+1][len+1][lclr];
                int rs =dp[pos][len][lclr] + cost;
                if (rs < ls){
                    dp[pos+1][len+1][lclr] = rs;
                    par[pos+1][len+1][lclr] = tr(pos,len,lclr);
                }
    }
    int ans = inf;
    int pos = m;
    for (int len = x;len<=y;len++)
    for (int clr=0;clr<=1;clr++)
        {
            ans = min(ans, dp[pos][len][clr]);
            /*if (ans==2){
                int i = n, j = len, k = clr;
                while (par[i][j][k]!=tr(i,j,k)){
                    cout<<i<<' '<<j<<' '<<k<<endl;
                    tr x= par[i][j][k];
                    i = x.i;
                    j = x.j;
                    k = x.k;
                }
                cout<<i<<' '<<j<<' '<<k;
                return 0;
            }*/
        }
    cout<<ans;
    return 0;
}