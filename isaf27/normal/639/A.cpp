#include <bits/stdc++.h>

using namespace std;

#define FOR(i, l, r) for (ll (i) = (l); (i) < (r); ++(i))
#define FORD(i, l, r) for (ll (i) = (l); (i) > (r); --(i))
#define True true
#define False false
#define S second
#define F first
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define eps 1e-9
#define COUT 20
#define db(x) cerr << endl <<#x << " = " << x << endl
#define sqr(x) (x) * (x)
#define sqrt(x) pow((x), 0.5)
#define START_() ios::sync_with_stdio(0); cin.tie(0); cout.precision(COUT);

#define x0 pelfpskfo
#define y0 issgksknkdns
#define x1 kjwoieill
#define y1 poposkdlkd

typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ld pi = acos(-1.0);

ll gcd (ll n1, ll n2) {return ((n2) == 0) ? (n1) : gcd ((n2), (n1) % (n2));}
ll lcm (ll n1, ll n2) {return n1 * n2 / gcd(n1, n2);}
#define read_default() ll n; cin >> n; ll a[n]; FOR(i, 0, n) cin >> a[i];
int main()
{
    ll n, k, q;
    cin >> n >> k >> q;
    ll t[n];
    vll yes(k);
    FOR(i, 0, n)
        cin >> t[i];
    ll type[q], id[q];
    FOR(i, 0, q){
        cin >> type[i] >> id[i];
        if(type[i] == 1){
            vll now(k + 1);
            ll last = 0;
            bool flag = True;
            FOR(j, 0, k){
                now[last] = (yes[j]);
                last++;
                if(yes[j] < t[id[i] - 1] && flag){
                    now[last] = (t[id[i] - 1]);
                    last++;
                    flag = False;
                }
            }
            sort(all(now));
            FOR(j, 1, k + 1){
                yes[j - 1] = now[j];
            }
        }
        else
        {
            bool flag = True;
            FOR(j, 0, k){
                if(yes[j] == t[id[i] - 1])
                    flag = False;
                //cout << yes[j] << " ";
            }
            if(flag)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}