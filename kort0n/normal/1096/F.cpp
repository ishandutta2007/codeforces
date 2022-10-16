#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI
const ll mod = 998244353;
ll inv[1000000];
ll FactorialInv[1000000];
ll Factorial[1000000];
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
    for(int i = 2; i < 1000000; i++){
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
struct SegmentTree {
private:
    int n;
    vector<int> node;
 
public:
    SegmentTree() {
        int sz = 200500;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = (node[2*i+1] + node[2*i+2]);
    }
 
    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = (node[2*x+1] + node[2*x+2]);
        }
    }
    // hannkaikukann 
    int getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return (vl + vr);
    }
};


int main() {
    //cout.precision(10);
    SegmentTree question;
    SegmentTree ok;
    ll n;
    cin >> n;
    init_combination();
    ll a[200500];
    ll hatena = 0;
    for(int i = 1; i <= n; i++){
        question.update(i, 1);
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == -1){
            hatena++;
        }
        if(a[i] > 0){
            question.update(a[i], 0);
        }
    }
    ll ans = ((inv[2]) % mod) * (((hatena * (hatena - 1)) % mod * inv[2])% mod) % mod;
    ll before = 0;
    if(hatena == 0) hatena++;
    for(int i = 1; i <= n; i++){
        //cout << ans << endl;
        if(a[i] > 0){
            ans = (ans + ok.getsum(a[i], n + 1)) % mod;
            ll after = hatena - before;
            ll prob = (question.getsum(a[i], n + 1) * inv[hatena]) % mod;
            ans = (ans + prob * before) % mod;
            prob = (question.getsum(0, a[i]) * inv[hatena]) % mod;
            ans = (ans + prob * after) % mod;
            ok.update(a[i], 1);
            continue;
        }
        before++;
    }
    cout << ans << endl;
    return 0;
}