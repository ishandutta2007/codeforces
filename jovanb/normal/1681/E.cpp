#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;
const ll INF = 1000000000000000000LL;

void mrg(ll** res, ll a[2][2], ll b[2][2]){
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            res[i][j] = INF;
            for(int k=0; k<2; k++){
                res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
            }
        }
    }
}

struct Segment{
    ll val[2][2];
} seg[4*N+5];

ll cniz[N+5][2][2];

void init(int node, int l, int r){
    if(l > r) return;
    if(l == r){
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                seg[node].val[i][j] = cniz[l][i][j];
            }
        }
        return;
    }
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            seg[node].val[i][j] = INF;
            for(int k=0; k<2; k++){
                seg[node].val[i][j] = min(seg[node].val[i][j], seg[node*2].val[i][k] + seg[node*2+1].val[k][j]);
            }
        }
    }
}

ll res[2][2];
ll pres[2][2];
ll id[2][2];

void query(int node, int l, int r, int tl, int tr){
    if(l > r) return;
    if(tl > r || l > tr) return;
    if(tl <= l && r <= tr){
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                pres[i][j] = res[i][j];
                res[i][j] = INF;
            }
        }
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                res[i][j] = INF;
                for(int k=0; k<2; k++){
                    res[i][j] = min(res[i][j], pres[i][k] + seg[node].val[k][j]);
                }
            }
        }
        return;
    }
    int mid = (l+r)/2;
    query(node*2, l, mid, tl, tr);
    query(node*2+1, mid+1, r, tl, tr);
}

pair <ll, ll> d[2][N+5];

ll rdist(ll a, ll b, ll c, ll d){
    return abs(a - c) + abs(b - d);
}

ll ps[2], pt[2];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    id[0][0] = id[1][1] = 0;
    id[0][1] = id[1][0] = INF;
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> d[0][i].first >> d[0][i].second >> d[1][i].first >> d[1][i].second;
    }
    for(int i=1; i<n-1; i++){
        for(int j=0; j<2; j++){
            cniz[i][0][j] = 1 + rdist(d[0][i].first + 1, d[0][i].second, d[j][i+1].first, d[j][i+1].second);
            cniz[i][1][j] = 1 + rdist(d[1][i].first, d[1][i].second + 1, d[j][i+1].first, d[j][i+1].second);
        }
    }
    init(1, 1, n - 2);
    int qrs;
    cin >> qrs;
    for(int tt=1; tt<=qrs; tt++){
        int d1i, d1j, d2i, d2j;
        cin >> d1i >> d1j >> d2i >> d2j;
        for(int i=0; i<2; i++) for(int j=0; j<2; j++) res[i][j] = id[i][j];
        int ly1 = max(d1i, d1j);
        int ly2 = max(d2i, d2j);
        if(ly1 == ly2){
            cout << rdist(d1i, d1j, d2i, d2j) << "\n";
            continue;
        }
        if(ly1 > ly2){
            swap(ly1, ly2);
            swap(d1i, d2i);
            swap(d1j, d2j);
        }
        query(1, 1, n - 2, ly1, ly2 - 2);
        ll sol = INF;
        //cout << d1i << "  " << d1j << " ze " << d[0][ly1].first << " " << d[0][ly1].second << endl;
        ps[0] = rdist(d1i, d1j, d[0][ly1].first, d[0][ly1].second);
        ps[1] = rdist(d1i, d1j, d[1][ly1].first, d[1][ly1].second);
        pt[0] = 1 + rdist(d2i, d2j, d[0][ly2-1].first + 1, d[0][ly2-1].second);
        pt[1] = 1 + rdist(d2i, d2j, d[1][ly2-1].first, d[1][ly2-1].second + 1);
        //cout << ps[0] << " " << ps[1] << " " << pt[0] << " " << pt[1] << endl;
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                sol = min(sol, ps[i] + res[i][j] + pt[j]);
            }
        }
        cout << sol << "\n";
    }
    return 0;
}

/*
4
1 1 1 1
2 1 2 2
3 2 1 3
1
1 1 3 3
*/