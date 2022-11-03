#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<char> ans(n, 1);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    for(int j = 0; j < m; ++j){
        int sum = 0, cnt = 0;
        for(int i = 0; i < n; ++i){
            if(s[i][j] == '1'){
                ++cnt, sum += i;
            }
        }
        if(cnt == 1){
            ans[sum] = 0;
        }
    }
    for(int i = 0; i < n; ++i){
        if(ans[i]){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;


}