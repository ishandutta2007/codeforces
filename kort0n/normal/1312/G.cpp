#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
typedef pair<char, int> ci;
vector<ci> node[1002000];
vector<int> query;
vector<int> ans;
int choosen[1000200];
int cnt = 0;
int number[1000200];
int anssub[1000200];
int p[1000300];
int l[1000020], r[1000020];
struct LazySegmentTree {
private:
    int n;
    vector<int> node, lazy;

public:
    LazySegmentTree() {
        int sz = 1e6;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 1e9);
        lazy.resize(2*n-1, 1e9);

        for(int i=0; i<sz; i++) node[i+n-1] = 1e9;
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }
    void eval(int k, int l, int r) {
        if(lazy[k] != 1e9) {
            chmin(node[k], lazy[k]);
            if(r - l > 1) {
                chmin(lazy[2*k+1], lazy[k]);
                chmin(lazy[2*k+2], lazy[k]);
            }
            lazy[k] = 1e9;
        }
    }

    void update(int a, int b, int x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            chmin(lazy[k], x);
            eval(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }

    int getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);

        if(b <= l || r <= a) return 1e9;
        if(a <= l && r <= b) return node[k];
        ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }

};



void dfs2(int now) {
    if(choosen[now] != -1) {
        p[cnt] = choosen[now];
        choosen[now] = cnt;
        chmin(l[now], cnt);
        chmax(r[now], cnt);
        cnt++;
    }
    for(auto tmp : node[now]) {
        dfs2(tmp.second);
        chmin(l[now], l[tmp.second]);
        chmax(r[now], r[tmp.second]);
    }
}

/*
void dfs(int now, int score, int before) {
    int nextscore = score + 1;
    int nextbefore = before;
    if(choosen[now] != -1) {
        int tmp = score;
        if(before != -1) {
            chmin(tmp, anssub[before] + cnt - before);
        }
        ans[choosen[now]] = tmp;
        anssub[cnt] = tmp;
        cerr << choosen[now] << " " << tmp << endl;
        nextscore = tmp + 1;
        nextbefore = cnt;
        cnt++;
    }
    cerr << now << " " << cnt << " " << nextscore << " " << nextbefore << endl;
    for(auto tmp : node[now]) {
        dfs(tmp.second, nextscore, nextbefore);
    }
}
*/
LazySegmentTree seg;

void dfs(int now, int score) {
    if(choosen[now] != -1) {
        int val = seg.getmin(choosen[now], choosen[now]+1);
        //cerr << "now: " << now << " " << choosen[now] << " " << val << endl;
        int tmp = score - choosen[now];
        seg.update(choosen[now], choosen[now]+1, tmp);
        val = seg.getmin(choosen[now], choosen[now]+1);
        //cerr << val << endl;
        val += choosen[now];
        chmin(score, val);
    }
    if(l[now] <= r[now]) {
        //cerr << now << " " << l[now] << " " << r[now] << " "<< score - l[now] + 1 << endl;
        seg.update(l[now], r[now]+1, score - l[now] + 1);
    }
    for(auto tmp : node[now]) {
        dfs(tmp.second, score + 1);
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int p;
        char c;
        cin >> p >> c;
        node[p].push_back({c, i});
    }
    for(int i = 0; i <= N; i++) {
        sort(node[i].begin(), node[i].end());
        choosen[i] = -1;
        l[i] = 1e9;
        r[i] = -1e9;
    }
    ll k;
    cin >> k;
    ans.resize(k);
    query.resize(k);
    for(int i = 0; i < k; i++) {
        cin >> query[i];
        choosen[query[i]] = i;
    }
    dfs2(0);
    for(int i = 0; i < k; i++) {
        //cerr << p[i] << " ";
    }
    //cerr << endl;
    for(int i = 0; i <= N; i++) {
        //cerr << i << " " << l[i] << " " << r[i] << endl;
    }
    dfs(0, 0);
    for(int i = 0; i < k; i++) {
        ans[p[i]] = seg.getmin(i, i + 1) + i;
        //cout << seg.getmin(p[i], p[i]+1) + i << " ";
    }
    for(int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
    ///dfs(0, 0, -1);
    for(int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}