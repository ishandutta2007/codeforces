#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
int mat[maxn + 1], vis[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    cout << n + m + n * m - 1 << "\n";
    for(int i = 0; i < n; i += 1) cout << 'U';
    for(int i = 0; i < m; i += 1) cout << 'L';
    int x = 1, y = 1;
    for(int i = 1; i < n * m; i += 1)
        if(x & 1){
            if(y == m){
                cout << 'D';
                x += 1;
            }
            else{
                cout << 'R';
                y += 1;
            }
        }
        else{
            if(y == 1){
                cout << 'D';
                x += 1;
            }
            else{
                cout << 'L';
                y -= 1;
            }
        }
    return 0;
}