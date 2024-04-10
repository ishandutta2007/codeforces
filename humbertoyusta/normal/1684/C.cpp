#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long double ld;
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const ll INF = 1ll * mod * mod;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> A(n, vector<int> (m));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                cin >> A[i][j];

        vector<vector<int>> B(m, vector<int> (n));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                B[j][i] = A[i][j];

        stable_sort(B.begin(), B.end());

        bool sorted = true;

        for (int i=1; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (B[i][j] < B[i-1][j])
                {
                    sorted = false;
                }
            }
        }

        if (!sorted)
        {
            cout << -1 << '\n';
            continue;
        }
        else
        {

            vector<int> swapped;
            for (int i=0; i<m; i++)
            {
                bool bad = false;
                for (int j=0; j<n; j++)
                    if (A[j][i] != B[i][j])
                        bad = true;
                if (bad)
                    swapped.push_back(i + 1);
            }

            if (swapped.size() == 0)
            {
                cout << 1 << ' ' << 1 << '\n';
                continue;
            }
            if (swapped.size() == 2)
            {
                cout << swapped[0] << ' ' << swapped[1] << '\n';
                continue;
            }
            if (swapped.size() > 2)
            {
                cout << -1 << '\n';
                continue;
            }
        }
    }


    return 0;
}