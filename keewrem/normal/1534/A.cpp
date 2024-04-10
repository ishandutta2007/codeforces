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
    int N,M; cin >> N >> M;
    string s[N];
    for(int i = 0; i < N; i++)cin >> s[i];
    int b = -1, r = -1;
    FOR(i,N)FOR(j,M){
        if(s[i][j] == 'W'){
            if(b > -1 && b != (i+j)%2){
                cout << "NO\n";
                return;
            }
            b = (i+j)%2;
        }
        if(s[i][j] == 'R'){
            if(r > -1 && r != (i+j)%2){
                cout << "NO\n";
                return;
            }
            r = (i+j)%2;
        }
    }
    if(b > -1 && r == b){
        cout << "NO\n";
        return;
    }
    if(r == -1 && b == -1)r = 1;
    if(r > -1)b = 1-r;
    else r = 1-b;
    cout << "YES\n";
    FOR(i,N){
        FOR(j,M){
            if((i+j)%2 == r)cout << 'R';
            else cout << 'W';
        }
        cout << "\n";
    }
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