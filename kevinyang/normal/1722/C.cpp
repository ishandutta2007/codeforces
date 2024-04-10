#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<vector<string>> a(3);
        map<string, int> cnt;
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < N; ++j){
                string s; cin >> s;
                a[i].push_back(s);
                cnt[s]++;
            }
        }
        map<int, int> mp = {{3, 0}, {2, 1}, {1, 3}};
        vector<int> score(3);
        for (int i = 0; i < 3; ++i){
            for (string s : a[i]){
                score[i] += mp[cnt[s]];
            }
            cout << score[i] << " ";
        }
        cout << '\n';
    }
}