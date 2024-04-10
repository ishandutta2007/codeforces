#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;
const int blk = 316;
int n, m, a[maxN];
int x, y, z, k;
int cnt[1048576];

int sum = 0;
int ans[maxN];

struct query{
    int l;
    int r;
    int ind;
} qr[maxN];

bool comp(query n1, query n2){
    if(n1.l / blk > n2.l / blk) return 0;
    if(n1.l / blk < n2.l / blk) return 1;
    return (((n1.l / blk) & 1ll) xor (n1.r < n2.r));
}

void ad(int ind){
    ind = a[ind];
    sum += cnt[ind ^ k];
    cnt[ind]++;
}

void sb(int ind){
    ind = a[ind];
    cnt[ind]--;
    sum -= cnt[ind ^ k];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o;
    cin >> n >> o >> k;
    a[1] = 0;
    n++;
    for1(i, 2, n){
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    memset(cnt, 0, sizeof(cnt));
    for1(i, 1, o){
        cin >> qr[i].l >> qr[i].r;
        qr[i].r++;
        qr[i].ind = i;
    }
    sort(qr + 1, qr + o + 1, comp);
    int l = 1;
    int r = 0;
    for1(i, 1, o){
        while(r < qr[i].r) ad(++r);
        while(l > qr[i].l) ad(--l);
        while(r > qr[i].r) sb(r--);
        while(l < qr[i].l) sb(l++);
        ans[qr[i].ind] = sum;
    }
    for1(i, 1, o){
        cout << ans[i] << endl;
    }
}