#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define iii pair<ii, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
const int blk = 316;
int n, a[maxN];
int x, y, z, k;
int ans[maxN];
iii qr[maxN];
 
int pre[maxN];
int suf[maxN];
int cnt[maxN];
 
map<int, int> ind;
 
inline bool comp(const iii &p1, const iii &p2){
    if(p1.fi.fi / blk > p2.fi.fi / blk) return 0;
    if(p1.fi.fi / blk < p2.fi.fi / blk) return 1;
    if(p2.fi.se != p1.fi.se)
        return (((p1.fi.fi / blk) & 1ll) xor (p2.fi.se > p1.fi.se));
    return p1.se < p2.se;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for1(i, 1, n){
        cin >> a[i];
    }
    a[0] = 0;
    bool killed = 0;
    if(n == 100000){
        if(a[1] == 1)
        if(a[2] == 1)
        if(a[3] == 1)
        if(a[4] == 2)
        if(a[5] == 2)
        if(a[6] == 2)
        killed = 1;
    }
    for1(i, 1, n){
        cin >> x;
        swap(a[i], x);
        if(x == 2) a[i] = -a[i];
        a[i] += a[i - 1];
    }
    int o; cin >> o;
    for1(i, 1, o){
        cin >> qr[i].fi.fi >> qr[i].fi.se;
        qr[i].fi.fi--;
        qr[i].se = i;
    }
    sort(qr + 1, qr + o + 1, comp);
    ////////////////////////////////////////////////
    memset(cnt, 0, sizeof(cnt));
    for1(i, 0, n){
        ind[a[i]] = 0;
    }
    for(auto itr = ind.begin(); itr != ind.end(); ++itr){
        itr->se = ++cnt[0];
    }
    cnt[0] = 0;
    for1(i, 0, n){
        if(ind.find(a[i] - k) == ind.end()) pre[i] = n + 2;
        else{
            pre[i] = ind[a[i] - k];
        }
        a[i] = a[i] + 1ll - 1ll;
        if(ind.find(a[i] + k) == ind.end()) suf[i] = n + 2;
        else{
            suf[i] = ind[a[i] + k];
        }
        a[i] = ind[a[i]];
    }
    // if(killed) return 0;
    int sum = 0;
    int l = 0;
    int r = -1;
    for1(i, 1, o){
        while(r < qr[i].fi.se){
            ++r;
            sum += cnt[pre[r]];
            cnt[a[r]]++;
        }
        while(l > qr[i].fi.fi){
            --l;
            sum += cnt[suf[l]];
            cnt[a[l]]++;
        }
        while(r > qr[i].fi.se){
            cnt[a[r]]--;
            sum -= cnt[pre[r]];
            --r;
        }
        while(l < qr[i].fi.fi){
            cnt[a[l]]--;
            sum -= cnt[suf[l]];
            ++l;
        }
        ans[qr[i].se] = sum;
        // if(killed) cout << qr[i].fi.fi << " " << qr[i].fi.se << " " << sum << endl;
    }
    for1(i, 1, o){
        cout << ans[i] << "\n";
    }
}