#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;

typedef long long int lint;
typedef long double ld;

template<typename T>
T read()
{
    T tmp;
    cin >> tmp;
    return tmp;
}
#define readi read<int>

template<typename T>
vector<T> reads(int count){
    vector<T> values;
    values.reserve(count);
    for (int i = 0; i < count; i++)
        values.push_back(read<T>());
    return values;
}
#define readsi reads<int>

int main() {
    int max = INT_MAX / 2;

    ios_base::sync_with_stdio(false);
    //cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, k, s;
    cin >> n >> k >> s;

    int max_s = 0;
    FOR(i, k)
        max_s += n-i;

    s = min(s, max_s);

    vector<vector<int>> dp(k + 1, vector<int>(s + 1, max));
    FOR(i, s+1)
        dp[0][i] = 0;

    FOR(i, n)
    {
        int next_soldier;
        cin >> next_soldier;
        //cout << next_soldier << " index:" << i << endl;
        for (int m = k; m > 0; m--)
        {
            if (i+1 < m)
                continue;
            //cout << "Bearbeite Zeile " << m << endl;
            for (int n = s; n >= 0; n--)
            {
                 if (n - (i+1 - m) >=  0)
                    dp[m][n] = min(dp[m][n], dp[m-1][n - (i+1-m)] + next_soldier);
                //else
                     //if ()
                    //dp[m][n] = min(dp[m][n], dp[m])
//                else
//                    if (m == i + 1)
//                        dp[m][n] = min(dp[m][n], dp[m-1][n] + next_soldier);
            }
        }
//        FOR(m, k+1)
//        {
//            FOR(n, s+1)
//            {
//                cout << (dp[m][n] == max ? -1 : dp[m][n]) << "\t";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }

    cout << dp[k][s];



}