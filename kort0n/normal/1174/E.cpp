#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
ll ans = 1;
ll num[20];
ll num3[20];
ll numnot3[20];
ll inv[1000005];
ll FactorialInv[1000005];
ll Factorial[1000005];
ll beki(ll a, ll b){
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2);
    ans = ans * ans % mod;
    if(b % 2 == 1){
        ans = ans * a % mod;
    }
    return ans;
}
void init_combination(){
    inv[1] = 1;
    FactorialInv[1] = 1;
    Factorial[1] = 1;
    Factorial[0] = 1;
    FactorialInv[0] = 1;
    inv[0] = 1;
    for(int i = 2; i < 1000004; i++){
        inv[i] = beki(i, mod - 2);
        Factorial[i] = Factorial[i - 1] * i % mod;
        FactorialInv[i] = FactorialInv[i - 1] * inv[i] % mod;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    init_combination();
    ll n;
    cin >> n;
    ll len = 1;
    while(((ll)1 << len) <= n) len++;
    //cerr << len << endl;
    for(ll i = 1; i <= n; i++) {
        ll index = 0;
        while(!((1 << index) & i)) index++;
        num[index]++;
        if(i % 3 == 0) num3[index]++;
        else numnot3[index]++;
    }
    ans = Factorial[num[0]];
    ll nowsum = num[0];
    for(int i = 1; i < len; i++) {
        //if(num[i] == 0) continue;
        ll now = (Factorial[nowsum + num[i]] * FactorialInv[nowsum]) - (Factorial[nowsum + num[i] - 1] * FactorialInv[nowsum - 1]);
        now = ((now % mod) + mod) % mod;
        ans = ans * now % mod;
        nowsum += num[i];
        //cerr << i << " " << now << " " << ans << " " << nowsum << " " << num[i] << " " << endl;
    }
    cerr << ans << endl;
    if(beki(2, len - 1) * 3 <= n * 2) {
        numnot3[len-2] += numnot3[len-1];
        numnot3[len-1] = 0;
        for(int three = 0; three < len; three++) {
            ll nowans = 1;
            ll nowsum = 0;
            for(int i = 0; i < len; i++) {
                ll nownum = 0;
                if(i < three) {
                    nownum = numnot3[i] + num3[i];
                } else if(i == three) {
                    for(int j = three; j < len; j++) {
                        nownum += numnot3[j];
                    }
                } else if(i > three) {
                    nownum = num3[i - 1];
                }
                //cerr << three << " " << i << " " << nownum << endl;
                ll now = (Factorial[nowsum + nownum] * FactorialInv[nowsum]) - (Factorial[nowsum + nownum - 1] * FactorialInv[nowsum - 1]);
                now = ((now % mod) + mod) % mod;
                nowans = nowans * now % mod;
                nowsum += nownum;
            }
            ans = (ans + nowans) % mod;
            //cerr << three << " " << nowans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}