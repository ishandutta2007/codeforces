#include<bits/stdc++.h>
//#define int long long
#define maxn 44
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

string s;
int N, Q, M, ac[maxn][maxn], a[maxn][maxn], cnt[maxn][maxn][maxn][maxn], dp[maxn][maxn][maxn][maxn];
vector<pair<ii,ii> > q[maxn];

int sum(int x,int y,int w,int z){
    return ac[w][z] - ac[w][y-1] - ac[x-1][z] + ac[x-1][y-1];
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);

    cin >> N >> M >> Q;

    for(int i=1; i<=N; i++){
        cin >> s;
        for(int j=1; j<=M; j++){
            a[i][j] = s[j-1] - '0';
            ac[i][j] = ac[i-1][j] + ac[i][j-1] - ac[i-1][j-1] + a[i][j];
        }
    }

    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            for(int k=i; k>=1; k--)
                for(int l=j; l>=1; l--)
                    cnt[k][l][i][j] = cnt[k+1][l][i][j] + cnt[k][l+1][i][j] - cnt[k+1][l+1][i][j] + ( sum(k,l,i,j) == 0 );

    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            for(int k=i; k<=N; k++)
                for(int l=j; l<=M; l++)
                    dp[i][j][k][l] = dp[i][j][k][l-1] + dp[i][j][k-1][l] - dp[i][j][k-1][l-1] + cnt[i][j][k][l];

    for(int i=1; i<=Q; i++){
        int x, y, w, z;
        cin >> x >> y >> w >> z;
        cout << dp[x][y][w][z] << '\n';
    }

    return 0;
}