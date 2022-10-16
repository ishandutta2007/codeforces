#include <bits/stdc++.h>
//#include <atcoder/all>
#define endl "\n"
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
ll H, W;
vector<vector<ll>> a, b;
vector<vector<ll>> A;
vector<ll> B;
vector<ll> ans;
bool breaking[2000][2000];
ll breaknum[2000];

bool used[2000];
ll num[2005];
ll num2[2005];
bool Same(vector<ll> v, vector<ll> v2) {
    for(auto tmp : v) {
        num[tmp]++;
    }
    for(auto tmp : v2) {
        num2[tmp]++;
    }
    bool ret = true;
    if(v.size() != v2.size()) ret = false;
    for(auto tmp : v) {
        if(num[tmp] != num2[tmp]) ret = false;
    }
    for(auto tmp : v) {
        num[tmp]--;
    }
    for(auto tmp : v2) {
        num2[tmp]--;
    }
    return ret;
}

bool IsSorted() {
    vector<ll> C;
    for(auto tmp : A) {
        for(auto val : tmp) {
            C.push_back(val);
        }
    }
    return B == C;
}
vector<vector<ll>> v;

vector<vector<ll>> g(int w, vector<ll> q) {
    stable_sort(q.begin(), q.end(), [&](ll tmp1, ll tmp2) {
        return v[tmp1][w] < v[tmp2][w];
    });
    vector<vector<ll>> ret;
    for(auto tmp : q) {
        if(ret.empty() or v[ret.back().back()][w] != v[tmp][w]) ret.push_back({});
        ret.back().push_back(tmp);
    }
    return ret;
}

void f(int w) {
    vector<vector<ll>> NewA;
    ll before = 0;
    for(auto q : A) {
        auto Q = g(w, q);
        for(int i = 0; i < Q.size(); i++) {
            NewA.push_back(Q[i]);
            if(i >= 1) {
                for(int w = 0; w < W; w++) {
                    //cerr << "check: " << before-1 << " " << w << endl;
                    if(breaking[before-1][w]) {
                        breaknum[w]--;
                    }
                }
            }
            before += Q[i].size();
        }
    }
    A = NewA;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    a.resize(H), b.resize(H);
    for(int h = 0; h < H; h++) {
        a[h].resize(W);
        for(int w = 0; w < W; w++) {
            cin >> a[h][w];
        }
        v.push_back(a[h]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    A.resize(1);
    B.resize(H);
    A.back().resize(H);
    for(int h = 0; h < H; h++) {
        auto itr = lower_bound(v.begin(), v.end(), a[h]);
        A[0][h] = itr - v.begin();
    }
    for(int h = 0; h < H; h++) {
        b[h].resize(W);
        for(int w = 0; w < W; w++) {
            cin >> b[h][w];
        }
        auto itr = lower_bound(v.begin(), v.end(), b[h]);
        if(itr == v.end() or *itr != b[h]) {
            cout << -1 << endl;
            return 0;
        }
        B[h] = itr - v.begin();
    }
    /*
    for(auto tmp : A) cerr << tmp << " ";
    cerr << endl;
    for(auto tmp : B) cerr << tmp << " ";
    cerr << endl;
    */
    for(int w = 0; w < W; w++) {
        for(int h = 0; h + 1 < H; h++) {
            ll idx = B[h];
            ll idx2 = B[h+1];
            if(v[idx][w] > v[idx2][w]) {
                breaking[h][w] = true;
                breaknum[w]++;
            }
        }
    }
    /*
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            cerr << breaking[h][w] << " ";
        }
        cerr << endl;
    }
    */
    while(!IsSorted()) {
        int ope = -1;
        for(int w = 0; w < W; w++) {
            if(used[w]) continue;
            if(breaknum[w] == 0) {
                ope = w;
                break;
            }
        }
        /*
        for(auto tmp : A) {
            cerr << "{";
            for(auto val : tmp) {
                cerr << val << " ";
            }
            cerr << "}" << endl;
        }
        for(auto tmp : B) {
            cerr << tmp << " ";
        }
        cerr <<endl;
        cerr << "ope: " << ope << endl;
        */
        if(ope == -1) {
            cout << -1 << endl;
            //assert(false);
            return 0;
        }
        used[ope] = true;
        f(ope);
        ans.push_back(ope);
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i] + 1;
    }
    cout << endl;
    /*
    for(auto w : ans) {
        stable_sort(a.begin(), a.end(), [&](vector<ll> z, vector<ll> x) {
            return z[w] < x[w];
        });
    }
    assert(a == b);
    */
    return 0;
}