//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'

const int N=3010;
const int mod=998244353;

string s, t;
int dp[N][N];

bool match(int a, int b){
    if(b >= SIZE(t)) return 1;
    return s[a]==t[b];
}

void solve(){
    cin>>s>>t;
    s='#'+s;
    t='#'+t;
    int n=SIZE(s)-1;
    FOR(i, SIZE(t), n+1) dp[i][0]=1;
    FORD(i, n, 1){
        FOR(k, 0, n){
            if(k>0 && match(i, k)) dp[i][k]+=dp[i+1][k-1];
            if(match(i, i+k)) dp[i][k]+=dp[i+1][k];
            dp[i][k]%=mod;
        }
    }
    int ans=0;
    FOR(i, 0, n) ans=(ans+dp[1][i])%mod;
    cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    // int tt; cin>>tt;
    // FOR(te, 1, tt)
	solve();
	return 0;
}