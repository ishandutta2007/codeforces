#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int dp[300][300][300];
int SIZE[4];
int ctoi(char moji) {
    return (int)(moji-'a');
}
string religion[4];

int n, q;
string S;
int NEXT[100005][27];

void initialize() {
    int LAST[27];
    for(int i = 0; i <= 25; i++) LAST[i] = INF;
    for(int i = n; i >= 0; i--) {
        for(int index = 0; index <= 25; index++) {
            NEXT[i][index] = LAST[index];
        }
        LAST[ctoi(S[i])] = i;
        //cerr << i << " " << NEXT[i][0] << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> q >> S;
    S = "#" + S;
    initialize();
    for(int i = 0; i <= 250; i++) {
        for(int j = 0; j <= 250; j++) {
            for(int k = 0; k <= 250; k++) dp[i][j][k] = INF;
        }
    }
    for(int i = 1; i <= 3; i++) religion[i] = "#";
    dp[0][0][0] = 0;
    while(q--) {
        char sign;
        cin >> sign;
        int index;
        cin >> index;
        if(sign == '-') {
            religion[index].pop_back();
            SIZE[index]--;
            if(dp[SIZE[1]][SIZE[2]][SIZE[3]] <= n) {
                cout << "YES" << endl;
            } else cout << "NO" << endl;
            continue;
        }
        char dust;
        cin >> dust;
        religion[index].push_back(dust);
        //cerr << index << " " << religion[index] << endl;
        int now = ctoi(dust);
        SIZE[index]++;
        int index_S[4];
        for(index_S[1] = 0; index_S[1] <= SIZE[1]; index_S[1]++) {
            if(index == 1) index_S[1] = SIZE[1];
            for(index_S[2] = 0; index_S[2] <= SIZE[2]; index_S[2]++) {
                if(index == 2) index_S[2] = SIZE[2];
                for(index_S[3] = 0; index_S[3] <= SIZE[3]; index_S[3]++) {
                    if(index == 3) index_S[3] = SIZE[3];
                    dp[index_S[1]][index_S[2]][index_S[3]] = INF;
                    if(index_S[1] > 0 && dp[index_S[1]-1][index_S[2]][index_S[3]] <= n) {
                        dp[index_S[1]][index_S[2]][index_S[3]] = min(dp[index_S[1]][index_S[2]][index_S[3]], NEXT[dp[index_S[1]-1][index_S[2]][index_S[3]]][ctoi(religion[1][index_S[1]])]);
                        //cerr << religion[1][index_S[1]] << endl;
                    }
                    if(index_S[2] > 0 && dp[index_S[1]][index_S[2]-1][index_S[3]] <= n) {
                        dp[index_S[1]][index_S[2]][index_S[3]] = min(dp[index_S[1]][index_S[2]][index_S[3]], NEXT[dp[index_S[1]][index_S[2]-1][index_S[3]]][ctoi(religion[2][index_S[2]])]);
                    }
                    if(index_S[3] > 0 && dp[index_S[1]][index_S[2]][index_S[3]-1] <= n) {
                        dp[index_S[1]][index_S[2]][index_S[3]] = min(dp[index_S[1]][index_S[2]][index_S[3]], NEXT[dp[index_S[1]][index_S[2]][index_S[3]-1]][ctoi(religion[3][index_S[3]])]);
                    }
                    //cerr << "UPDATING: " << index_S[1] << " " << index_S[2] << " " << index_S[3] << endl;
                    //cerr << dp[index_S[1]][index_S[2]][index_S[3]] << endl;
                }
            }
        }
        /*
        dp[SIZE[1]][SIZE[2]][SIZE[3]] = INF;
        if(SIZE[1] > 0 && dp[SIZE[1]-1][SIZE[2]][SIZE[3]] <= n) {
            dp[SIZE[1]][SIZE[2]][SIZE[3]] = min(dp[SIZE[1]][SIZE[2]][SIZE[3]], NEXT[dp[SIZE[1]-1][SIZE[2]][SIZE[3]]][now]);
        }
        if(SIZE[2] > 0 && dp[SIZE[1]][SIZE[2]-1][SIZE[3]] <= n) {
            dp[SIZE[1]][SIZE[2]][SIZE[3]] = min(dp[SIZE[1]][SIZE[2]][SIZE[3]], NEXT[dp[SIZE[1]][SIZE[2]-1][SIZE[3]]][now]);
        }
        if(SIZE[3] > 0 && dp[SIZE[1]][SIZE[2]][SIZE[3]-1] <= n) {
            dp[SIZE[1]][SIZE[2]][SIZE[3]] = min(dp[SIZE[1]][SIZE[2]][SIZE[3]], NEXT[dp[SIZE[1]][SIZE[2]][SIZE[3]-1]][now]);
        }
        */
        cerr << q << " " << dp[SIZE[1]][SIZE[2]][SIZE[3]] << endl;
        if(dp[SIZE[1]][SIZE[2]][SIZE[3]] <= n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}