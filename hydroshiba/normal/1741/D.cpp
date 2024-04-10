#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int inf = INT_MAX / 2;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr) cin >> i;

    int ans = 0;
    int lg = __builtin_ctz(n);

    vector<int> vec = arr;

    for(int j = 1; j <= lg; ++j){
        vector<int> temp;

        for(int i = 0; i < vec.size(); i += 2){
            if(abs(vec[i] - vec[i + 1]) > (1 << (j - 1))){
                cout << "-1\n";
                return;
            }

            if(vec[i] > vec[i + 1]) ++ans;
            temp.push_back(min(vec[i], vec[i + 1]));
        }

        vec = temp;
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}