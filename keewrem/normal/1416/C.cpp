#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N;
struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return x + FIXED_RANDOM;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vi v(N);
    for(auto &x: v)cin >> x;
    ll ans = 0,a,b,xx = 0;
    vi vv;
    for(int i = 1<<30; i; i >>= 1){
        a = 0, b = 0;
        unordered_map<int,int,custom_hash> m;
        vv = v;
        for(auto &x: vv)x/=i;
        for(auto x: vv){
            if(m.count(x))m[x]++;
            else m[x]=1;
            if(x&1)a+=m[x-1];
            else b+=m[x+1];
        }
    //    cout << "i "<<i << " a "<<a << " b "<<b <<"\n";
        if(a < b){
            ans+=a;
            xx^=i;
        }else{
            ans+=b;
        }
    }
    cout << ans << " "<<xx;

    return 0;
}