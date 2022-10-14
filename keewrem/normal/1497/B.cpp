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
    int N,M; cin >> N >> M;
    vi c(M*2,0);
    int a;

    for(int i = 0; i < N; i++){cin >> a; c[a%M]++;}

    if(M == 1){cout << "1\n"; return;}
    int ans = 0;
    if(c[0] > 0)ans = 1;
    if(M%2 == 0 && c[M/2]>0)ans++;
    for(int i = 1; i < (M+1)/2; i++){
        ans += abs(c[M-i]-c[i]);
        if(c[i] == c[M-i] && c[i]!=0)ans++;
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