#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int inf = INT_MAX / 2;

bool comp(int a, int b){
    return (__builtin_ctz(a) > __builtin_ctz(b));
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    int z = 0;

    for(int &i : arr){
        cin >> i;
        z += __builtin_ctz(i);
    }

    if(z >= n){
        cout << "0\n";
        return;
    }

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1);
    sort(perm.begin(), perm.end(), comp);

    int ans = 0;

    for(int i : perm){
        z += __builtin_ctz(i);
        ++ans;

        if(z >= n){
            cout << ans << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}