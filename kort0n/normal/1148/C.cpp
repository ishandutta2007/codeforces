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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n;
int p[300500];
int inv[300500];
vector<i_i> ans;

int main() {
    //cout.precision(10);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        inv[p[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        /*
        cerr << "----" << i << "----" << endl;
        for(int i = 1; i <= n; i++) {
            cerr << p[i] << " ";
        }
        cerr << endl;
        for(int i = 1; i <= n; i++) {
            cerr << inv[i] << " ";
        }
        cerr << endl;
        */
        if(p[i] == i) continue;
        if(abs(i - inv[i]) >= n / 2) {
            ans.emplace_back(i, inv[i]);
            int index = inv[i];
            swap(inv[i], inv[p[i]]);
            swap(p[i], p[index]);
            continue;
        }
        if(i >= n / 2 + 1) {
            int tmp = 1;
            int index = inv[i];
            ans.emplace_back(i, 1);
            ans.emplace_back(index, 1);
            ans.emplace_back(i, 1);
            swap(inv[i], inv[p[i]]);
            swap(p[i], p[index]);
            continue;
        }
        if(inv[i] <= n / 2) {
            int index = inv[i];
            ans.emplace_back(i, n);
            ans.emplace_back(index, n);
            ans.emplace_back(i, n);
            swap(inv[i], inv[p[i]]);
            swap(p[i], p[index]);
            continue;
        } else {
            int index = inv[i];
            ans.emplace_back(i, n);
            ans.emplace_back(inv[i], 1);
            ans.emplace_back(1, n);
            ans.emplace_back(inv[i], 1);
            ans.emplace_back(i, n);
            swap(inv[i], inv[p[i]]);
            swap(p[i], p[index]);
        }
        /*
        if(inv[i] - i >= n / 2) {
            ans.emplace_back(i, inv[i]);
            int index = inv[i];
            swap(inv[i], inv[p[i]]);
            swap(p[i], p[index]);
            continue;
        }
        int tmp = 1;
        */
    }
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    /*
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    */
    return 0;
}