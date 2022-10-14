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

bool kek( string a, string b, int n){
    int c=0;
    vi cnt(2*n+2,0), cn(2*n+2,0);
    for(auto x: a)
        if(x == '0')c++;
        else cn[c]++;
    int cc = 0;
    for(auto x: b)
        if(x == '0')cc++;
        else cn[cc]++;
    string s;
    for(int i = 0; i < max(c,cc)+1; i++){
        FOR(j,max(cn[i],cnt[i]))s.pb('1');
        s.pb('0');
    }
    s.pop_back();
    if(s.size()>3*n)return 0;
    while(s.size() < 3*n)s.pb('0');
    cout << s << endl;
    return 1;
}
bool kvk( string a, string b, int n){
    int c=0;
    vi cnt(2*n+2,0), cn(2*n+2,0);
    for(auto x: a)
        if(x == '1')c++;
        else cn[c]++;
    int cc = 0;
    for(auto x: b)
        if(x == '1')cc++;
        else cn[cc]++;
    string s;
    for(int i = 0; i < max(c,cc)+1; i++){
        FOR(j,max(cn[i],cnt[i]))s.pb('0');
        s.pb('1');
    }
    s.pop_back();
    if(s.size()>3*n)return 0;
    while(s.size() < 3*n)s.pb('1');
    cout << s << endl;
    return 1;
}

void solve(){
    int N; cin >> N;
    string a,b,c; cin >> a >> b >> c;
    if(kek(a,b,N))return;
    if(kek(a,c,N))return;
    if(kek(b,c,N))return;
    if(kvk(a,b,N))return;
    if(kvk(a,c,N))return;
    if(kvk(b,c,N))return;
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