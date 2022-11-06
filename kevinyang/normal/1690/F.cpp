#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        string s; cin >> s;
        for (char &c : s) c -= 'a';
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
            a[i]--;
        }
        ll ans = 1;
        vector<bool> vis(N);
        for (int i = 0; i < N; ++i){
            if (vis[i]) continue;
            int cnt = 0, v = i;
            vector<int> loop;
            while (true){
                v = a[v];
                loop.push_back(v);
                vis[v] = 1;
                if (v == i) break;
            }
            vector<int> mp(loop.size()+1);
            for (int v : loop){
                int ov = v;
                int cnt = 0;
                while (true){
                    v = a[v];
                    cnt++;
                    if (s[v] == s[ov]) mp[cnt]++;
                    if (v == ov) break;
                }
            }
            for (int a = 1; a <= loop.size(); ++a){
                int b = mp[a];
                if (b == loop.size()){
                    ans = lcm(ans, a);
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}