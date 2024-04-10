#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 440;
const ll INF = 1E18+7;
const ll base = 26;
const ll MOD = 998244353;

ll res = 0,n;

void solve(){
    ll prev = 26*26;
    for(ll i = 3;i<=n;++i){
        prev = (prev*25)%MOD;
    }
    res = prev;
}
ll dp[2][DIM][2][2],A[DIM];
void solve1(){
    for(ll cv = 0;cv<=n;++cv){
        for(ll a = 0;a<2;++a){
            for(ll b = 0;b<2;++b){
                dp[0][cv][a][b] = 0;
                dp[1][cv][a][b] = 0;
            }
        }
    }
    for(ll a = 0;a<2;++a){
        for(ll b = 0;b<2;++b){
            ll val = 1;
            if (a)val*=25ll;
            if (b)val*=25ll;
            dp[0][a+b][a][b] = val%MOD;
        }
    }
    for(ll i = 3;i<=n;++i){
        for(ll cv = 0;cv<=n;++cv){
            for(ll cur = 0;cur<2;++cur)
                for(ll p1 = 0;p1<2;++p1)
                    for(ll p2 = 0;p2<2;++p2){
                        if (cur!=0 && cur==p2)continue;

                        if (cur==0){
                            if (p2==0)
                                dp[1][cv+cur][cur][p1] = (dp[1][cv+cur][cur][p1]+24ll*dp[0][cv][p1][p2])%MOD;
                            else
                                dp[1][cv+cur][cur][p1] = (dp[1][cv+cur][cur][p1]+25ll*dp[0][cv][p1][p2])%MOD;
                        }
                        else
                            dp[1][cv+1][cur][p1] = (dp[1][cv+1][cur][p1]+dp[0][cv][p1][p2])%MOD;
                    }
        }
        for(ll cv = 0;cv<=n;++cv){
            for(ll a = 0;a<2;++a){
                for(ll b = 0;b<2;++b){
                    dp[0][cv][a][b] = dp[1][cv][a][b];
                    dp[1][cv][a][b] = 0;
                }
            }
        }
    }
    for(ll sy = 1;sy<=base;++sy){
        for(ll i = A[sy]+1;i<=n;++i){
            for(ll a = 0;a<2;++a){
                for(ll b = 0;b<2;++b){
                    res = (res+MOD-dp[0][i][a][b])%MOD;
                }
            }
        }
    }
}
#define dp dp1
ll dp[2][DIM][DIM][3][3],S[DIM][DIM];
void solve2(){
    for(ll a = 0;a<3;++a){
        for(ll b = 0;b<3;++b){
            ll n1 = (a==1)+(b==1);
            ll n2 = (a==2)+(b==2);
            ll val = 1;
            if (a==0)val*=24;
            if (b==0)val*=24;
            dp[0][n1][n2][a][b]+=val;
        }
    }
    for(ll i = 3;i<=n;++i){
        for(ll c1 = 0;c1<=n;++c1)
            for(ll c2 = 0;c2<=n;++c2)
                for(ll last = 0;last<3;++last)
                    for(ll a = 0;a<3;++a)
                        for(ll b = 0;b<3;++b){
                            if (last!=0 && last==b)continue;
                            ll n1 = c1+(last==1),n2 = c2+(last==2);
                            if (last==0){
                                if (b==0)
                                    dp[1][n1][n2][last][a] = (dp[1][n1][n2][last][a]+dp[0][c1][c2][a][b]*23ll)%MOD;
                                else
                                    dp[1][n1][n2][last][a] = (dp[1][n1][n2][last][a]+dp[0][c1][c2][a][b]*24ll)%MOD;

                            }
                            else
                                dp[1][n1][n2][last][a] = (dp[1][n1][n2][last][a]+dp[0][c1][c2][a][b])%MOD;
                        }
        swap(dp[0],dp[1]);
        memset(dp[1],0,sizeof(dp[1]));
    }
    for(ll c1 = 0;c1<=n;++c1){
        for(ll c2 = 0;c2<=n;++c2){
            for(ll a = 0;a<3;++a){
                for(ll b = 0;b<3;++b){
                    S[c1][c2] = (S[c1][c2]+dp[0][c1][c2][a][b])%MOD;
                }
            }
        }
    }
    for(ll c1 = n;c1>=0;--c1){
        for(ll c2 = n;c2>=0;--c2){
            S[c1][c2] = (S[c1][c2]+S[c1+1][c2]+S[c1][c2+1]-S[c1+1][c2+1])%MOD;
        }
    }
    for(ll s1 = 1;s1<base;++s1){
        for(ll s2 = s1+1;s2<=base;++s2)
            res = (res+S[A[s1]+1][A[s2]+1])%MOD;
    }
}
const int N=410;
//const int A=1000001;
const ll mod=998244353;
#define dp dsgds
#define dp1 sdfdsfds
ll dp[N][N][2][2];

ll dp1[2][N][N][3][3];
int c[27];

void ss(){
    //ll res=26ll*26ll;

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            int cn=(i==1)+(j==1);
            dp[2][cn][i][j]=1ll;
            for (int t=1;t<=2-cn;t++){
                dp[2][cn][i][j]*=25ll;
                dp[2][cn][i][j]%=mod;
            }
        }
    }
    for (int i=2;i<n;i++){
        for (int j=0;j<=i;j++){
            for (int x=0;x<2;x++){
                for (int y=0;y<2;y++){
//                    cout<<"OK\n";
                    if (!x){
                        dp[i+1][j+1][y][1]=(dp[i+1][j+1][y][1]+dp[i][j][x][y])%mod;
                    }
                    dp[i+1][j][y][0]=(dp[i+1][j][y][0]+dp[i][j][x][y]*(24ll+x))%mod;
                }
            }
        }
    }
    for (int i=1;i<=26;i++){
        for (int j=c[i]+1;j<=n;j++){
            ll sum=0ll;
            for (int x=0;x<2;x++){
                for (int y=0;y<2;y++){
                    sum+=dp[n][j][x][y];
                    res+=mod-dp[n][j][x][y];
                    res%=mod;
                }
            }
        }
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            int cn1=(i==1)+(j==1);
            int cn2=(i==2)+(j==2);
            dp1[0][cn1][cn2][i][j]=1ll;
            for (int t=1;t<=2-cn1-cn2;t++){
                dp1[0][cn1][cn2][i][j]*=24ll;
                dp1[0][cn1][cn2][i][j]%=mod;
            }
        }
    }
    for (int i=2;i<n;i++){
        for (int j=0;j<=i;j++){
            for (int t=0;t+j<=i;t++){
                for (int x=0;x<3;x++){
                    for (int y=0;y<3;y++){
                        dp1[(i+1)%2][j][t][x][y]=0ll;
                    }
                }
            }
        }
        for (int j=0;j<=i;j++){
            for (int t=0;t+j<=i;t++){
                for (int x=0;x<3;x++){
                    for (int y=0;y<3;y++){
                        if (x!=1){
                            dp1[(i+1)%2][j+1][t][y][1]=(dp1[(i+1)%2][j+1][t][y][1]+dp1[i%2][j][t][x][y])%mod;
                        }
                        if (x!=2){
                            dp1[(i+1)%2][j][t+1][y][2]=(dp1[(i+1)%2][j][t+1][y][2]+dp1[i%2][j][t][x][y])%mod;
                        }
                        dp1[(i+1)%2][j][t][y][0]=(dp1[(i+1)%2][j][t][y][0]+dp1[i%2][j][t][x][y]*(23ll+(x>0)))%mod;
                    }
                }
            }
        }
    }
    for (int i=1;i<=26;i++){
        for (int j=i+1;j<=26;j++){
            for (int cn1=c[i]+1;cn1<=n;cn1++){
                for (int cn2=c[j]+1;cn1+cn2<=n;cn2++){
                    for (int x=0;x<3;x++){
                        for (int y=0;y<3;y++){
                            res+=dp1[n%2][cn1][cn2][x][y];
//                            cout<<dp1[n%2][cn1][cn2][x][y]<<endl;
                            res%=mod;
                        }
                    }

                }
            }
        }
    }

}
int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    for(ll i = 1;i<=base;++i){
        cin>>A[i];
        c[i] = A[i];
    }
    solve();
    //solve1();
    ss();
    cout<<res<<endl;
    return 0;
}