#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
const int rng = 547;
int n, a[maxN];
int ans[maxN];
int cnt[maxN];
int cx[maxN];
int x, y, z, k;
int mxer = 0;

struct query{
    int l;
    int r;
    int ind;
}qr[maxN];


bool comp(query f1, query f2){
    if(f1.l / rng > f2.l / rng) return 0;
    if(f1.l / rng < f2.l / rng) return 1;
    if((f1.l / rng) & 1) return f1.r > f2.r;
    else                return f1.r < f2.r;
}

void ad(int pos){
    cx[cnt[a[pos]]]--;
    cnt[a[pos]]++;
    cx[cnt[a[pos]]]++;
    if(mxer < cnt[a[pos]]) mxer = cnt[a[pos]];
}

void mn(int pos){
    if(mxer == cnt[a[pos]]) if(cx[cnt[a[pos]]] == 1) --mxer;
    cx[cnt[a[pos]]]--;
    cnt[a[pos]]--;
    cx[cnt[a[pos]]]++;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o;
    cin >> n >> o;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[i] = 0;
        cx[i] = 0;
    }
    cx[0] = n;
    for(int i = 1; i <= o; i++){
        cin >> qr[i].l >> qr[i].r;
        qr[i].ind = i;
    }
    sort(qr + 1, qr + o + 1, comp);
    int l = 1;
    int r = 0;
    mxer = 0;
    for(int i = 1; i <= o; i++){
        while(r < qr[i].r){
            r++;
            ad(r);
        }
        while(l > qr[i].l){
            l--;
            ad(l);
        }
        while(l < qr[i].l){
            mn(l);
            l++;
        }
        while(r > qr[i].r){
            mn(r);
            r--;
        }
        int len = qr[i].r - qr[i].l + 1;
        int ds = (len + 1) / 2;
        int idr = qr[i].ind;
        if(mxer <= ds){
            ans[idr] = 1;
        }
        else{
            ds = len - mxer;
            ans[idr] = mxer - ds;
        }
    }
    for(int i = 1; i <= o; i++){
        cout << ans[i] << "\n";
    }
}