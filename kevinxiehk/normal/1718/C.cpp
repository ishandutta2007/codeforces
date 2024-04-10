#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1;
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}

int seg[800005][8];
int arr[200005][8];
int org[200005];
void build(int l, int r, int id, int aa) {
    if(l == r) seg[id][aa] = arr[l][aa];
    else {
        int m = (l + r) / 2;
        build(l, m, id * 2, aa);
        build(m + 1, r, id * 2 + 1, aa);
        seg[id][aa] = max(seg[id * 2][aa], seg[id * 2 + 1][aa]);
    }
    // cout << id << ' ' << seg[id] << '\n';
    return;
}
void upd(int l, int r, int id, int k, int aa) {
    if(l == r) seg[id][aa] = arr[l][aa];
    else {
        int m = (l + r) / 2;
        if(k <= m) upd(l, m, id * 2, k, aa);
        else upd(m + 1, r, id * 2 + 1, k, aa);
        seg[id][aa] = max(seg[id * 2][aa], seg[id * 2 + 1][aa]);
    }
    return;
}
int rmq(int l, int r, int id, int ql, int qr, int aa) {
    // cerr << l << ' ' << r << ' ' << id << ' ' << ql << ' ' << qr << '\n';
    if(ql > r || qr < l) return -1;
    if(ql <= l && qr >= r) return seg[id][aa];
    int m = (l + r) / 2;
    return max(rmq(l, m, id * 2, ql, qr, aa), rmq(m + 1, r, id * 2 + 1, ql, qr, aa));
}
vector<int> ha;
vector<int> sz;

int getans() {
    int an = 0;
    for(int i = 0; i < sz.size(); i++) {
        an = max(an, rmq(0, sz[i] - 1, 1, 0, sz[i] - 1, i) * sz[i]);
    }
    return an;
}
void solve(int TC) {
    // bruh nt
    // must be the lowest pf of n?
    int n, q;
    ha.clear();
    sz.clear();
    cin >> n >> q;
    int nn = n;
    for(int i = 2; i * i <= n; i++) {
        if(nn % i == 0) {
            ha.pb(i);
            sz.pb(n / i);
            while(nn % i == 0) nn /= i;
        }
    }
    if(nn > 1) {
        ha.pb(nn);
        sz.pb(n / nn);
    }
    int aa = ha.size();
    for(int i = 0; i < n; i++) cin >> org[i];
    // int t = 2;
    // while(n % t != 0) t++;
    // t = n / t;
    for(int j = 0; j < aa; j++) for(int i = 0; i < sz[j]; i++) arr[i][j] = 0;
    for(int j = 0; j < aa; j++) {
        for(int i = 0; i < n; i++) {
            arr[i % sz[j]][j] += org[i]; 
        } 
        build(0, sz[j] - 1, 1, j);
    }
    
    // cout << TC << ": " << t << '\n';
    cout << getans() << '\n';
    int a, b;
    while(q--) {
        cin >> a >> b;
        a--;
        int ch = b - org[a];
        org[a] = b;
        for(int j = 0; j < aa; j++) {
            arr[a % sz[j]][j] += ch;
            upd(0, sz[j] - 1, 1, a % sz[j], j);
        }
        cout << getans() << '\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}