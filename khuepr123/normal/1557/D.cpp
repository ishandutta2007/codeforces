/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define ii pair<int, int>
#define iii pair<int, ii>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 600005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int m;
int dp[maxN];
map<int, int> mp;
vector<ii> qr[maxN];

int tree[maxN * 4];
int lazy[maxN * 4];
int l[maxN * 4];
int r[maxN * 4];

void build(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    tree[node] = 0;
    lazy[node] = -1;
    if(left == right) return;
    int mid = (left + right) / 2;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
}

int mxer;
void update(int node, int left, int right){
    if(left > right) return;
    tree[node] = max(tree[node], mxer);
    if(left == l[node] && right == r[node]){
        lazy[node] = max(lazy[node], mxer);
        return;
    }
    int mid = r[node * 2];
    update(node * 2, left, min(mid, right));
    update(node * 2 + 1, max(left, mid + 1), right);
}

int ans;
void get(int node, int left, int right){
    if(left > right) return;
    ans = max(ans, lazy[node]);
    if(left == l[node] && right == r[node]){
        ans = max(ans, tree[node]);
        return;
    }
    int mid = r[node * 2];
    get(node * 2, left, min(mid, right));
    get(node * 2 + 1, max(left, mid + 1), right);
}

vector<iii> trail;

int t1[maxN];
int t2[maxN];

void addup(int *ftree, int plc, int val){
    while(plc < maxN){
        ftree[plc] += val;
        plc += (plc & -plc);
    }
}

void range(int le, int ri, int val){
    addup(t1, le, val);
    addup(t1, ri + 1, -val);
    addup(t2, le, val * (le - 1));
    addup(t2, ri + 1, -val * ri);
}

int take(int *ftree, int plc){
    int res = 0;
    while(plc){
        res += ftree[plc];
        plc -= (plc & -plc);
    }
    return res;
}

int prefix_sum(int plc){
    return take(t1, plc) * plc - take(t2, plc);
}

bool query(int le, int ri){
    return (prefix_sum(ri) - prefix_sum(le - 1)) > 0;
}

stack<ii> trash;

void clean(){
    while(!trash.empty()){
        ii pr = trash.top(); trash.pop();
        range(pr.fi, pr.se, -1);
    }
}

void incr(ii pr){
    trash.push(pr);
    range(pr.fi, pr.se, 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    memset(t1, 0, sizeof(t1));
    memset(t2, 0, sizeof(t2));

    for1(i, 1, m){
        cin >> z >> x >> y; ++y;
        trail.pb({z, {x, y}});
        mp[x] = 0; mp[y] = 0;
    }
    x = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        itr->se = ++x;
    }
    for(iii cl : trail){
        x = cl.se.fi; y = cl.se.se;
        qr[cl.fi].pb({mp[x], mp[y] - 1});
    }
    build(1, 1, maxN - 1);
    int plc = 0;
    int fvl = -1;
    for1(i, 1, n){
        ans = 0;
        for(ii pr : qr[i]){
            x = pr.fi;
            y = pr.se;
            get(1, x, y);
        }
        mxer = ans + 1;
        for(ii pr : qr[i]){
            x = pr.fi;
            y = pr.se;
            update(1, x, y);
        }
        dp[i] = mxer;
        if(dp[i] > fvl){
            fvl = dp[i];
            plc = i;
        }
    }
    set<int> st;
    incr(ii(1, maxN - 1));
    while(plc){
        if(dp[plc] != fvl){
            --plc; continue;
        }
        for(ii pr : qr[plc]){
            if(query(pr.fi, pr.se)){
                --fvl;
                st.insert(plc);
                clean();
                for(ii pore : qr[plc]) incr(pore);
                break;
            }
        }
        --plc;
    }
    cout << n - st.size() << endl;
    for1(i, 1, n) if(st.find(i) == st.end()) cout << i << " ";
    cout << endl;
}