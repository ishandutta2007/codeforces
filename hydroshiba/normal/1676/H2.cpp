#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int maxn = 2e5 + 88;

struct fenwick{
    vector<int> tree;

    fenwick(){
        tree.resize(2e5 + 88);
    }

    void inc(int pos){
        while(pos < maxn){
            ++tree[pos];
            pos += pos & -pos;
        }
    }

    int sum(int pos){
        int res = 0;
        while(pos > 0){
            res += tree[pos];
            pos -= pos & -pos;
        }
        return res;
    }
};

void brute(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr) cin >> i;

    long long ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i; ++j) ans += (arr[j] >= arr[i]);
    }

    cout << ans << '\n';
}

void solve(){
    int n;
    cin >> n;


    int maxval = INT_MIN;

    vector<int> arr(n);
    for(int &i : arr) cin >> i, maxval = max(maxval, i);

    fenwick F;
    long long ans = 0;

    for(int i = 0; i < n; ++i){
		int val = arr[i];

		ans += (long long)F.sum(maxval) - (long long)F.sum(val - 1);
		F.inc(val);
	}

	cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}