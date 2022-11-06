#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        string s; cin >> s;
        int N = s.size();
        for (char &c : s) c -= 'a';
        if (s[0] > s[N-1]){
            for (char &c : s){
                c = 26 - c - 1;
            }
        }
        vector<vector<int>> idx(26);
        int i = 0;
        for (char c : s){
            idx[c].push_back(++i);
        }
        vector<int> ans;
        for (int i = s[0]; i <= s[N-1]; ++i){
            for (int x : idx[i])
                ans.push_back(x);
        }
        cout << s[N-1] - s[0] << " " << ans.size() << '\n';
        for (int x : ans) cout << x << " ";
        cout << '\n';
    }
}