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
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int can = (n - 1) / 2 + 1;
        if(can < k) {
            cout << -1 << '\n';
            continue;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j || i % 2 == 1 || k == 0) {
                    cout << '.';
                } else {
                    --k;
                    cout << 'R';
                }
            }
            cout << '\n';
        }
    }
}