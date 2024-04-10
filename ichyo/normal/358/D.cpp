#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
const int INF = 500000000;
void update(int& x, int y) { if(x < y) x = y; }

int main(){
    int N;
    while(cin >> N){
        int d[3000][3];
        for(int j = 0; j < 3; j++)
        for(int i = 0; i < N; i++){
            cin >> d[i][j];
        }

        int dp[3333][2] = {};
        REP(i, N + 2) dp[i][0] = dp[i][1] = -INF;
        if(N == 1){
            cout << d[0][0] << endl;
            continue;
        }else if(N == 2){
            cout << max(d[0][1] + d[1][0], d[0][0] + d[1][1]) << endl;
            continue;
        }
        for(int i = 0; i < N - 1; i++){
            if(i == 0){
                update(dp[i + 1][0], d[i][0]);
                update(dp[i + 1][1], d[i][1]);
            }else if(i < N - 2){
                update(dp[i + 1][0], dp[i][1] + d[i][0]);
                update(dp[i + 1][1], dp[i][1] + d[i][1]);
                update(dp[i + 1][0], dp[i][0] + d[i][1]);
                update(dp[i + 1][1], dp[i][0] + d[i][2]);
            }else {
                update(dp[i + 1][0], dp[i][1] + d[i][0] + d[i + 1][1]);
                update(dp[i + 1][1], dp[i][1] + d[i][1] + d[i + 1][0]);
                update(dp[i + 1][0], dp[i][0] + d[i][1] + d[i + 1][1]);
                update(dp[i + 1][1], dp[i][0] + d[i][2] + d[i + 1][0]);
            }
            //cout << dp[i + 1][0] << " " << dp[i + 1][1] << endl;
        }
        cout << max(dp[N - 1][0], dp[N - 1][1]) << endl;
    }
    return 0;
}