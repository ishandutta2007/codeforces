#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300000;

int a[N+5];
int sol[N+5];
vector <int> vec[N+5];
int cnt[N+5];

vector <int> top[N+5];
vector <int> tren;

void dodaj(int x){
    for(int i=0; i<tren.size(); i++){
        if(tren[i] == x){
            tren.erase(tren.begin() + i);
            break;
        }
    }
    bool inserted = 0;
    for(int i=0; i<tren.size(); i++){
        if(cnt[x] > cnt[tren[i]]){
            tren.insert(tren.begin() + i, x);
            inserted = 1;
            break;
        }
    }
    if(!inserted) tren.push_back(x);
    if(tren.size() > 5) tren.pop_back();
}

using T = tuple <int, int, int, int>;

int appear(int x, int l, int r){
    return lower_bound(vec[x].begin(), vec[x].end(), r+1) - lower_bound(vec[x].begin(), vec[x].end(), l);
}

void solve(int l, int r, const vector <T> &queries){
    if(l == r || queries.empty()) return;
    int mid = (l+r)/2;
    for(int i=mid; i>=l; i--){
        cnt[a[i]]++;
        dodaj(a[i]);
        top[i] = tren;
    }
    for(int i=mid; i>=l; i--) cnt[a[i]] = 0;
    tren.clear();
    for(int i=mid+1; i<=r; i++){
        cnt[a[i]]++;
        dodaj(a[i]);
        top[i] = tren;
    }
    for(int i=mid+1; i<=r; i++) cnt[a[i]] = 0;
    tren.clear();
    vector <T> q1, q2;
    for(auto qr : queries){
        int l, r, k, ind;
        tie(l, r, k, ind) = qr;
        if(l <= mid && mid+1 <= r){
            for(auto c : top[l]) if(appear(c, l, r) > (r-l+1)/k) sol[ind] = min(sol[ind], c);
            for(auto c : top[r]) if(appear(c, l, r) > (r-l+1)/k) sol[ind] = min(sol[ind], c);
        }
        else if(r <= mid) q1.push_back(qr);
        else q2.push_back(qr);
    }
    solve(l, mid, q1);
    solve(mid+1, r, q2);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, qrs;
    cin >> n >> qrs;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        vec[a[i]].push_back(i);
    }
    vector <T> queries;
    for(int i=1; i<=qrs; i++){
        sol[i] = N+5;
        int l, r, k;
        cin >> l >> r >> k;
        if(l == r) sol[i] = a[l];
        else queries.push_back({l, r, k, i});
    }
    solve(1, n, queries);
    for(int i=1; i<=qrs; i++){
        if(sol[i] == N+5) cout << "-1\n";
        else cout << sol[i] << "\n";
    }
    return 0;
}