#include <bits/stdc++.h>
#include <queue>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define int long long

typedef long long ll;

using namespace std;

void solve();
signed main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cout.precision(15); cout << fixed;
    solve();
    return 0;
}

const int inf = 2e18 + 7;

struct T{
    vector<int> a, t, u;
    T(){}
    T(vector<int> a) : a(a){
        t.resize(4 * a.size());
        u.resize(4 * a.size());
        build(0, 0, a.size());
    }
    void build(int v, int l, int r){
        if(r -l == 1){
            t[v] = a[l];
            return;
        }
        build(2 * v + 1, l, l + r >> 1);
        build(2 * v + 2, l + r>> 1, r);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }
    void push(int v, int l, int r){
        if(!u[v]) return;
        if(r - l == 1){
            t[v] += u[v];
            u[v] = 0;
            return;
        }
        t[v] += u[v];
        u[2 * v + 1] += u[v];
        u[2 * v + 2] += u[v];
        u[v] = 0;
    }
    void upd(int v ,int l, int r, int vl, int vr, int d){
        push(v, l, r);
        if(l >= vr || vl >= r) return;
        if(vl <= l && r <= vr){
            u[v] += d;
            push(v, l, r);
            return;
        }
        upd(2 * v + 1, l, l + r >> 1, vl, vr, d);
        upd(2 * v+ 2, l + r >> 1,r, vl, vr, d);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }
    int get(int v, int l, int r, int vl, int vr){
        push(v, l, r);
        if(l >= vr || vl >= r) return -inf;
        if(vl <= l && r <= vr) return t[v];
        return max(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
    }
};

const int N = 2e5 + 7;

const int K = 1e6 + 1;

int a[N], ca[N], b[N], cb[N];

int m1[K], m2[K];


vector<pair<int, int> > kek[K];

void solve(){
    int n, m, p;
    cin >> n >> m >> p;
    fill(m1, m1 + K, inf);
    fill(m2, m2 + K, inf);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> ca[i]; a[i]--;
        m1[a[i]] = min(m1[a[i]], ca[i]);
    }
    for(int i = 0; i < m; i++){
        cin >> b[i] >> cb[i]; b[i]--;
        m2[b[i]] = min(m2[b[i]], cb[i]);
    }
    vector<int> mem(K);
    for(int i = K - 1; i >=0 ;i--){
        mem[i] = -m2[i];
        if(i != (K - 1))
            mem[i] = max(mem[i], mem[i + 1]);
    }
    T t = T(mem);
    for(int i =0 ; i < p; i++){
        int x, y, z;
        cin >> x>> y >> z; x--; y--;
        kek[x].push_back({y, z});
    }
    int ans = -inf;
    //cout << t.get(0, 0, K, 3, 4) << endl;
    for(int i = 0; i < K; i++){
        if(i){
            for(int j = 0; j < kek[i - 1].size(); j++){
                pair<int, int> v = kek[i - 1][j];
                t.upd(0, 0, K, v.first + 1, K, v.second);
            }
        }
        if(m1[i] == inf) continue;
        //if(i == 3) cout << m1[i] << " " << t.get(0, 0, K, 0, K) << endl;
        ans = max(ans, -m1[i] + t.get(0, 0, K, 0, K));
    }
    cout << ans << endl;
}