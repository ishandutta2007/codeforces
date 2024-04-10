#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr) cin >> i;

    vector<int> num(n);

    for(int i = 0; i < n; ++i){
        int temp = (i ? num[i - 1] : 0);
        bool flag = 0;

        for(int j = 0; j <= temp; ++j) if(arr[i] % (i + 2 - j)){
            flag = 1;
            break;
        }

        if(!flag){
            cout << "NO\n";
            return;
        }

        num[i] = temp + 1;
    }

    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}