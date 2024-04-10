#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        string s1, s2; cin >> s1 >> s2;
        for (char &c : s1){
            if (c == 'G') c = 'B';
        }
        for (char &c : s2){
            if (c == 'G') c = 'B';
        }
        cout << (s1 == s2 ? "YES" : "NO") << '\n';
    }
}