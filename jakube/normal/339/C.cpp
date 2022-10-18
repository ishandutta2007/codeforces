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

const int debug = 1;
template <typename T, typename S>
void DBG(pair<T, S> p){if(debug)cout<<p.first<<" "<<p.second<<endl;}
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    int m;
    cin >> m;

    vector<int> numbers;
    FOR(i, 10)
        if (s[i] == '1')
            numbers.push_back(i+1);

    vector<vector<vector<int>>> dp(11, vector<vector<int>>(numbers.size()));

    FOR(i, numbers.size())
    {
        dp[numbers[i]][i].push_back(numbers[i]);
    }

    FORR(j, 1, m)
    {
        FORR(k, 1, 11)
        {
            FOR(i, numbers.size())
            {
                if (dp[k][i].size() == j)
                {
                    FOR(ii, numbers.size())
                    {
                        int number = numbers[ii];
                        if (k < number && i != ii) {
                            dp[number - k][ii] = vector<int>(dp[k][i]);
                            dp[number - k][ii].push_back(number);
                        }
                    }
                }
            }
        }
    }

    FORR(i, 1, 11)
    {
        FOR(j, numbers.size())
        {
            if (dp[i][j].size() == m)
            {
                cout << "YES" << endl;
                DBG(dp[i][j]);
                return 0;
            }
        }
    }

    cout << "NO";
}