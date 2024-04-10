#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int maxn = 2e5 + 88;

lol n, m;
lol arr[maxn];
lol tree[maxn << 1];

void build(){
	for(int i = m; i < (m << 1); ++i){
		tree[i] = arr[i - m + 1];
	}

	for(int i = m - 1; i > 0; --i){
		tree[i] = max(tree[i << 1], tree[(i << 1) + 1]);
	}
}

lol get(int l, int r){
    --l; --r;
    l += m; r += m;

    lol res = INT_MIN;

    while(l <= r){
        if(l & 1) res = max(res, tree[l++]);
        if(!(r & 1)) res = max(res, tree[r--]);

        l /= 2;
        r /= 2;
    }

    return res;
}

void solve(){
    lol xs, ys, xf, yf, k;
    cin >> xs >> ys >> xf >> yf >> k;

    if(abs(xf - xs) % k || abs(yf - ys) % k){
        cout << "NO\n";
        return;
    }

    lol maxx = get(min(ys, yf), max(ys, yf));
    if(maxx < xs){
        cout << "YES\n";
        return;
    }

    lol num = (maxx - xs) / k;
    ++num;
    num = k * num;

    cout << (num + xs > n ? "NO\n" : "YES\n");
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) cin >> arr[i];

    int t;
    cin >> t;
    build();

    while(t--)
        solve();
}