#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) int((x).size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; i >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD =   1000000007;//   998244353;

void solve(){
    ll N,K;
    cin >> N >> K;
    int v[N]; iota(v,v+N,1);
    if((1LL << min(N-1,61LL)) < K){cout << "-1\n"; return;}
    vi k; K--;
    if(K == 0){
        FOR(i,N)cout << v[i] << " ";
        cout << endl;
        return;
    }
    for(int i = min(61LL,N-1);i >= 0; i--){
        if(K&(1LL<<i))k.pb(N-i-2);
    }
    int s = k[0];
    for(int i = 1; i < k.size(); i++){
        if(k[i] == k[i-1]+1)continue;
        else {
            reverse(v+s,v+k[i-1]+2);
            s = k[i];
        }
    }
    reverse(v+s,v+k.back()+2);
    FOR(i,N)cout << v[i] << " ";
    cout << endl;
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}