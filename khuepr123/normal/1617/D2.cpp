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
#define eb emplace_back
#define ii pair<int, int>
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int ray[] = {0, 1, 0, 0, 1, 1, 1, 0, 0, 0};

bool imp(int v1, int v2, int v3){
    cout << "? " << v1 << " " << v2 << " " << v3 << endl;
    assert(v1 != v2 && v1 != v3 && v2 != v3);
    int cn = 0;
    cn += ray[v1];
    cn += ray[v2];
    cn += ray[v3];
    // return cn > 1;
    cin >> v1; if(v1 == -1) exit(0); return !v1;
}
bool stat[maxN];
vector<int> svi[4];
int e(int slot, int id){
    return slot * 3 - id;
}

int p1, p0;
int p[2];
vector<int> ans;
int a0, a1, a2;

bool check(int v){
    return imp(v, p0, p1);
}

void solve(int sta){
    a0 = e(sta, 0);
    a1 = e(sta, 1);
    a2 = e(sta, 2);
    set<int> st;
    st.insert(a0);
    st.insert(a1);
    st.insert(a2);
    st.insert(p0);
    st.insert(p1);
    bool dm = stat[sta];
    // cout << a0 << " " << a1 << " " << a2 << " " << p1 << " " << p0 << " " << dm << endl;
    assert(st.size() == 5);
    if(imp(a0, a1, p[!dm]) != dm){
        a[0] = check(a0);
        a[1] = !a[0];
        a[2] = dm;
    }
    else{
        a[0] = dm;
        a[1] = dm;
        a[2] = check(a2);
    }
    if(a[0]) ans.pb(a0);
    if(a[1]) ans.pb(a1);
    if(a[2]) ans.pb(a2);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    for1(dumb, 1, o){
        ans.clear();
        cin >> n; n /= 3;
        for1(i, 1, n) stat[i] = imp(e(i, 0), e(i, 1), e(i, 2));
        for1(i, 2, n) if(stat[i] != stat[i - 1]){
            int j = i - 1;
            vector<int> dt, et, gt;
            dt.pb(e(i, 0));
            dt.pb(e(i, 1));
            dt.pb(e(j, 0));
            dt.pb(e(j, 1));
            // for(int cc : dt) cout << cc << " ";
            // cout << endl;
            for1(i1, 0, 3){
                for1(i2, 0, 3) if(i2 != i1) gt.pb(dt[i2]);
                et.pb(imp(gt[0], gt[1], gt[2]));
                svi[i1] = gt;
                gt.clear();
            }
            for1(i1, 0, 2) if(et[i1] != et[i1 + 1]){
                int i2 = i1 + 1;
                if(et[i2]) swap(i1, i2);
                map<int, int> mp;
                for(int cc : svi[i1]) ++mp[cc];
                for(int cc : svi[i2]) ++mp[cc];
                for(int cc : svi[i1]) if(mp[cc] == 1) p1 = cc;
                for(int cc : svi[i2]) if(mp[cc] == 1) p0 = cc;
                break;
            }
            if(et[0] == et[1] && et[1] == et[2] && et[2] == et[3]){
                if(et[0] == stat[i]){
                    p0 = e(j, 0);
                    p1 = e(j, 1);
                }
                else{
                    p0 = e(i, 0);
                    p1 = e(i, 1);
                }
            }
            vector<int> nom;
            for1(ig, i - 1, i) for1(jg, 0, 2){
                int id = e(ig, jg);
                if(id == p0 || id == p1) continue;
                if(check(id)) ans.pb(id);
                else nom.pb(id);
            }
            int c1 = p1;
            int c0 = p0;
            p0 = nom[0];
            p1 = ans[0];
            for1(ig, i - 1, i) for1(jg, 0, 2){
                int id = e(ig, jg);
                if(id != c1 && id != c0) continue;
                if(id == p0 || id == p1) continue;
                if(check(id)) ans.pb(id);
                else nom.pb(id);
            }
            p[1] = p1;
            p[0] = p0;
            for1(g, 1, i - 2) solve(g);
            for1(g, i + 1, n) solve(g);
            break;
        }
        sort(all(ans)); ans.resize(unique(all(ans)) - ans.begin());
        cout << "! " << ans.size();
        for(int cc : ans) cout << " " << cc;
        cout << endl;
    }
}