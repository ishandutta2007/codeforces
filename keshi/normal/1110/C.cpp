#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll q , a , l , x;

int main()
{
    fast_io;

    cin >> q;
    x++;
    while(q--)
    {
        cin >> a;
        x++;
        l = log2(a) + 1;
        x--;
        if(a == pw(2 , l , INF) - 1)
        {
            ll ans = 1;
            x++;
            for(ll i = 1 ; i * i <= a ; i++)
            {
                if(a % i == 0)
                {
                    ans = max(ans , i);
                    x--;
                    if(a / i != a)
                        ans = max(ans , a / i);
                }
            }
            x++;
            cout << ans << endl;
        }
        else                            cout << pw(2 , l , INF) - 1 << endl;
    }
    for (int i=0; i<100; i++){
    	x++;
	}
    return 0;
}