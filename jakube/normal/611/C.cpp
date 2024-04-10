#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);
const long long int MOD = 1e9 + 7;

typedef long long int lint;
typedef long double ld;
lint powmod(lint a,lint b, lint mod) {lint res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int debug = 0;
template <typename T>
T DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}return v;}
template <typename T>
T DBG(T t){if(debug)cout<<t<<endl;return t;}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    FOR(i, h)
        cin >> board[i];

    vector<vector<vector<lint>>> dp(h, vector<vector<lint>>(w, vector<lint>(3, 0)));
    FOR(r, h)
    {
        int count_left = 0;
        int count_up_old = 0;
        int count_up = 0;
        FOR(c, w)
        {
            count_up_old = count_up;
            if (board[r][c] == '.'){
                if (r > 0 && board[r - 1][c] == '.')
                    count_up++;

                if (c > 0 && board[r][c - 1] == '.')
                    count_left++;
            }

            if (r > 0)
            {
                dp[r][c][0] = dp[r - 1][c][0] + count_left + count_up;
                dp[r][c][1] = dp[r - 1][c][0] + count_up;
                dp[r][c][2] = dp[r - 1][c][2] + count_left + count_up_old;
            }
            else
            {
                dp[r][c][0] = count_left + count_up;
                dp[r][c][1] = count_up;
                dp[r][c][2] = count_left + count_up_old;
            }
        }
    }

    int queries;
    cin >> queries;
    FOR(i, queries)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;

        int number = DBG(dp[r2][c2][0]);
        number -= DBG(dp[r2][c1][2]);
        number -= DBG(dp[r1][c2][1]);
        number += DBG(dp[r1][c1][0]);
        //if (c1 > 0)
            number -= DBG(dp[r1][c1][0] - dp[r1][c1][1]);
        //if (r1 > 0)
            number -= DBG(dp[r1][c1][0] - dp[r1][c1][2]);

        cout << number << endl;
        DBG("");



    }

}