#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for(cin >> T; T; T -= 1){
        int n, m, cnt[2]{};
        cin >> n >> m;
        for(int i = 0; i < n; i += 1){
            string s;
            cin >> s;
            for(int j = 0; j < m; j += 1)
                if(s[j] != '.') cnt[((s[j] == 'R') ^ i ^ j) & 1] += 1;
        }
        if(cnt[0] and cnt[1]) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < n; i += 1){
            for(int j = 0; j < m; j += 1)
                cout << "RW"[(i ^ j ^ (cnt[0] != 0)) & 1];
                cout << "\n";
        }
    }
    return 0;
}