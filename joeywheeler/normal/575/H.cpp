#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define sz(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/

#define MOD_N 1000000007
#define MAX_N 1000005

ll pw (ll b, ll ex) {
    if (ex == 0) return 1;
    ll ans = 1;
    ll pow = b;
    for (;ex != 0;) {
        if (ex&1) {
            ans *= pow;
            ans %= MOD_N;
        }
        ex = ex>>1;
        pow *= pow;
        pow %= MOD_N;
        //printf ("ans: %d\n", (int) ans);
    }
    return ans;
}

ll inv (ll a) {
    //Use fermat's little theorem:
    //a^(p-2) == a^(-1)
    return pw(a,(MOD_N-2));
}
    
ll fact[2*MAX_N+10];

ll chs (ll a, ll b) {
    //a choose b
    //a!/(b!(a-b)!)
    ll ans = fact[a];
    ans *= inv(fact[b]);
    ans %= MOD_N;
    ans *= inv(fact[a-b]);
    ans %= MOD_N;
    return ans;
}

int N;

int main() {
    scanf ("%d", &N);
    fact[0] = 1;
    FO (i,1,2*N+5) {
        fact[i] = i*fact[i-1];
        fact[i] %= MOD_N;
    }
    ll ans = 0;
    FO (i,0,N+1) {
        ll st = i;
        ll en = N+i;
        ans += chs (en+1, i+1);
        //printf ("ans: %d\n", (int)ans);
        if (ans >= MOD_N) ans -= MOD_N;
    }
    printf ("%d\n", (int)ans);
    return 0;
}