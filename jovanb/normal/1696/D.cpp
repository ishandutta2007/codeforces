#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 250000;
const int LOG = 19;

int a[N+5];

int stmin[LOG+1][N+5];
int stmax[LOG+1][N+5];
int LG[N+5];

int qmin(int l, int r){
    int j = LG[r - l + 1];
    int x = stmin[j][l];
    int y = stmin[j][r - (1 << j) + 1];
    if(a[x] < a[y]) return x;
    return y;
}

int qmax(int l, int r){
    int j = LG[r - l + 1];
    int x = stmax[j][l];
    int y = stmax[j][r - (1 << j) + 1];
    if(a[x] > a[y]) return x;
    return y;
}

vector <int> graf[N+5];

int dist[N+5];

void add_edge(int u, int v){
    assert(u && v);
    if(u > v) swap(u, v);
    if(a[u] < a[v]){
        assert(qmin(u, v) == u);
        assert(qmax(u, v) == v);
    }
    else{
        assert(qmin(u, v) == v);
        assert(qmax(u, v) == u);
    }
    graf[u].push_back(v);
    graf[v].push_back(u);
}

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        graf[i].clear();
        dist[i] = 0;
    }
    if(n == 1){
        cout << "0\n";
        return;
    }
    vector <int> vec;
    vec.push_back(a[1]);
    for(int i=2; i<n; i++){
        if(a[i-1] < a[i] && a[i] > a[i+1]) vec.push_back(a[i]);
        if(a[i-1] > a[i] && a[i] < a[i+1]) vec.push_back(a[i]);
    }
    vec.push_back(a[n]);
    n = vec.size();
    for(int i=1; i<=n; i++) a[i] = vec[i-1];
    for(int i=1; i<=n; i++){
        stmin[0][i] = stmax[0][i] = i;
    }
    for(int j=1; j<=LOG; j++){
        for(int l=1; l<=n; l++){
            int r = l + (1 << j) - 1;
            if(r > n) continue;
            int x = stmin[j-1][l], y = stmin[j-1][l + (1 << (j-1))];
            if(a[x] < a[y]) stmin[j][l] = x;
            else stmin[j][l] = y;
            x = stmax[j-1][l], y = stmax[j-1][l + (1 << (j-1))];
            if(a[x] > a[y]) stmax[j][l] = x;
            else stmax[j][l] = y;
        }
    }
    int fv, lv, fm, lm;
    if(a[1] < a[2]){
        fv = 2;
    }
    else fv = 1;
    if(a[n] < a[n-1]){
        lv = n - 1;
    }
    else lv = n;
    fm = 3 - fv;
    lm = n + n - 1 - lv;
    stack <int> st;
    for(int i=fv; i<=lv; i+=2){
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        int tl;
        if(st.empty()) tl = 1;
        else tl = st.top() + 1;
        add_edge(i, qmin(tl, i));
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=lv; i>=fv; i-=2){
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        int tr;
        if(st.empty()) tr = n;
        else tr = st.top() - 1;
        add_edge(i, qmin(i, tr));
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=fm; i<=lm; i+=2){
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        int tl;
        if(st.empty()) tl = 1;
        else tl = st.top() + 1;
        add_edge(i, qmax(tl, i));
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=lm; i>=fm; i-=2){
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        int tr;
        if(st.empty()) tr = n;
        else tr = st.top() - 1;
        add_edge(i, qmax(i, tr));
        st.push(i);
    }
    queue <int> q;
    q.push(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto c : graf[v]){
            if(!dist[c] && c != 1){
                q.push(c);
                dist[c] = dist[v] + 1;
            }
        }
    }
    assert(dist[n]);
    cout << dist[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    for(int i=2; i<=N; i++) LG[i] = LG[i/2] + 1;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
6
1 2 3 4 6 5
*/