#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T = 1;
ll N,M,K;
ll dp[101][101][11];
bool pr[101][101][11];
int main(){
    cin >> N >> M >> K; K++;
    for(int i = 0; i < M; i++)for(int j = 0; j < N; j++)for(int k = 0; k < K; k++)dp[j][i][k] = -1;
    string s[N];
    for(int i = N-1; i >=0; i--)cin >> s[i];
    for(int i = 0; i < N; i++)for(auto &x: s[i])x-='0';
    for(int i = 0; i < M; i++)dp[0][i][(s[0][i])%K] = s[0][i];
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < K; k++){
                if(dp[i][j][k] == -1)continue;
                if(j > 0){
                    if(dp[i+1][j-1][(k+s[i+1][j-1])%K] < dp[i][j][k] + s[i+1][j-1]){
                        dp[i+1][j-1][(k+s[i+1][j-1])%(K)] = dp[i][j][k] + s[i+1][j-1];
                        pr[i+1][j-1][(k+s[i+1][j-1])%(K)] = 1;
                    }
                }
                if(j < M-1){
                    if(dp[i+1][j+1][(k+s[i+1][j+1])%K] < dp[i][j][k] + s[i+1][j+1]){
                        dp[i+1][j+1][(k+s[i+1][j+1])%(K)] = dp[i][j][k] + s[i+1][j+1];
                        pr[i+1][j+1][(k+s[i+1][j+1])%(K)] = 0;
                    }
                }
            }
        }
    }
    int m = -1;
    int mi,mk = 0;
    for(int i = 0; i < M; i++){
        if(dp[N-1][i][0] > m){
            m = dp[N-1][i][0];
            mi = i;
        }
    }
    string ans;
    if(m == -1){cout << "-1\n"; return 0;}
    for(int i = N-1; i>0; i--){
    //    cout << mi << " "<<mk<<"\n";
        int nm;
        if(pr[i][mi][mk] == 1){ans.pb('L');nm =   mi+1;}
        else {ans.pb('R');nm = mi -1;}
        mk = (6*K+mk-s[i][mi])%K;
        mi = nm;

    }
    reverse(ans.begin(),ans.end());
    cout << m <<"\n"<<mi+1<<"\n"<<ans<<"\n";
    return 0;
}