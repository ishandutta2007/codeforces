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
const int MAXN = 10000100;
int p[MAXN];

vi get_div(int n){
    vi v = {1};
    int c = 0,s,ss;
    while(n > 1){
        c++;
        if(p[n] != p[n/p[n]]){
            s = sz(v);
            while(c--){
                ss = sz(v);
                for(int i = 0; i < s; i++)v.pb(p[n]*v[ss-i-1]);
            }
            c = 0;
        }
        n /= p[n];
    }
    return v;
}
ll m[MAXN], mm[MAXN];
void solve(){
    int N; cin >> N;
    int a;
    vll v(N+1); v[0] = 100000000;
    for(int i = 1; i <= N; i++){
        cin >> v[i];
        for(auto x: get_div(v[i])){
            if(v[i] < v[mm[x]])mm[x] = i;
            if(v[mm[x]] < v[m[x]])swap(mm[x],m[x]);
        }
    }
    ll ans = 10000000000000000;
    pii k;
    for(int i = 1; i < MAXN; i++){
        if(mm[i] == 0 || m[i] == 0)continue;
        if(v[m[i]] * v[mm[i]] / i < ans){
            k = {m[i],mm[i]};
            ans = v[m[i]] * v[mm[i]] / i;
        }
    }
    cout << min(k.fi,k.se) <<" "<< max (k.fi,k.se)<<endl;
    return;
}

int main(){
    for(int i = 2; i < MAXN; i++){
        if(p[i] == 0)for(int j = i; j < MAXN; j+= i)p[j] = i;
    }
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}