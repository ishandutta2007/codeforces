#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
using namespace std;
int arr[505];
int grid[505][505];
bool valid(int x, int y) {
    if(min(x, y) < 1) return false;
    return grid[x][y] == -1;
}
void solve() {
    int n; cin >> n;
    memset(grid, -1, sizeof grid);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        grid[i][i] = arr[i];
    }
    int x = 0, y = 0, rem;
    for(int i = 1; i <= n; i++) {
        x = y = i;
        rem = arr[i] - 1;
        while(rem--) {
            if(valid(x, y - 1)) {
                y--;
                grid[x][y] = arr[i];
            }
            else {
                x++;
                grid[x][y] = arr[i];
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    //cin >> t;
    
    while(t--) solve();
    return 0;
}