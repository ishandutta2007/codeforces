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

#define bity(x) (__builtin_popcountll((ll)(x)))

const int mod=998244353;
const int N=2e5+5;
const int M=36;
const int K=22;
const int T=M-K;

int n, m;
ll t[N], basis[M];
int sz;
int dwado[N]={1};
ll ans[M];
ll dp[M][M][1<<T];

void insertVector(ll mask) {
	for (int i = 0; i < m; i++) {
		if ((mask & (1ll << i)) == 0) continue; // continue if i != f(mask)
		if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
			basis[i] = mask;
			++sz;
			return;
		}
		mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
	}
}

void zmien(int a, int b){
    ll full=(1ll<<m)-1;
    FOR(i, 0, m-1){
        ll aty=(basis[i]>>a)&1;
        ll bty=(basis[i]>>b)&1;
        basis[i]&=(full^(1ll<<a)^(1ll<<b));
        basis[i]|=(aty<<b)^(bty<<a);
    }
    swap(basis[a], basis[b]);
}

void solve(){
    cin>>n>>m;
    FOR(i, 1, n) dwado[i]=((ll)dwado[i-1]*2)%mod;
    FOR(i, 1, n) cin>>t[i];
    FOR(i, 1, n) insertVector(t[i]);
    FOR(i, 0, m-1){
        if(!basis[i]){
            FOR(j, i+1, m-1){
                if(basis[j]){
                    zmien(i, j);
                    break;
                }
            }
        }
    }
    FOR(i, 0, m-1) FOR(j, i+1, m-1) if(basis[i] & (1ll<<j)) basis[i]^=basis[j];
    if(sz<K){
        FOR(mask, 0, (1<<sz)-1){
            ll val=0;
            FOR(i, 0, sz-1){
                if((mask>>i)&1) val^=basis[i];
            }
            ans[bity(val)]+=dwado[n-sz];
            ans[bity(val)]%=mod;
        }
    }
    else{
        dp[0][1][(basis[0]^1)>>sz]=1;
        dp[0][0][0]=1;
        FOR(i, 1, sz-1){
            ll konc=(basis[i]^(1ll<<i))>>sz;
            FOR(k, 0, m){
                FOR(mask, 0, (1<<T)-1){
                    dp[i][k][mask]+=dp[i-1][k][mask];
                    if(k>0) dp[i][k][mask]+=dp[i-1][k-1][mask^konc];
                    dp[i][k][mask]%=mod;
                }
            }
        }
        FOR(k, 0, m){
            FOR(mask, 0, (1<<T)-1){
                ans[k+bity(mask)]+=(ll)dp[sz-1][k][mask]*dwado[n-sz]%mod;
                ans[k+bity(mask)]%=mod;
            }
        }
    }
    FOR(i, 0, m) cout<<ans[i]<<sp;
    cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    // int tt; cin>>tt;
    // FOR(te, 1, tt)
	solve();
	return 0;
}