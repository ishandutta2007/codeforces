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
    int n;
    cin >> n;
    vi am(n, 0);
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        ++am[v];
        ++am[u];
    }
    for(int i = 0; i < n; i++) {
        if(am[i] == 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}