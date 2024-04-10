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
    int N; cin >> N;
    vi v(N); for(int &i: v)cin >> i;
    v.pb(-1);
    int ans = 0, a = -1, b = -1;
    for(int i = 0; i < N; i++){
        if(v[i] == a){
            if(v[i] == b)continue;
            else {b = v[i]; ans++;}
        }else{
            ans++;
            if(v[i] == v[i+1]){
                a = v[i];
            }else{
                if(b == v[i+1])b = v[i];
                else a = v[i];
            }
        }
    }
    cout << ans << "\n";
    return;
}

int main(){
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}