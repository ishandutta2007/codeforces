#include "bits/stdc++.h"
using namespace std;

void rev(vector<int> &vec, string &s){
    int l = 0, r = vec.size() - 1;
    while(l <= r){
        swap(s[vec[l]], s[vec[r]]);
        ++l;
        --r;
    }
}

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int pos = n - 1;
    int ans = 0;

    vector<vector<int>> res;

    while(true){
        bool flag = 1;
        for(int i = 0; i < n - 1; ++i){
            flag &= s[i] <= s[i + 1];
        }

        if(flag) break;

        vector<int> num0(n + 1), num1(n + 1), vec;

        for(int i = 1; i <= n; ++i){
            num0[i] = num0[i - 1];
            num1[i] = num1[i - 1];

            if(s[i - 1] == '0') ++num0[i];
            else ++num1[i];
        }

        int pos = 0, minn = INT_MAX / 2;
        for(int i = 1; i <= n; ++i){
            if(abs(num1[i] - num0[n] + num0[i]) < minn){
                minn = abs(num1[i] - num0[n] + num0[i]);
                pos = i;
            }
        }

        for(int i = 0; i < pos; ++i) if(s[i] == '1') vec.push_back(i);
        for(int i = pos; i < n; ++i) if(s[i] == '0') vec.push_back(i);

        rev(vec, s);

        ++ans;
        res.push_back(vec);
    }

    cout << ans << '\n';
    for(auto i : res){
        cout << i.size() << ' ';
        for(auto j : i) cout << j + 1 << ' ';
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}