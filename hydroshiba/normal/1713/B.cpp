#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

int operations(vector<int>& arr){
    if(!arr.size()) return 0;
    int res = arr[0];

    for(int i = 1; i < arr.size(); ++i) res += max(arr[i] - arr[i - 1], 0);
    return res;
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr) cin >> i;

    auto it = unique(arr.begin(), arr.end());
    arr.resize(it - arr.begin());
    n = arr.size();
    
    vector<int> s = arr;
    sort(s.begin(), s.end());

    map<int, vector<int>> pos;
    vector<bool> check(n);

    for(int i = 0; i < n; ++i){
        pos[arr[i]].push_back(i);
    }

    for(int val : s){
        for(int i : pos[val]) check[i] = true;

        for(int i : pos[val]){
            bool left = (i ? check[i - 1] : true);
            bool right = (i + 1 < n ? check[i + 1] : true);

            if(left || right) continue;
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL));
    //compare();

    int t;
    cin >> t;

    while(t--) solve();
}