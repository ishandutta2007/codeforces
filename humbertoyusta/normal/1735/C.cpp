#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 100010;
const int mod2 = 1000000007;
const int mod = 998244353;
const ll INF = 1ll * mod * mod;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return 1ll * qpow(b,e-1) * b % mod;
    ll pwur = qpow(b,e>>1);
    return 1ll * pwur * pwur % mod;
}
// Problem starts here

int find_(int x, vector<int> &p)
{
    return (p[x] == x) ? x : p[x] = find_(p[x], p);
}

bool join(int u,int v, vector<int> &p)
{
    u = find_(u, p);
    v = find_(v, p);
    if (u == v)
        return false;
    p[v] = u;
    return true;
}


int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> available(30, true);
        vector<int> p(30);
        for (int i=0; i<30; i++)
        {
            p[i] = i;
        }

        set<int> st;
        map<char, char> mp;
        for (auto i : s)
        {
            int x = int(i - 'a');
            if (st.find(x) == st.end())
            {
                st.insert(x);
                for (int j=0; j<26; j++)
                {
                    if (available[j] && (st.size() == 26 || join(x, j, p)))
                    {
                        available[j] = false;
                        mp[char(x + 'a')] = char(j + 'a');
                        break;
                    }
                }
            }
        }

        for (int i=0; i<n; i++)
            s[i] = mp[s[i]];

        cout << s << '\n';
    }

    return 0;
}