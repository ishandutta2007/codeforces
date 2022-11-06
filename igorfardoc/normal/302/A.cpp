#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    int am1 = 0;
    int am0 = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a == 1) {
            ++am1;
        } else {
            ++am0;
        }
    }
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if(len % 2 == 0 && len / 2 <= am1 && len / 2 <= am0) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}