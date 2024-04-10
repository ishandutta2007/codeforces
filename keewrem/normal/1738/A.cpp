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
#define sz(x) (int)b((x).size())
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
const int MAXN = 3000010;

void solve(){
    int N; cin >> N;
    vector<int> a,b,v(N);
    for(auto &x: v)cin >> x;
    int in;
    ll sum = 0;
    for(int i = 0; i < N; i++){
        cin >> in; 
        if(v[i])a.push_back(in);
        else b.push_back(in);
        sum += in;
    }
    if(a.empty() || b.empty()){
        cout << sum << endl;
        return;
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    ll f = b.back();
    ll m = f;
    int i = 0;
    b.pop_back();
    for(auto x: a){
        if(i <= b.size())
            m += 2*x;
        else 
            m += x;
        if(i == b.size()) ++i;
        if(i < b.size())
            m += 2*b[i++];            
    }
    while(i < b.size())m += b[i++];
    b.push_back(f);
    ll ans = m;
    swap(a,b);
    m = b.back();
    b.pop_back();
    i = 0;
    for(auto x: a){
        if(i <= b.size())
            m += 2*x;
        else 
            m += x;
        if(i == b.size()) ++i;
        if(i < b.size())
            m += 2*b[i++];            
    }
    while(i < b.size())m += b[i++];
    ans = max(ans,m); 
    cout << ans << endl;
	return;
}

int main(){
	int T = 1;
	cin >> T;
	while(T--)solve();
	return 0;
}