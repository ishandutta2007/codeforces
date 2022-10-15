#define x firsts
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int inf = INT_MAX / 2;

vector<int> coprime[1001];

void prepare(){
    for(int i = 1; i <= 1000; ++i){
        for(int j = 1; j <= 1000; ++j) if(__gcd(i, j) == 1) coprime[i].push_back(j);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;

    vector<lol> arr, num;

    for(int i = 0; i < n; ++i){
        lol val; cin >> val;
        if(!arr.size() || val > arr[arr.size() - 1])
            arr.push_back(val), num.push_back(val);
        else num[num.size() - 1] += val;
    }

    vector<lol> pre(num.size());
    partial_sum(num.begin(), num.end(), pre.begin());

    while(q--){
        lol k;
        cin >> k;

        auto it = upper_bound(arr.begin(), arr.end(), k);

        if(it == arr.begin()) cout << "0 ";
        else if(it == arr.end()) cout << pre[pre.size() - 1] << ' ';
        else{
            --it;

            int pos = it - arr.begin();
            cout << pre[pos] << ' ';
        }
    }

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    prepare();

    int t;
    cin >> t;

    while(t--)
        solve();
}