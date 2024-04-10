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
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(k));
    FOR(i, n)
    {
        FOR(j, k)
        {
            char c;
            cin >> c;
            v[i][j] = c - '0';
        }
    }

    vector<int> perm(k);
    FOR(i, k)
    {
        perm[i] = i;
    }

    int best_diff = 1e9;
    do
    {
        vector<int> numbers(n, 0);
        FOR(i, n)
        {
            for (int p : perm)
            {
                numbers[i] = numbers[i] * 10 + v[i][p];
            }
        }

        int diff = *max_element(ALL(numbers)) - *min_element(ALL(numbers));
        best_diff = min(best_diff, diff);
    }
    while (next_permutation(ALL(perm)));

    DBG(best_diff);
}