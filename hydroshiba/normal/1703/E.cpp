#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int maxn = 100;

int n;
int arr[maxn][maxn], pass[maxn][maxn];

ii ninety(ii cur){
    return ii(n - cur.y - 1, cur.x);
}

void solve(){
    cin >> n;

    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;

        for(int j = 0; j < n; ++j){
            if(s[j] == '0') arr[i][j] = 0;
            else arr[i][j] = 1;
            pass[i][j] = 0;
        }
    }

    int ans = 0;

    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j) if(!pass[i][j]){
        vector<int> num(2);
        ++num[arr[i][j]];
        pass[i][j] = 1;

        int a = ninety(ii(i, j)).x;
        int b = ninety(ii(i, j)).y;
        ++num[arr[a][b]];
        pass[a][b] = 1;

        ii cur = ii(a, b);
        a = ninety(cur).x;
        b = ninety(cur).y;
        ++num[arr[a][b]];
        pass[a][b] = 1;

        cur = ii(a, b);
        a = ninety(cur).x;
        b = ninety(cur).y;
        ++num[arr[a][b]];
        pass[a][b] = 1;

        ans += min(num[0], num[1]);
    }

    cout << ans << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}