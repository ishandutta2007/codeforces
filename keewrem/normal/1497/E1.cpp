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
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) int(x.size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < k; i++)
#define foll(i,k) for(long long i = 0; i < k; i++)
#define FORr(i,k) for(int i = k-1; i >= 0; i--)
#define folr(i,k) for(long long i = k-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


void solve(){
    int N,K; cin >> N >> K;
    vi v(N);
    for(auto &x: v){
        cin >> x;
        for(int i = 2; i*i <= x; i++){
            if(x%(i*i) == 0)x/=(i*i);
        }
    }
    set<int> s;
    int ans = 1;
    for(auto x: v){
        if(s.count(x) > 0){s.clear(); ans++;}
        s.insert(x);
    }
    cout << ans << endl;
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