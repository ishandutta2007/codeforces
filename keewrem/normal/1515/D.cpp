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
    int N,a,b; cin >> N >> a >> b;
    vi l(N,0), r(N,0);
    FOR(i,N){
        cin >> b;
        if(i < a)l[b-1]++;
        else{
            if(l[b-1]>0)l[b-1]--;
            else r[b-1]++;
        }
    }
    a = 0; b = 0;
    for(auto x: l)a+=x;
    for(auto x: r)b+=x;
    int ans = min(a,b)+abs(a-b)/2;
    if(a > b){
        for(auto x: l)
            a = max(b,a-(x/2)*2);
    }else{
        for(auto x: r){
            b = max(a,b-(x/2)*2);
        }
    }
    cout << ans+abs(a-b)/2 << endl;
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