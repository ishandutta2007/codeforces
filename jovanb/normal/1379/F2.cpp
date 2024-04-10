#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 400000;

map <pair <int, int>, int> koji;

int lbseg[4*N+5], rbseg[4*N+5];

void lb_upd(int node, int l, int r, int x, int val){
    if(l == r){
        lbseg[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid) lb_upd(node*2, l, mid, x, val);
    else lb_upd(node*2+1, mid+1, r, x, val);
    lbseg[node] = max(lbseg[node*2], lbseg[node*2+1]);
}

int lb_mxquery(int node, int l, int r, int tl, int tr){
    if(tl > r || l > tr) return 0;
    if(tl <= l && r <= tr) return lbseg[node];
    int mid = (l+r)/2;
    return max(lb_mxquery(node*2, l, mid, tl, tr), lb_mxquery(node*2+1, mid+1, r, tl, tr));
}

void rb_upd(int node, int l, int r, int x, int val){
    if(l == r){
        rbseg[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid) rb_upd(node*2, l, mid, x, val);
    else rb_upd(node*2+1, mid+1, r, x, val);
    rbseg[node] = min(rbseg[node*2], rbseg[node*2+1]);
}

int rb_mnquery(int node, int l, int r, int tl, int tr){
    if(tl > r || l > tr) return 2*N;
    if(tl <= l && r <= tr) return rbseg[node];
    int mid = (l+r)/2;
    return min(rb_mnquery(node*2, l, mid, tl, tr), rb_mnquery(node*2+1, mid+1, r, tl, tr));
}

int qi[N+5], qj[N+5];
multiset <int> lbs[N+5], rbs[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, m, qrs;
    cin >> n >> m >> qrs;
    for(int i=1; i<=4*N; i++) rbseg[i] = 2*N;
    for(int i=1; i<=n; i++){
        lbs[i].insert(0);
        rbs[i].insert(m);
    }
    set <int> st;
    for(int tt=1; tt<=qrs; tt++){
        int ih, jh;
        cin >> ih >> jh;
        qi[tt] = ih;
        qj[tt] = jh;
        if(!koji[{ih, jh}]){
            koji[{ih, jh}] = tt;
            st.insert(tt);
        }
        else{
            int t = koji[{ih, jh}];
            if(st.find(t) != st.end()) st.erase(t);
            else{
                int i = (ih + 1)/2;
                int j = (jh + 1)/2;
                if(ih%2 == 1){
                    rbs[i].erase(rbs[i].find(j - 1));
                    rb_upd(1, 1, n, i, *rbs[i].begin());
                }
                else{
                    lbs[i].erase(lbs[i].find(j));
                    lb_upd(1, 1, n, i, *lbs[i].rbegin());
                }
            }
            koji[{ih, jh}] = 0;
        }
        while(!st.empty()){
            auto ind = *st.begin();
            ih = qi[ind], jh = qj[ind];
            int i = (ih + 1)/2;
            int j = (jh + 1)/2;
            if(ih%2 == 1){
                rbs[i].insert(j - 1);
                if(lb_mxquery(1, 1, n, i, n) > *rbs[i].begin()){
                    rbs[i].erase(rbs[i].find(j - 1));
                    break;
                }
                rb_upd(1, 1, n, i, *rbs[i].begin());
            }
            else{
                lbs[i].insert(j);
                if(rb_mnquery(1, 1, n, 1, i) < *lbs[i].rbegin()){
                    lbs[i].erase(lbs[i].find(j));
                    break;
                }
                lb_upd(1, 1, n, i, *lbs[i].rbegin());
            }
            st.erase(ind);
        }
        if(st.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}