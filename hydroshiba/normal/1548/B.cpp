#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int maxn = 2e5 + 6;
const int maxl = 18;
const int inf = INT_MAX / 2;

template <typename T>
struct rmq{
    int size;
    vector<int> loga;
    vector<vector<T>> _rmq;

    rmq(vector<T> &arr){
        size = arr.size();
        loga.resize(size + 1);
        for(int i = 2; i <= size; ++i) loga[i] = loga[i / 2] + 1;

        _rmq.resize(loga[size] + 1);
        for(vector<lol> &vec : _rmq) vec.resize(size);

        _rmq[0] = arr;
        for(int i = 1; i <= loga[size]; ++i)
        for(int j = 0; j < size; ++j){
            _rmq[i][j] = _rmq[i - 1][j];
            if(j + (1 << (i - 1)) < size) _rmq[i][j] = __gcd(_rmq[i][j], _rmq[i - 1][j + (1 << (i - 1))]);
        }
    }

    T gcd(int l, int r){
        int d = loga[r - l + 1];
        return __gcd(_rmq[d][l], _rmq[d][r - (1 << d) + 1]);
    }
};

void solve(){
    int n;
    cin >> n;

    vector<lol> arr(n);
    for(lol &i : arr) cin >> i;

    vector<lol> diff;
    for(int i = 0; i < n - 1; ++i) diff.push_back(llabs(arr[i] - arr[i + 1]));
    for(lol &i : diff) if(!i) i = 1;

    rmq<lol> RMQ(diff);

    int ans = 0;

    for(int step = RMQ.loga[n - 1]; step >= 0; --step){
        int dist = (1 << step);
        if(ans + dist > diff.size()) continue;

        lol maxx = 0;
        for(int i = 0; i + (ans + dist) - 1 < diff.size(); ++i)
            maxx = max(maxx, RMQ.gcd(i, i + (ans + dist) - 1));

        if(maxx != 1) ans += dist;
    }

    cout << ans + 1 << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}