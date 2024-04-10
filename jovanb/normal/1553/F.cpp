#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300000;

vector <int> divs[N+5];

struct Segment{
    ll sum;
    ll lazy;
} seg[4*N+5];

ll soln[N+5];

void propagate(int node, int l, int r){
    seg[node].sum += (r-l+1)*seg[node].lazy;
    if(l == r){
        seg[node].lazy = 0;
        return;
    }
    seg[node*2].lazy += seg[node].lazy;
    seg[node*2+1].lazy += seg[node].lazy;
    seg[node].lazy = 0;
}

void mrg(int node, int l, int r){
    int mid = (l+r)/2;
    propagate(node*2, l, mid);
    propagate(node*2+1, mid+1, r);
    seg[node].sum = seg[node*2].sum + seg[node*2+1].sum;
}

void set0(int node, int l, int r, int x){
    propagate(node, l, r);
    if(l == r){
        seg[node].sum = 0;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid) set0(node*2, l, mid, x);
    else set0(node*2+1, mid+1, r, x);
    mrg(node, l, r);
}

void upd(int node, int l, int r, int tl, int tr){
    propagate(node, l, r);
    if(tl > r || l > tr) return;
    if(tl <= l && r <= tr){
        seg[node].lazy++;
        propagate(node, l, r);
        return;
    }
    int mid = (l+r)/2;
    upd(node*2, l, mid, tl, tr);
    upd(node*2+1, mid+1, r, tl, tr);
    mrg(node, l, r);
}

ll query(int node, int l, int r, int tl, int tr){
    propagate(node, l, r);
    if(tl > r || l > tr) return 0;
    if(tl <= l && r <= tr) return seg[node].sum;
    int mid = (l+r)/2;
    return query(node*2, l, mid, tl, tr) + query(node*2+1, mid+1, r, tl, tr);
}

int ind[N+5];
int niz[N+5];

vector <int> uradi(int l, int r){
    vector <int> sp;
    if(l == r){
        sp.push_back(niz[l]);
        return sp;
    }
    int mid = (l+r)/2;
    vector <int> a = uradi(l, mid);
    vector <int> b = uradi(mid+1, r);
    vector <ll> pref;
    pref.push_back(0);
    for(int i=0; i<a.size(); i++){
        pref.push_back(a[i] + pref.back());
    }
    for(auto x : b){
        int pos = 0;
        while(pos < a.size()){
            int p = x*(a[pos]/x);
            auto nxt = lower_bound(a.begin(), a.end(), p+x) - a.begin();
            soln[ind[x]] += pref[nxt] - pref[pos] - (nxt-pos)*p;
            pos = nxt;
        }
    }
    int j = 0;
    for(auto c : a){
        while(j < b.size() && b[j] < c){
            sp.push_back(b[j]);
            j++;
        }
        sp.push_back(c);
    }
    while(j < b.size()){
        sp.push_back(b[j]);
        j++;
    }
    return sp;
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        ind[x] = i;
        niz[i] = x;
    }
    for(int i=1; i<=N; i++){
        if(!ind[i]) continue;
        for(int j=i; j<=N; j+=i){
            divs[j].push_back(ind[i]);
        }
    }
    for(int i=1; i<=N; i++){
        upd(1, 1, n, 1, n);
        for(auto c : divs[i]){
            set0(1, 1, n, c);
        }
        if(!ind[i]) continue;
        soln[ind[i]] = query(1, 1, n, 1, ind[i]);
    }
    uradi(1, n);
    for(int i=1; i<=n; i++){
        soln[i] += soln[i-1];
        cout << soln[i] << " ";
    }
    return 0;
}