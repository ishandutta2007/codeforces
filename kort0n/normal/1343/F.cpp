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

const long long INF = 1e18;
//const ll mod = 1000000007;
set<ll> st[205];
set<ll> inv[205];
set<ll> stnow[205];
set<ll> invnow[205];
int N;

void print(vector<int> v) {
    //cerr << "----------begin----------" << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] + 1 << " ";
    }
    cout << endl;
    //cerr << "-----------end--------" << endl;
}

vector<int> ans;
set<int> candidate[205];

void f() {
    int l = 0;
    int idx = N - 1 - ans.size();
    for(int i = 0; i < N; i++) {
        if(inv[i].size() == 1 and candidate[idx].find(i) != candidate[idx].end()) l = i;
    }
    for(; ;) {
        ans.push_back(l);
        //cerr << i << " " << l << endl;
        if(ans.size() == N) break;
        ll nxt;
        for(auto idx : inv[l]) {
            st[idx].erase(l);
            if(st[idx].size() == 1) {
                nxt = *st[idx].begin();
            }
        }
        l = nxt;
    }
}

bool can(int idx, int r) {
    while(true) {
        //cerr << "can: " << idx << " " << r << endl;
        idx--;
        if(idx < 0) return true;
        ll nxt = -1;
        if(invnow[r].size() != 1) {
            //cerr << "A" << " " << r << " " << invnow[r].size() << endl;
            //for(auto tmp : invnow[r]) cerr << tmp << " ";
            //cerr << endl;
            return false;
        }
        for(auto idx : invnow[r]) {
            stnow[idx].erase(r);
            if(stnow[idx].size() >= 2) {
                //cerr << "B" << endl;
                return true;
            }
            if(stnow[idx].size() == 1) {
                nxt = *stnow[idx].begin();
            }
        }
        int stidx = *invnow[r].begin();
        for(auto val : stnow[stidx]) {
            invnow[val].erase(stidx);
        }
        r = nxt;
        if(r == -1) {
            //cerr << "C" << endl;
            return false;
        }
    }
    //cerr << "D" << endl;
    return true;
}

void g() {
    //print(ans);
    if(ans.size() == N) {
        reverse(ans.begin(), ans.end());
        print(ans);
        return;
    }
    bool All2 = true;
    for(int i = 0; i < N - 1; i++) {
        if(st[i].size() != 0 and st[i].size() != 2) All2 = false;
    }
    if(All2) {
        f();
        reverse(ans.begin(), ans.end());
        print(ans);
        return;
    }
    int idx = N - 1 - ans.size();
    int r = -1;
    for(auto tmp : candidate[idx]) {
        if(inv[tmp].size() != 1 and idx >= 1) continue;
        //cerr << "tmp: " << tmp << endl;
        for(int i = 0; i <= N; i++) {
            stnow[i].clear();
            invnow[i].clear();
            stnow[i] = st[i];
            invnow[i] = inv[i];
        }
        //cerr << inv[5].size() << " " << invnow[5].size() << endl;
        if(can(idx, tmp)) {
            r = tmp;
        }
    }
    assert(r != -1);
    idx = *inv[r].begin();
    int num = st[idx].size();
    for(int i = 0; i < num; i++) {
        int nowidx = N - 1 - ans.size() - i;
        if(nowidx < 0) continue;
        set<int> tmp;
        set_intersection(candidate[nowidx].begin(), candidate[nowidx].end(), st[idx].begin(), st[idx].end(), inserter(tmp, tmp.end()));
        swap(tmp, candidate[nowidx]);
    }
    ans.push_back(r);
    //cerr << "idx: " << idx << endl;
    for(int i = 0; i <= N; i++) {
        candidate[i].erase(r);
    }
    for(auto tmp : inv[r]) {
        st[tmp].erase(r);
    }
    for(auto val : st[idx]) {
        //cerr << "erase: " << val << " " << idx << endl;
        inv[val].erase(idx);
    }
    //cerr << "test: " << inv[5].size() << endl;
    g();
}

void solve() {
    ans.clear();
    cin >> N;
    for(int i = 0; i <= N; i++) {
        st[i].clear();
        inv[i].clear();
        candidate[i].clear();
        for(int j = 0; j < N; j++) {
            candidate[i].insert(j);
        }
    }
    for(int i = 0; i < N - 1; i++) {
        ll k;
        cin >> k;
        while(k--) {
            ll a;
            cin >> a;
            a--;
            st[i].insert(a);
            inv[a].insert(i);
        }
    }
    //for(auto tmp : inv[5]) cerr << tmp << " ";
    //cerr << endl;
    g();
}

int main() {
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}