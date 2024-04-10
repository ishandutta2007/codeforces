#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;
const int K = 350;

struct Query{
    int l, r, ind;
    bool operator <(const Query &x){
        if(l/K == x.l/K) return (r < x.r);
        return l/K < x.l/K;
    }
};

ll a[N+5];
ll b[N+5];
ll c[N+5];
int cnt[3*N+5];
int vr[N+5];
ll sol[N+5];
ll res = 0;

map <ll, int> u;

void AddL(int ind){
    if(ind < 0) return;
    res += cnt[c[ind]];
    cnt[a[ind]]++;
}

void AddR(int ind){
    if(ind < 0) return;
    res += cnt[b[ind]];
    cnt[a[ind]]++;
}

void SubL(int ind){
    if(ind < 0) return;
    cnt[a[ind]]--;
    res -= cnt[c[ind]];
}

void SubR(int ind){
    if(ind < 0) return;
    cnt[a[ind]]--;
    res -= cnt[b[ind]];
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    ll k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> vr[i];
    }
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        if(vr[i] == 1) a[i] = a[i-1] + a[i];
        else a[i] = a[i-1] - a[i];
    }
    int tjm = 0;
    for(int i=0; i<=n; i++){
        if(!u[a[i]]) u[a[i]] = ++tjm;
        if(!u[a[i] - k]) u[a[i] - k] = ++tjm;
        if(!u[a[i] + k]) u[a[i] + k] = ++tjm;
        b[i] = u[a[i] - k];
        c[i] = u[a[i] + k];
        a[i] = u[a[i]];
    }
    int qrs;
    cin >> qrs;
    vector <Query> queries;
    for(int i=1; i<=qrs; i++){
        int l, r;
        cin >> l >> r;
        l--;
        queries.push_back({l, r, i});
    }
    sort(queries.begin(), queries.end());
    int l = -1, r = -1;
    for(auto qr : queries){
        while(r < qr.r){
            r++;
            AddR(r);
        }
        while(l > qr.l){
            l--;
            AddL(l);
        }
        while(r > qr.r){
            SubR(r);
            r--;
        }
        while(l < qr.l){
            SubL(l);
            l++;
        }
        sol[qr.ind] = res;
    }
    for(int i=1; i<=qrs; i++) cout << sol[i] << "\n";
    return 0;
}