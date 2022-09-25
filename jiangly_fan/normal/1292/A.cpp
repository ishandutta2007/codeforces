#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
bool ban[2][maxn];
set<pair<int, int>> s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= q; i += 1){
        int r, c;
        cin >> r >> c;
        r -= 1;
        ban[r][c] ^= 1;
        if(ban[r][c]){
            for(int x = c - 1; x <= c + 1; x += 1)
                if(ban[r ^ 1][x])
                    s.insert(r ? make_pair(x, maxn + c) : make_pair(c, maxn + x));
        }
        else{
            for(int x = c - 1; x <= c + 1; x += 1)
                    s.erase(r ? make_pair(x, maxn + c) : make_pair(c, maxn + x));
        }
        cout << (s.empty() ? "Yes\n" : "No\n");
    }
    return 0;
}