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
ll a[1050];
vector<string> ans, trueans;
vector<vector<int>> Prev, Next;

void f(int item) {
    int idx1 = 0;
    int idx2 = 1;
    Next.clear();
    for(auto v : Prev) {
        if(v.size() <= 1) continue;
        idx1 = v[0];
        idx2 = v[1];
    }
    ans[idx1][item] = '1'; 
    ans[idx2][item] = '0'; 
    ll one = a[item] - 1;
    for(int i = 0; i <= N; i++) {
        if(i == idx2 or i == idx1) continue;
        if(one) {
            one--;
            ans[i][item] = '1';
        } else {
            ans[i][item] = '0';
        }
    }
    for(auto v : Prev) {
        vector<int> u[2];
        for(auto tmp : v) {
            if(ans[tmp][item] == '0') u[0].push_back(tmp);
            else u[1].push_back(tmp);
        }
        for(int i = 0; i < 2; i++) {
            if(u[i].size()) Next.push_back(u[i]);
        }
    }
    swap(Prev, Next);
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    ans.resize(N + 1, string(N, '0'));
    Prev.push_back({});
    for(int i = 0; i <= N; i++) {
        Prev[0].push_back(i);
    }
    for(int i = 0; i < N; i++) f(i);
    for(auto v : Prev) {
        assert(v.size() == 1);
    }
    for(auto s : ans) {
        if(s != string(N, '0')) trueans.push_back(s);
    }
    cout << trueans.size() << endl;
    for(auto s : trueans) {
        cout << s << endl;
    }
    return 0;
}