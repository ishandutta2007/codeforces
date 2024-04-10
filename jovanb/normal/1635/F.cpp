#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int N = 300000;
const ll INF = 4000000000000000000LL;
 
ll seg[4*N+5];
 
void init(int node, int l, int r){
    seg[node] = INF;
    if(l == r) return;
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
}
 
void upd(int node, int l, int r, int x, ll val){
    if(l == r){
        seg[node] = min(seg[node], val);
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid) upd(node*2, l, mid, x, val);
    else upd(node*2+1, mid+1, r, x, val);
    seg[node] = min(seg[node*2], seg[node*2+1]);
}
 
ll query(int node, int l, int r, int tl, int tr){
    if(tl > r || l > tr) return INF;
    if(tl <= l && r <= tr) return seg[node];
    int mid = (l+r)/2;
    return min(query(node*2, l, mid, tl, tr), query(node*2+1, mid+1, r, tl, tr));
}
 
int x[N+5], w[N+5];
 
ll eval(int a, int b){
    return 1LL*abs(x[a] - x[b])*(w[a] + w[b]);
}
 
vector <pair <int, ll>> vec[N+5];
vector <pair <int, int>> qvec[N+5];
ll soln[N+5];
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;
 
    int n, qrs;
    cin >> n >> qrs;
    for(int i=1; i<=n; i++) cin >> x[i] >> w[i];
    for(int i=1; i<=qrs; i++){
        int l, r;
        cin >> l >> r;
        qvec[r].push_back({l, i});
    }
    stack <int> st;
    for(int i=1; i<=n; i++){
        while(!st.empty() && w[st.top()] > w[i]) st.pop();
        if(!st.empty()) vec[i].push_back({st.top(), eval(st.top(), i)});
        st.push(i);
    }
    while(st.size()) st.pop();
    for(int i=n; i>=1; i--){
        while(!st.empty() && w[st.top()] >= w[i]) st.pop();
        if(!st.empty()) vec[st.top()].push_back({i, eval(st.top(), i)});
        st.push(i);
    }
    init(1, 1, n);
    for(int i=1; i<=n; i++){
        for(auto c : vec[i]) upd(1, 1, n, c.first, c.second);
        for(auto c : qvec[i]){
            soln[c.second] = query(1, 1, n, c.first, i);
        }
    }
    for(int i=1; i<=qrs; i++) cout << soln[i] << "\n";
    return 0;
}