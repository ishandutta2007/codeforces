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
int N, K;
bool Default[600000];
set<int> st[600000];
int cost[600000];
int ans = 0;
bool on[600000];
set<int> inv[600000];
int root[600000];
int find(int x) {
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

bool merge(int a, int b) {
    bool ret = false;
    if(st[a].size() < st[b].size()) {
        swap(a, b);
        ret = true;
    }
    for(auto val : st[b]) {
        inv[val].erase(b);
        if(st[a].count(val)) {
            inv[val].erase(a);
            st[a].erase(val);
        } else {
            st[a].insert(val);
            inv[val].insert(a);
        }
    }
    root[b] = a;
    return ret;
}


void print() {
    return;
    cerr << "--------------" << endl;
    for(int i = 0; i < N; i++) {
        cerr << i;
        for(auto val : inv[i]) {
            cerr << " " << val;
        }
        cerr << endl;
    }
    cerr << "--------------" << endl;
    for(int i = 0; i < N; i++) cerr << Default[i];
    cerr << endl;
    for(int i = 0; i < K; i++) {
        if(find(i) != i) {
            cerr << i << " is a child of " << find(i) << endl;
            for(auto val : st[i]) {
                cerr << val << " ";
            }
            cerr << endl;
            continue;
        }
        {
            cerr << i << " ";
            if(on[i]) cerr << "on ";
            else cerr << "off ";
            cerr << cost[i] << endl;
            for(auto val : st[i]) {
                cerr << val << " ";
            }
        cerr << endl;
        }
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    string dust;
    cin >> dust;
    for(int i = 0; i < N; i++) {
        Default[i] = (dust[i] == '1');
    }
    for(int i = 0; i < K; i++) {
        cost[i] = 1;
        root[i] = i;
        int c;
        cin >> c;
        while(c--) {
            int a;
            cin >> a;
            a--;
            st[i].insert(a);
            inv[a].insert(i);
        }
    }
    for(int i = 0; i < N; i++) {
        if(inv[i].size() == 1) {
            inv[i].insert(K);
            st[K].insert(i);
        }
    }
    cost[K] = 1e8;
    K++;
    for(int i = 0; i < N; i++) {
        //cerr << i << endl;
        /*
        if(inv[i].size() == 0) {
            cout << ans << "\n";
            continue;
        }
        */
        if(inv[i].size() == 1) {
            int idx = find(*inv[i].begin());
            if(!on[idx] ^ Default[i]) {
                if(on[idx]) {
                    on[idx] = false;
                    ans -= cost[idx];
                } else {
                    on[idx] = true;
                    ans += cost[idx];
                }
            }
        } else if(inv[i].size() == 2) {
            auto itr = inv[i].begin();
            int idx1 = *itr;
            itr++;
            int idx2 = *itr;
            //cerr << "idx: " << idx1 << " " << idx2 << endl;
            if(cost[idx1] > cost[idx2]) swap(idx1, idx2);
            if(Default[i] ^ on[idx1] ^ on[idx2]) {
                //cerr << "A" << endl;
                //if(!on[idx1]) {
                    //if(merge(idx2, idx1)) {
                     //   swap(idx1, idx2);
                    //}
                   // cost[idx2] += cost[idx1];
                 //   on[idx2] = false;
               // }
                if(!Default[i]) {
                    //cerr << "A" << endl;
                    if(on[idx1]) {
                        ans -= cost[idx1];
                        on[idx1] = false;
                    }
                    if(on[idx2]) {
                        ans -= cost[idx2];
                        on[idx2] = false;
                    }
                    if(merge(idx2, idx1)) {
                        swap(idx1, idx2);
                    }
                    ans += cost[idx1];
                    cost[idx2] -= cost[idx1];
                    on[idx1] = true;
                    if(cost[idx2] < 0) {
                        ans += cost[idx2];
                        on[idx2] = true;
                    }
                    for(auto val : st[idx1]) {
                        Default[val] ^= true;
                    }
                } else {
                    if(on[idx1]) {
                        on[idx1] = false;
                        ans -= cost[idx1];
                    }
                    if(on[idx2]) {
                        on[idx2] = false;
                        ans -= cost[idx2];
                    }
                    if(merge(idx2, idx1)) swap(idx2, idx1);
                    cost[idx2] += cost[idx1];
                    if(cost[idx2] < 0) {
                        on[idx2] = true;
                        ans += cost[idx2];
                    }
                    /*
                    if(!on[idx1]) {
                        on[idx1] = true;
                        ans += cost[idx1];
                    }
                    if(!on[idx2]) {
                        on[idx2] = true;
                        ans += cost[idx2];
                    }
                    */
                }
                } else if(!Default[i]) {
                if(on[idx1]) {
                    ans -= cost[idx1];
                    on[idx1] = false;
                }
                if(on[idx2]) {
                    ans -= cost[idx2];
                    on[idx2] = false;
                }
                if(merge(idx2, idx1)) {
                    swap(idx1, idx2);
                }
                ans += cost[idx1];
                cost[idx2] -= cost[idx1];
                on[idx1] = true;
                if(cost[idx2] < 0) {
                    ans += cost[idx2];
                    on[idx2] = true;
                }
                //if(!on[idx1]) ans += cost[idx1];
                //if(on[idx2]) ans -= cost[idx2];
                //on[idx1] = true;
                //on[idx2] = false;
                //cost[idx2] -= cost[idx1];
                for(auto val : st[idx1]) {
                    Default[val] ^= true;
                }
            } else {
                /*
                if(!on[idx1]) {
                    on[idx1] = true;
                    ans += cost[idx1];
                }
                if(!on[idx2]) {
                    on[idx2] = true;
                    ans += cost[idx2];
                }
                */
                    if(on[idx1]) {
                        on[idx1] = false;
                        ans -= cost[idx1];
                    }
                    if(on[idx2]) {
                        on[idx2] = false;
                        ans -= cost[idx2];
                    }
                    if(merge(idx2, idx1)) swap(idx2, idx1);
                    cost[idx2] += cost[idx1];
                    if(cost[idx2] < 0) {
                        on[idx2] = true;
                        ans += cost[idx2];
                    }
            }
        }
        print();
        //cout << "ans: " << i << " " << ans << "\n";
        cout << ans << "\n";
    }
    return 0;
}