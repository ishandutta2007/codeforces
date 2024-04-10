#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    set<char> good = {'T', 'i', 'm', 'u', 'r'};
    while (T--){
        int N; cin >> N;
        string s; cin >> s;
        set<char> cur;
        for (char c : s) cur.insert(c);
        cout << (cur == good && N == 5 ? "YES" : "NO") << '\n';
    }
}