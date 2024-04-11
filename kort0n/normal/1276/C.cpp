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
ll N;
ll anscolumn;
ll ansrow;
vector<ll> v;
map<ll, ll> mp;
vector<vector<int>> ans;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        mp[a]++;
    }
    for(auto val : mp) {
        v.push_back(val.second);
    }
    ll num = 0;
    sort(v.begin(), v.end());
    for(int c = 1; c * c <= N; c++) {
        auto itr = lower_bound(v.begin(), v.end(), c);
        num += distance(itr, v.end());
        //cerr << c << " " << distance(itr, v.end()) << " " << num << endl;
        int r = num / c;
        if(r < c) continue;
        if(anscolumn * ansrow < c * r) {
            anscolumn = c;
            ansrow = r;
        }
    }
    cout << anscolumn * ansrow << endl;
    cout << ansrow << " " << anscolumn << endl;
    int H = ansrow;
    int W = anscolumn;
    ans.resize(ansrow);
    for(int h = 0; h < ansrow; h++) ans[h].resize(anscolumn);
    int index = 0;
    vector<i_i> V;
    for(auto val : mp) {
        l_l tmp = val;
        swap(tmp.first, tmp.second);
        chmin(tmp.first, anscolumn);
        V.push_back(tmp);
    }
    sort(V.begin(), V.end(), greater<i_i>());
    index = 0;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            while(V[index].first == 0) index++;
            ans[(w+h)%H][w] = V[index].second;
            V[index].first--;
        }
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            cout << ans[h][w] << " ";
        }
        cout << endl;
    }
    return 0;
}