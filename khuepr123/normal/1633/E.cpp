/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int m;

vector<int> libr;
int adr[maxN];
int crew[maxN];

int u[maxN], v[maxN], w[maxN];
int par[maxN];

void rest(){
    for1(i, 1, n) par[i] = i;
}

int find(int i){
    if(i == par[i]) return i;
    else return par[i] = find(par[i]);
}

vector<int> junk; int sz;
map<int, vector<ii>> mp;

vector<ii> ed[maxN];
int val[maxN];
int newval[maxN];
bool stat[maxN];
int nm = 0;

int ans = 0;
void solve(int vl){
    vl *= 2;
    int id = upper_bound(all(libr), vl) - libr.begin() - 1;
    int res = crew[id] * vl + adr[id];
    // cout << res << endl;
    ans ^= res;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    memset(adr, 0, sizeof(adr));
    memset(crew, 0, sizeof(adr));
    for1(i, 1, m){
        cin >> u[i] >> v[i] >> w[i]; w[i] *= 2;
        junk.pb(w[i]);
        mp[w[i]].pb(ii(u[i], v[i]));
    }
    for1(i, 1, m) for1(j, i + 1, m){
        junk.pb((w[i] + w[j] + 1) >> 1);
    }
    junk.pb(-1);
    sort(all(junk));
    libr.pb(junk[0]);
    for(int cc : junk) if(cc != libr.back()) libr.pb(cc);
    sz = libr.size();
    for(auto cc : mp){
        val[++nm] = cc.fi;
        ed[nm] = cc.se;
    }
    for1(id, 0, sz - 1){
        int statue = libr[id];
        for1(i, 1, nm){
            stat[i] = (statue >= val[i]);
            newval[i] = abs(statue - val[i]);
        }
        for1(i, 1, nm - 1){
            if(stat[i] && newval[i] >= newval[i + 1]){
                swap(newval[i], newval[i + 1]);
                swap(stat[i], stat[i + 1]);
                swap(val[i], val[i + 1]);
                swap(ed[i], ed[i + 1]);
            }
        }
        rest();
        for1(i, 1, nm){
            for(ii cc : ed[i]){
                x = find(cc.fi); y = find(cc.se);
                if(x != y){
                    par[x] = y;
                    if(stat[i]){
                        ++crew[id];
                        adr[id] -= val[i];
                    }
                    else{
                        --crew[id];
                        adr[id] += val[i];
                    }
                }
            }
        }
    }
    int pval, pp, o, aa, bb, cc;
    cin >> pp >> o >> aa >> bb >> cc;
    o -= pp;
    while(pp--){
        cin >> pval; solve(pval);
    }
    while(o--){
        pval = (pval * aa + bb) % cc; solve(pval);
    }
    cout << ans / 2 << endl;
}