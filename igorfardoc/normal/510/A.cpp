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
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < m; j++) {
                cout << '#';
            }
            cout << '\n';
        } else {
            if(i % 4 == 3) {
                cout << '#';
            }
            for(int j = 0; j < m - 1; j++) {
                cout << '.';
            }
            if(i % 4 == 1) {
                cout << '#';
            }
            cout << '\n';
        }
    }
}