#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

int n;
string s;
int cnt;

void dfs(int x, int sum){
    if(cnt >= n / 2) return;
    if(x == n + 1){
        cout << s << '\n';
        ++cnt;
        return;
    }
    if(sum + 1 <= n - x){
        s += '(';
        dfs(x + 1, sum + 1);
        s.pop_back();
    }
    if(sum > 0){
        s += ')';
        dfs(x + 1, sum - 1);
        s.pop_back();
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n; n *= 2;
        cnt = 0;
        dfs(1, 0);
    }
    return 0;
}