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
const int maxN = 500005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

bool isg[maxN];

int cnt;
map<int, int> mp;
int l, r;

vector<ii> qry;
vector<int> spl;
vector<int> wait;

void ins(int plc, int val){
    qry.pb(ii(plc, val));
    for2(i, cnt, plc + 1) a[i + 2] = a[i];
    a[plc + 1] = val;
    a[plc + 2] = val;
    cnt += 2;
}

void rev(int blit){
    int ps = l + blit - 1;
    for1(i, l, l + blit - 1){
        ins(ps, a[i]);
        ++ps;
    }
    spl.pb(blit * 2);
    l += blit * 2;
    r += blit * 2;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        cin >> n;
        qry.clear();
        mp.clear();
        spl.clear();
        wait.clear();
        for1(i, 1, n){
            cin >> a[i]; ++mp[a[i]];
        }
        x = 0;
        for(ii cc : mp) if(cc.se & 1) x = 1;
        if(x){
            cout << -1 << endl;
            continue;
        }
        cnt = n;
        l = 1, r = n;
        while(l <= r){
            if(a[l] == a[r]){
                rev(r - l); wait.pb(2); r -= 2;
            }
            else{
                for1(i, l, r) if(a[i] == a[r]){
                    rev(i - l + 1); break;
                }
            }
        }
        cout << qry.size() << endl;
        for(ii cc : qry) cout << cc.fi << " " << cc.se << endl;
        reverse(all(wait));
        cout << wait.size() + spl.size() << endl;
        for(int cc : spl) cout << cc << " ";
        for(int cc : wait) cout << cc << " ";

    }
}