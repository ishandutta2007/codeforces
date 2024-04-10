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
        int a, b, ab, ba;
        cin >> a >> b >> ab >> ba;

        string s;
        cin >> s;

        int n = a + b + 2 * ab + 2 * ba;

        if (s.size() != n)
        {
            cout << "NO\n";
            continue;
        }

        int cntA(0), cntB(0);
        for (auto i : s)
        {
            cntA += (i == 'A');
            cntB += (i == 'B');
        }

        if (cntA != a + ba + ab || cntB != b + ab + ba)
        {
            cout << "NO\n";
            continue;
        }

        vector<int> mk(s.size());

        for (int i=0; i<n; i++)
        {
            if ( (i == 0 || s[i] == s[i-1]) && (i + 1 == n || s[i] == s[i+1]) )
                mk[i] = 1;
            if (i + 1 < n && ( (i == 0 || s[i] == s[i-1]) && (s[i] != s[i+1] && (i + 2 == n || s[i+1] == s[i+2]) )))
            {
                if (s[i] == 'A' && s[i+1] == 'B' && ab)
                    ab --;
                if (s[i] == 'B' && s[i+1] == 'A' && ba)
                    ba --;
                mk[i] = mk[i+1] = 1;
            }
        }

        multiset<int> AB, BA, ODD;
        int currId = 0;
        while (currId < n)
        {
            if (s[currId] == 'A' && !mk[currId])
            {
                int len = 1;
                while(currId + 1 < n && (!mk[currId+1] && s[currId + 1] != s[currId]))
                {
                    mk[currId] = 1;
                    currId ++;
                    len ++;
                }
                if (len & 1)
                    ODD.insert(len);
                else
                    AB.insert(len);
                currId ++;
                continue;
            }
            if (s[currId] == 'B' && !mk[currId])
            {
                int len = 1;
                while(currId + 1 < n && (!mk[currId+1] && s[currId + 1] != s[currId]))
                {
                    mk[currId] = 1;
                    currId ++;
                    len ++;
                }
                if (len & 1)
                    ODD.insert(len);
                else
                    BA.insert(len);
                currId ++;
                continue;
            }
            currId ++;
        }

//        db(AB.size())
//        db(BA.size())
        while (ab || ba) {
            if (AB.empty() && BA.empty() && ODD.empty())
            {
                break;
            }
            if (ab && !AB.empty())
            {
                int x = *AB.begin();
                AB.erase(AB.begin());
                ab --;
                if (x - 2 >= 2)
                    AB.insert(x - 2);
                continue;
            }
            if (ba && !BA.empty())
            {
                int x = *BA.begin();
                BA.erase(BA.begin());
                ba --;
                if (x - 2 >= 2)
                    BA.insert(x - 2);
                continue;
            }
            if (ab && !BA.empty() && *BA.rbegin() >= 3)
            {
                int x = *BA.rbegin();
                BA.erase(BA.lower_bound(*BA.rbegin()));
                ab --;
                if (x - 3 >= 2)
                    AB.insert(x - 3);
                continue;
            }
            if (ba && !AB.empty() && *AB.rbegin() >= 3)
            {
                int x = *AB.rbegin();
                AB.erase(AB.lower_bound(*AB.rbegin()));
                ba --;
                if (x - 3 >= 2)
                    BA.insert(x - 3);
                continue;
            }

            if (ab > ba)
            {
                if (!ODD.empty())
                {
                    int x = *ODD.begin();
                    ODD.erase(ODD.begin());
                    ab --;
                    if (x - 2 >= 2)
                        ODD.insert(x - 2);
                    continue;
                }
            }
            else
            {
                if (!ODD.empty())
                {
                    int x = *ODD.begin();
                    ODD.erase(ODD.begin());
                    ba --;
                    if (x - 2 >= 2)
                        ODD.insert(x - 2);
                    continue;
                }
            }
            break;
        }

        if (ab || ba)
            cout << "NO\n";
        else
            cout << "YES\n";
    }


    return 0;
}