#include<bits/stdc++.h>
using namespace std;
using LL = long long;
vector<pair<int, int>> ans;
void mer(int L, int R){
    if(L == R) return;
    int M = (L + R) / 2;
    mer(L, M);
    mer(M + 1, R);
    for(int i = L; i <= M; i += 1) ans.push_back({i, M + 1 - L + i});
}
vector<pair<int, int>> vp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int L = 1, m = (1 << 13), s = n; m; m >>= 1)
        if(s >= m){
            s -= m;
            mer(L, L + m - 1);
            vp.push_back({L, L + m - 1});
            L += m;
        }
    if(vp.size() > 2){
        vector<int> v;
        for(int i = vp.back().first; i <= vp.back().second; i += 1)
            v.push_back(i);
        vp.pop_back();
        while(vp.size() >= 2){
            while(v.size() < vp.back().second - vp.back().first + 1){
                int x = v.size();
                for(int i = 0; i < x; i += 1){
                    ans.push_back({v[i], vp[0].first + i});
                    v.push_back(vp[0].first + i);
                }
                vp[0].first += x;
            }
            int x = v.size();
            for(int i = 0; i < x; i += 1){
                ans.push_back({v[i], vp.back().first + i});
                v.push_back(vp.back().first + i);
            }
            vp.pop_back();
        }
    }
    assert(ans.size() <= 500000);
    cout << ans.size() << "\n";
    for(auto [x, y] : ans) cout << x << " " << y << "\n";
    return 0;
}