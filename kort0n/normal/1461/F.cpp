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
ll N;
ll A[105000];
char ans[105000];
void print() {
    cout << A[0];
    for(int i = 1; i < N; i++) {
        if(ans[i-1] == '.') {
            for(int j = 0; j <= 2e9; j++) {
                cout << "A" << endl;
            }
        }
        //assert(ans[i-1] != '.');
        cout << ans[i-1] << A[i];
    }
    cout << endl;
}
void trivial(char tmp) {
    for(int i = 0; i <= N; i++) ans[i] = tmp;
    print();
    exit(0);
}
void annoy() {
    for(int i = 0; i < N; i++) ans[i] = '*';
    for(int i = 0; i < N; i++) {
        if(A[i+1] == 0) {
            ans[i] = '-';
            break;
        }
    }
    print();
}

vector<ll> v;
vector<ll> ones;
vector<ll> from;
vector<ll> dp;

void g(ll l, ll r) {
    //cerr << "g: " << l << " " << r << endl;
    for(int i = l; i < r; i++) {
        if(1 <= A[i] and A[i] <= 9) continue;
        assert(0);
    }
    if(r <= l + 1) return;
    for(int i = l; i + 1 < r; i++) {
        ans[i] = '+';
    }
    v.clear();
    ones.clear();
    from.clear();
    ll nowone = 0;
    for(int i = l; i < r; i++) {
        if(A[i] == 1) nowone++;
        else {
            v.push_back(i);
            ones.push_back(nowone);
            nowone = 0;
            from.push_back(i);
        }
    }
    assert(nowone == 0);
    if(v.size() >= 19) {
        for(int i = l; i + 1 < r; i++) {
            ans[i] = '*';
        }
        return;
    }
    assert(v.size() >= 1);
    for(auto tmp : v) {
        assert(A[tmp] >= 2 and A[tmp] <= 9);
    }
    dp.clear();
    dp.resize(v.size() + 1, -INF);
    dp[0] = 0;
    for(int i = 0; i < (int)v.size(); i++) {
        ll prod = 1;
        for(int j = i; j >= 0; j--) {
            assert(2 <= A[v[j]] and A[v[j]] <= 9);
            prod *= A[v[j]];
            if(chmax(dp[i+1], dp[j] + ones[j] + prod)) {
                from[i] = j;
            }
            assert(dp[i+1] >= 0);
        }
    }
    /*
    cerr << "---v---" << endl;
    for(auto tmp : v) cerr << tmp << " ";
    cerr << endl;
    cerr << "---ones---" << endl;
    for(auto tmp : ones) cerr << tmp << " ";
    cerr << endl;
    cerr << "---from---" << endl;
    for(auto tmp : from) cerr << tmp << " ";
    cerr << endl;
    cerr << "---dp---" << endl;
    for(auto tmp : dp) cerr << tmp << " ";
    cerr << endl;
    */
    ll now = v.size() - 1;
    while(now >= 0) {
        for(int i = v[from[now]]; i + 1 <= v[now]; i++) {
            ans[i] = '*';
        }
        now = from[now] - 1;
    }
}

void f(ll l, ll r) {
    while(r > l + 1) {
        //cerr << "f: " << l << " " << r << endl;
        if(A[l] == 1) {
            ans[l] = '+';
            l++;
        } else if(A[r-1] == 1) {
            //cerr << r - 2 << endl;
            ans[r-2] = '+';
            r--;
        } else break;
    }
    g(l, r);
}

void solve() {
    ll Last = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == 0) {
            if(i) ans[i-1] = '+';
            ans[i] = '+';
            f(Last, i);
            Last = i + 1;
        }
    }
    f(Last, N);
    print();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        ans[i] = '.';
    }
    string T;
    cin >> T;
    sort(T.begin(), T.end());
    if(T.size() == 1) trivial(T[0]);
    if(T == "*+-" or T == "*+") solve();
    else if(T == "+-") trivial('+');
    else {
        assert(T == "*-");
        annoy();
    } 
    return 0;
}