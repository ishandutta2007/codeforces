#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
string C, S, T;
int dp[1005][52][52];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> C >> S >> T;
    for(int i = 0; i <= 51; i++) {
        for(int j = 0; j <= 51; j++) {
            for(int k = 0; k <= 1000; k++) dp[k][i][j] = -INF;
        }
    }
    dp[0][0][0] = 0;
    int snext[60][60][27], tnext[60][60][27];
    for(int s = 0; s < S.size(); s++) {
        for(int t = 0; t < T.size(); t++) {
            for(char moji = 'a'; moji <= 'z'; moji++) {
                string now = S.substr(0, s);
                now.push_back(moji);
                while(S.substr(0, now.size()) != now) now = now.substr(1);
                snext[s][t][(int)(moji - 'a')] = now.size();
                //cerr << s << " " << t << " " << moji << " ";
                //cerr << now.size() << " ";
                now = T.substr(0, t);
                now.push_back(moji);
                while(T.substr(0, now.size()) != now) now = now.substr(1);
                tnext[s][t][(int)(moji - 'a')] = now.size();
                //cerr << now.size() << endl;
            }
        }
    }
    string tester = S.substr(1);
    while(S.substr(0, tester.size()) != tester) tester = tester.substr(1);
    int SNEXT = tester.size();
    tester = T.substr(1);
    while(T.substr(0, tester.size()) != tester) tester = tester.substr(1);
    int TNEXT = tester.size();
    //cerr << SNEXT << " " << TNEXT << endl;
    for(int c = 0; c < C.size(); c++) {
        for(char moji = 'a'; moji <= 'z'; moji++) {
            int mojiindex = (int)(moji - 'a');
            if(C[c] != '*' && C[c] != moji) continue;
            for(int s = 0; s < S.size(); s++) {
                for(int t = 0; t < T.size(); t++) {
                    int val = dp[c][s][t];
                    int nexts = snext[s][t][mojiindex];
                    int nextt = tnext[s][t][mojiindex];
                    if(nexts == S.size()) {
                        val++;
                        nexts = SNEXT;
                    }
                    if(nextt == T.size()) {
                        val--;
                        nextt = TNEXT;
                    }
                    dp[c+1][nexts][nextt] = max(dp[c+1][nexts][nextt], val);
                }
            }
        }
    }
    int ans = -INF;
    for(int s = 0; s < S.size(); s++) {
        for(int t = 0; t < T.size(); t++) {
            ans = max(ans, dp[C.size()][s][t]);
        }
    }
    cout << ans << endl;
    return 0;
}